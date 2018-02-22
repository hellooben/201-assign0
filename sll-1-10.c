#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
    {
    srandom(1011);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    int i;
    for (i = 0; i < 1000000; ++i)
        {
        int j = random() % 100;
        insertSLL(p,0,newINTEGER(j));
        }
    if (sizeSLL(p) < 100)
        {
        displaySLL(p,stdout);
        printf("\n");
        }
    printf("size is %d\n",sizeSLL(p));
    printf("value at 142838 is %d\n",getINTEGER(getSLL(p,142838)));
    printf("setting value at 142838 to 99\n");
    freeINTEGER(setSLL(p,142838,newINTEGER(99)));
    printf("value at 142838 now is %d\n",getINTEGER(getSLL(p,142838)));
    freeSLL(p);
    return 0;
    }
