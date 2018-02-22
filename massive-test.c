#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"

extern void srandom(unsigned int);
extern long int random(void);
void disp(void *i,FILE *fp) { fprintf(fp,"%d",*(int *)i); }

int values[] = { 1, 2, 3, 4, 5 };

extern void sllTEST0() {
    srandom(1);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    insertSLL(p,0,newINTEGER(3));
    insertSLL(p,sizeSLL(p),newINTEGER(2));
    displaySLL(p,stdout);
    printf("\n");
    freeINTEGER(removeSLL(p,1));
    displaySLL(p,stdout);
    printf("\n");
    freeINTEGER(removeSLL(p,0));
    displaySLL(p,stdout);
    printf("\n");
    SLL *q = newSLL(displayINTEGER,freeINTEGER);
    insertSLL(p,0,newINTEGER(6));
    insertSLL(p,0,newINTEGER(7));
    insertSLL(q,0,newINTEGER(4));
    insertSLL(q,0,newINTEGER(5));
    displaySLL(p,stdout);
    printf("\n");
    displaySLL(q,stdout);
    printf("\n");
    unionSLL(p,q);
    displaySLL(p,stdout);
    displaySLL(q,stdout);
    printf("\n");
    displaySLLdebug(p,stdout);
    printf("\n");
    displaySLLdebug(q,stdout);
    printf("\n");
    freeSLL(p);
    freeSLL(q);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST1() {
    srandom(2);
    SLL *p = newSLL(displayREAL,freeREAL);
    insertSLL(p,0,newREAL(3.3));
    insertSLL(p,sizeSLL(p),newREAL(2.2));
    displaySLL(p,stdout);
    printf("\n");
    freeREAL(removeSLL(p,1));
    displaySLL(p,stdout);
    printf("\n");
    freeREAL(removeSLL(p,0));
    displaySLL(p,stdout);
    printf("\n");
    SLL *q = newSLL(displayREAL,freeREAL);
    insertSLL(p,0,newREAL(6.7));
    insertSLL(p,0,newREAL(8.9));
    insertSLL(q,0,newREAL(4.3));
    insertSLL(q,0,newREAL(5.2));
    displaySLL(p,stdout);
    printf("\n");
    displaySLL(q,stdout);
    printf("\n");
    unionSLL(p,q);
    displaySLL(p,stdout);
    displaySLL(q,stdout);
    printf("\n");
    displaySLLdebug(p,stdout);
    printf("\n");
    displaySLLdebug(q,stdout);
    printf("\n");
    freeSLL(p);
    freeSLL(q);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST2() {
    srandom(3);
    SLL *p = newSLL(displaySTRING,freeSTRING);
    insertSLL(p,0,newSTRING("a"));
    insertSLL(p,sizeSLL(p),newSTRING("b"));
    displaySLL(p,stdout);
    printf("\n");
    freeSTRING(removeSLL(p,1));
    displaySLL(p,stdout);
    printf("\n");
    freeSTRING(removeSLL(p,0));
    displaySLL(p,stdout);
    printf("\n");
    SLL *q = newSLL(displaySTRING,freeSTRING);
    insertSLL(p,0,newSTRING("e"));
    insertSLL(p,0,newSTRING("f"));
    insertSLL(q,0,newSTRING("c"));
    insertSLL(q,0,newSTRING("d"));
    displaySLL(p,stdout);
    printf("\n");
    displaySLL(q,stdout);
    printf("\n");
    unionSLL(p,q);
    displaySLL(p,stdout);
    displaySLL(q,stdout);
    printf("\n");
    displaySLLdebug(p,stdout);
    printf("\n");
    displaySLLdebug(q,stdout);
    printf("\n");
    freeSLL(p);
    freeSLL(q);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST3() {
    srandom(4);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    int i;
    for (i = 0; i < 11; ++i)
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
    printf("setting value at 9 to 74\n");
    freeINTEGER(setSLL(p,9,newINTEGER(74)));
    printf("value at 9 now is %d\n",getINTEGER(getSLL(p,9)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST4() {
    srandom(5);
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
    printf("value at 5 is %d\n",getINTEGER(getSLL(p,5)));
    printf("setting value at 5 to 10\n");
    freeINTEGER(setSLL(p,5,newINTEGER(10)));
    printf("value at 5 now is %d\n",getINTEGER(getSLL(p,5)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST5() {
    srandom(6);
    SLL *p = newSLL(displayREAL,freeREAL);
    int i;
    for (i = 0; i < 11; ++i)
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
    printf("value at 6 is %.2lf\n",getREAL(getSLL(p,6)));
    printf("setting value at 6 to 12.65\n");
    freeREAL(setSLL(p,6,newREAL(12.65)));
    printf("value at 6 now is %.2lf\n",getREAL(getSLL(p,6)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST6() {
    srandom(7);
    SLL *p = newSLL(displayREAL,freeREAL);
    int i;
    for (i = 0; i < 37; ++i)
        {
        int j = random() % 100;
        int k = random() % (sizeSLL(p) + 1);
        j += (random() % 100) / 100.0;
        insertSLL(p,k,newREAL(j));
        }
    freeREAL(removeSLL(p,12));
    freeREAL(removeSLL(p,29));
    freeREAL(removeSLL(p,31));
    freeREAL(removeSLL(p,10));
    freeREAL(removeSLL(p,29));
    freeREAL(removeSLL(p,3));
    insertSLL(p,9,newREAL(20.20));
    insertSLL(p,32,newREAL(70.70));
    insertSLL(p,28,newREAL(63.63));
    insertSLL(p,14,newREAL(49.49));
    insertSLL(p,1,newREAL(92.92));
    freeREAL(removeSLL(p,14));
    freeREAL(removeSLL(p,34));
    insertSLL(p,2,newREAL(6.6));
    freeREAL(removeSLL(p,32));
    insertSLL(p,23,newREAL(8.8));
    freeREAL(removeSLL(p,5));
    freeREAL(removeSLL(p,16));
    insertSLL(p,3,newREAL(0.0));
    freeREAL(removeSLL(p,23));
    insertSLL(p,1,newREAL(1.1));
    insertSLL(p,11,newREAL(5.5));
    freeREAL(removeSLL(p,12));
    insertSLL(p,10,newREAL(95.95));
    insertSLL(p,9,newREAL(29.29));
    insertSLL(p,34,newREAL(87.87));
    insertSLL(p,29,newREAL(83.83));
    freeREAL(removeSLL(p,29));
    freeREAL(removeSLL(p,2));
    freeREAL(removeSLL(p,17));
    freeREAL(removeSLL(p,11));
    insertSLL(p,20,newREAL(51.51));
    insertSLL(p,3,newREAL(4.4));
    insertSLL(p,3,newREAL(9.9));
    insertSLL(p,34,newREAL(27.27));
    insertSLL(p,6,newREAL(75.75));
    freeREAL(removeSLL(p,31));
    if (sizeSLL(p) < 100)
        {
        displaySLL(p,stdout);
        printf("\n");
        }
    printf("size is %d\n",sizeSLL(p));
    printf("value at 26 is %.2lf\n",getREAL(getSLL(p,26)));
    printf("setting value at 26 to 97.10\n");
    freeREAL(setSLL(p,26,newREAL(97.10)));
    printf("value at 26 now is %.2lf\n",getREAL(getSLL(p,26)));
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST7() {
    srandom(8);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    SLL *q = newSLL(displayINTEGER,freeINTEGER);
    unionSLL(p,q);
    /* do some inserts */
    int i;
    for (i = 0; i < 36; ++i)
        {
        int j = random() % 100;
        insertSLL(p,0,newINTEGER(j));
        }
    /* do some inserts */
    for (i = 0; i < 36; ++i)
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
    for (i = 0; i < 144; ++i)
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
    printf("value at 30 is %d\n",getINTEGER(getSLL(p,30)));
    printf("setting value at 30 to 49\n");
    freeINTEGER(setSLL(p,30,newINTEGER(49)));
    printf("value at 30 now is %d\n",getINTEGER(getSLL(p,30)));
    freeSLL(p);
    freeSLL(q);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST8() {
    srandom(9);
    SLL *p = newSLL(disp,0);
    unsigned int i;
    /* inserting pointers to int, not INTEGERS */
    for (i = 0; i < sizeof(values)/sizeof(int); ++i)
        insertSLL(p,0,values+i);
    displaySLL(p,stdout);
    printf("\n");
    freeSLL(p);
    printf("-----------\n");
    return;
}
extern void sllTEST9() {
    srandom(10);
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
    printf("value at 69295 is %d\n",getINTEGER(getSLL(p,69295)));
    printf("setting value at 69295 to 8\n");
    freeINTEGER(setSLL(p,69295,newINTEGER(8)));
    printf("value at 69295 now is %d\n",getINTEGER(getSLL(p,69295)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST10() {
    srandom(11);
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
    printf("value at 311423 is %d\n",getINTEGER(getSLL(p,311423)));
    printf("setting value at 311423 to 94\n");
    freeINTEGER(setSLL(p,311423,newINTEGER(94)));
    printf("value at 311423 now is %d\n",getINTEGER(getSLL(p,311423)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST11() {
    srandom(12);
    SLL *p = newSLL(displayREAL,freeREAL);
    int i;
    for (i = 0; i < 10000; ++i)
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
    printf("value at 3760 is %.2lf\n",getREAL(getSLL(p,3760)));
    printf("setting value at 3760 to 14.94\n");
    freeREAL(setSLL(p,3760,newREAL(14.94)));
    printf("value at 3760 now is %.2lf\n",getREAL(getSLL(p,3760)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST13() {
    srandom(14);
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
    for (i = 0; i < 183; ++i)
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
    printf("value at 464452 is %d\n",getINTEGER(getSLL(p,464452)));
    printf("setting value at 464452 to 51\n");
    freeINTEGER(setSLL(p,464452,newINTEGER(51)));
    printf("value at 464452 now is %d\n",getINTEGER(getSLL(p,464452)));
    freeSLL(p);
    freeSLL(q);
    printf("--------------------------------------------\n");
    return;
}
extern void sllTEST14() {
    srandom(15);
    SLL *p = newSLL(displayINTEGER,freeINTEGER);
    /* do some inserts */
    int i;
    for (i = 0; i < 1000000; ++i)
        {
        int j = random() % 100;
        insertSLL(p,0,newINTEGER(j));
        }
    /* now a bunch of gets and sets */
    printf("starting 1000000 get and sets\n");
    int size = sizeSLL(p);
    for (i = 0; i < 1000000; ++i)
        {
        INTEGER *x = getSLL(p,size-1);
        setINTEGER(x,random() % 100);
        (void) setSLL(p,size-1,x);
        }
    if (sizeSLL(p) < 100)
        {
        printf("p: ");
        displaySLL(p,stdout);
        printf("\n");
        printf("p (debug): ");
        displaySLLdebug(p,stdout);
        printf("\n");
        printf("\n");
        }
    printf("size of p is %d\n",sizeSLL(p));
    printf("the last value is %d\n",getINTEGER(getSLL(p,size-1)));
    freeSLL(p);
    printf("--------------------------------------------\n");
    return;
}
extern void dllTEST() {
    srandom(1);
    DLL *p = newDLL(displayINTEGER,freeINTEGER);
    insertDLL(p,0,newINTEGER(3));
    insertDLL(p,sizeDLL(p),newINTEGER(2));
    displayDLL(p,stdout);
    printf("\n");
    freeINTEGER(removeDLL(p,1));
    displayDLL(p,stdout);
    printf("\n");
    freeINTEGER(removeDLL(p,0));
    displayDLL(p,stdout);
    printf("\n");
    DLL *q = newDLL(displayINTEGER,freeINTEGER);
    insertDLL(p,0,newINTEGER(6));
    insertDLL(p,0,newINTEGER(7));
    insertDLL(q,0,newINTEGER(4));
    insertDLL(q,0,newINTEGER(5));
    displayDLL(p,stdout);
    printf("\n");
    displayDLL(q,stdout);
    printf("\n");
    unionDLL(p,q);
    displayDLL(p,stdout);
    displayDLL(q,stdout);
    printf("\n");
    displayDLLdebug(p,stdout);
    printf("\n");
    displayDLLdebug(q,stdout);
    printf("\n");
    freeDLL(p);
    freeDLL(q);
    return;
}
extern void stackTEST() {
    srandom(1);
    STACK *p = newSTACK(displayINTEGER,freeINTEGER);
    push(p,newINTEGER(3));
    push(p,newINTEGER(4));
    push(p,newINTEGER(2));
    displaySTACK(p,stdout);
    printf("\n");
    void *value = pop(p);
    displayINTEGER(value,stdout);
    printf("\n");
    freeINTEGER(value);
    displaySTACK(p,stdout);
    printf("\n");
    displaySTACKdebug(p,stdout);
    printf("\n");
    value = pop(p);
    displayINTEGER(value,stdout);
    printf("\n");
    freeINTEGER(value);
    displaySTACK(p,stdout);
    printf("\n");
    displaySTACKdebug(p,stdout);
    printf("\n");
    freeINTEGER(pop(p));
    displaySTACK(p,stdout);
    printf("\n");
    displaySTACKdebug(p,stdout);
    printf("\n");
    freeSTACK(p);
    return;
}
extern void queueTEST() {
    srandom(1);
    QUEUE *p = newQUEUE(displayINTEGER,freeINTEGER);
    enqueue(p,newINTEGER(3));
    enqueue(p,newINTEGER(4));
    enqueue(p,newINTEGER(2));
    displayQUEUE(p,stdout);
    printf("\n");
    void *value = dequeue(p);
    displayINTEGER(value,stdout);
    printf("\n");
    freeINTEGER(value);
    displayQUEUE(p,stdout);
    printf("\n");
    displayQUEUEdebug(p,stdout);
    printf("\n");
    value = dequeue(p);
    displayINTEGER(value,stdout);
    printf("\n");
    freeINTEGER(value);
    displayQUEUE(p,stdout);
    printf("\n");
    displayQUEUEdebug(p,stdout);
    printf("\n");
    freeINTEGER(dequeue(p));
    displayQUEUE(p,stdout);
    printf("\n");
    displayQUEUEdebug(p,stdout);
    printf("\n");
    freeQUEUE(p);
    return;
}

int
main(void) {
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ SLL TESTS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    sllTEST0();
    sllTEST1();
    sllTEST2();
    sllTEST3();
    sllTEST4();
    sllTEST5();
    sllTEST6();
    sllTEST7();
    sllTEST8();
    sllTEST9();
    sllTEST10();
    sllTEST11();
    sllTEST13();
    sllTEST14();
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ DLL TESTS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    dllTEST();
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ STACK TESTS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    stackTEST();
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ QUEUE TESTS $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    queueTEST();
    return 0;
}
