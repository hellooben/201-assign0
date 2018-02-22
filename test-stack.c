#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"


int main(void) {
    STACK *items = newSTACK(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        push(items, newINTEGER(i));
    }
    displaySTACK(items, stdout);
    printf("\nSize: %d\n", sizeSTACK(items));
    printf("\n");

    for (int i=5; i>0; i--) {
        push(items, newINTEGER(i+10));
        displaySTACK(items, stdout);
        printf("\n");
    }
    displaySTACK(items, stdout);
    printf("\nSize: %d\n", sizeSTACK(items));
    printf("\n");

    INTEGER *i = pop(items);
    displayINTEGER(i, stdout);
    printf("\n");
    displaySTACK(items, stdout);
    printf("\nSize: %d\n", sizeSTACK(items));
    printf("\n");
    i = pop(items);
    displayINTEGER(i, stdout);
    printf("\n");
    displaySTACK(items, stdout);
    printf("\nSize: %d\n", sizeSTACK(items));
    printf("\n");
    displaySTACKdebug(items, stdout);
    printf("\n");
    freeSTACK(items);
    printf("freed!\n");





    return 0;
}
