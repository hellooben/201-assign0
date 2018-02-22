#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
    {
    srandom(1005);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    int i;
    for (i = 0; i < 15; ++i)
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
    printf("value at 9 is %d\n",getINTEGER(getSLL(p,9)));
    printf("setting value at 9 to 93\n");
    freeINTEGER(setSLL(p,9,newINTEGER(93)));
    printf("value at 9 now is %d\n",getINTEGER(getSLL(p,9)));
    freeSLL(p);
    return 0;
    }
