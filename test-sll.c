#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"


int main(void) {
    SLL *items = newSLL(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        insertSLL(items, i, newINTEGER(i));
    }
    displaySLL(items, stdout);
    printf("\nSize: %d\n", sizeSLL(items));
    printf("\n");

    for (int i=5; i>0; i--) {
        insertSLL(items, i, newINTEGER(i+10));
        displaySLL(items, stdout);
        printf("\n");
    }
    displaySLL(items, stdout);
    printf("\nSize: %d\n", sizeSLL(items));
    printf("\n");

    INTEGER *i = removeSLL(items,0);
    displayINTEGER(i, stdout);
    printf("\n");
    displaySLL(items, stdout);
    printf("\nSize: %d\n", sizeSLL(items));
    printf("\n");
    i = removeSLL(items, sizeSLL(items)-1);
    displayINTEGER(i, stdout);
    printf("\n");
    displaySLL(items, stdout);
    printf("\nSize: %d\n", sizeSLL(items));
    printf("\n");

    SLL *stuff = newSLL(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        insertSLL(stuff, i, newINTEGER(i));
    }
    SLL *stuff2 = newSLL(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        insertSLL(stuff2, i, newINTEGER(i+10));
    }
    unionSLL(stuff, stuff2);
    displaySLLdebug(stuff, stdout);
    printf("\n");
    displaySLL(stuff2, stdout);
    printf("\n");
    i = getSLL(stuff, 0);
    displayINTEGER(i, stdout);
    printf("\n");
    i = getSLL(stuff, 9);
    displayINTEGER(i, stdout);
    printf("\n");
    i = getSLL(stuff, 4);
    displayINTEGER(i, stdout);
    printf("\n");



    return 0;
}
