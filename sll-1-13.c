#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
    {
    srandom(1014);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    SLL *q = newSLL(displayINTEGER,freeINTEGER);
    unionSLL(p,q);
    /* do some inserts */
    int i;
    for (i = 0; i < 1000000; ++i)
        {
        int j = random() % 100;
        insertSLL(p,0,newINTEGER(j));
        }
    /* do some inserts */
    for (i = 0; i < 1000000; ++i)
        {
        int j = random() % 100;
        insertSLL(q,0,newINTEGER(j));
        }
    /* now a bunch of unions */
    printf("starting 1000000 unions\n");
    for (i = 0; i < 1000000; ++i)
        {
        unionSLL(q,p);
        unionSLL(p,q);
        }
    /* do some inserts */
    for (i = 0; i < 145; ++i)
        {
        int j = random() % 100;
        insertSLL(p,0,newINTEGER(j));
        j = random() % 100;
        insertSLL(q,0,newINTEGER(j));
        }
    if (sizeSLL(p) < 200)
        {
        printf("p: ");
        displaySLL(p,stdout);
        printf("\n");
        printf("p (debug): ");
        displaySLLdebug(p,stdout);
        printf("\n");
        printf("\n");
        }
    if (sizeSLL(q) < 200)
        {
        printf("q: ");
        displaySLL(q,stdout);
        printf("\n");
        printf("q (debug): ");
        displaySLLdebug(q,stdout);
        printf("\n");
        printf("\n");
        }
    printf("size of p is %d\n",sizeSLL(p));
    printf("size of q is %d\n",sizeSLL(q));
    printf("value at 109409 is %d\n",getINTEGER(getSLL(p,109409)));
    printf("setting value at 109409 to 23\n");
    freeINTEGER(setSLL(p,109409,newINTEGER(23)));
    printf("value at 109409 now is %d\n",getINTEGER(getSLL(p,109409)));
    freeSLL(p);
    freeSLL(q);
    return 0;
    }
