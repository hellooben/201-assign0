#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "real.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
    {
    srandom(1006);
    SLL *p = newSLL(displayREAL,freeREAL);
    int i;
    for (i = 0; i < 18; ++i)
        {
        int j = random() % 100;
        int k = random() % (sizeSLL(p) + 1);
        j += (random() % 100) / 100.0;
        insertSLL(p,k,newREAL(j));
        }
    if (sizeSLL(p) < 100)
        {
        displaySLL(p,stdout);
        printf("\n");
        }
    printf("size is %d\n",sizeSLL(p));
    printf("value at 3 is %.2lf\n",getREAL(getSLL(p,3)));
    printf("setting value at 3 to 85.68\n");
    freeREAL(setSLL(p,3,newREAL(85.68)));
    printf("value at 3 now is %.2lf\n",getREAL(getSLL(p,3)));
    freeSLL(p);
    return 0;
    }
