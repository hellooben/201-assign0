#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
    {
    srandom(1010);
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
    printf("value at 979551 is %d\n",getINTEGER(getSLL(p,979551)));
    printf("setting value at 979551 to 76\n");
    freeINTEGER(setSLL(p,979551,newINTEGER(76)));
    printf("value at 979551 now is %d\n",getINTEGER(getSLL(p,979551)));
    freeSLL(p);
    return 0;
    }
