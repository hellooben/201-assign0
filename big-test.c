#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"

int
main(void) {

    DLL *single = newDLL(displayINTEGER, freeINTEGER);
    displayDLL(single, stdout);
    printf("\n");
    for (int i=0; i<10; i++) {
        insertDLL(single, 0, newINTEGER(i));
        displayDLL(single, stdout);
        printf("\n");
    }
    for (int i=0; i<10; i++) {
        insertDLL(single, sizeDLL(single), newINTEGER(i+10));
        displayDLLdebug(single, stdout);
        printf("\n");
    }
    for (int i=0; i<10; i++) {
        insertDLL(single, sizeDLL(single)/2, newINTEGER(i+100));
        displayDLL(single, stdout);
        printf("\n");
    }
    for (int i=0; i<10; i++) {
        removeDLL(single, sizeDLL(single)-1);
        displayDLLdebug(single, stdout);
        printf("\n");
    }
    for (int i=0; i<10; i++) {
        removeDLL(single, 0);
        displayDLL(single, stdout);
        printf("\n");
    }
    for (int i=0; i<10; i++) {
        removeDLL(single, sizeDLL(single)/2);
        displayDLLdebug(single, stdout);
        printf("\n");
    }
    freeDLL(single);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    STACK *cakes = newSTACK(displayINTEGER, freeINTEGER);
    displaySTACK(cakes, stdout);
    printf("\n");
    printf("%d\n", sizeSTACK(cakes));
    for (int i=0; i<100000; i++) {
        push(cakes, newINTEGER(i));
    }
    for (int i=0; i<99990; i++) {
        pop(cakes);
    }

    displaySTACK(cakes, stdout);
    printf("\n");

    return 0;
}
