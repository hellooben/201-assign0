#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "real.h"

extern void srandom(unsigned int);
extern long int random(void);

int
main(void)
    {
    srandom(1007);
    SLL *p = newSLL(displayREAL,freeREAL);
    int i;
    for (i = 0; i < 36; ++i)
        {
        int j = random() % 100;
        int k = random() % (sizeSLL(p) + 1);
        j += (random() % 100) / 100.0;
        insertSLL(p,k,newREAL(j));
        }
    insertSLL(p,0,newREAL(56.56));
    insertSLL(p,31,newREAL(44.44));
    insertSLL(p,18,newREAL(68.68));
    freeREAL(removeSLL(p,4));
    insertSLL(p,31,newREAL(45.45));
    freeREAL(removeSLL(p,25));
    freeREAL(removeSLL(p,20));
    insertSLL(p,0,newREAL(72.72));
    insertSLL(p,15,newREAL(95.95));
    freeREAL(removeSLL(p,38));
    freeREAL(removeSLL(p,15));
    insertSLL(p,35,newREAL(33.33));
    insertSLL(p,12,newREAL(41.41));
    insertSLL(p,32,newREAL(86.86));
    insertSLL(p,13,newREAL(6.6));
    insertSLL(p,5,newREAL(40.40));
    freeREAL(removeSLL(p,4));
    freeREAL(removeSLL(p,28));
    freeREAL(removeSLL(p,0));
    freeREAL(removeSLL(p,38));
    insertSLL(p,2,newREAL(15.15));
    freeREAL(removeSLL(p,18));
    freeREAL(removeSLL(p,9));
    insertSLL(p,25,newREAL(62.62));
    freeREAL(removeSLL(p,6));
    freeREAL(removeSLL(p,28));
    insertSLL(p,22,newREAL(73.73));
    freeREAL(removeSLL(p,5));
    freeREAL(removeSLL(p,25));
    insertSLL(p,31,newREAL(50.50));
    insertSLL(p,13,newREAL(69.69));
    insertSLL(p,37,newREAL(22.22));
    insertSLL(p,35,newREAL(43.43));
    freeREAL(removeSLL(p,12));
    insertSLL(p,17,newREAL(64.64));
    insertSLL(p,27,newREAL(26.26));
    if (sizeSLL(p) < 100)
        {
        displaySLL(p,stdout);
        printf("\n");
        }
    printf("size is %d\n",sizeSLL(p));
    printf("value at 12 is %.2lf\n",getREAL(getSLL(p,12)));
    printf("setting value at 12 to 45.73\n");
    freeREAL(setSLL(p,12,newREAL(45.73)));
    printf("value at 12 now is %.2lf\n",getREAL(getSLL(p,12)));
    freeSLL(p);
    return 0;
    }
