#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "integer.h"


int main(void) {
    DLL *items = newDLL(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        insertDLL(items, i, newINTEGER(i));
    }
    displayDLL(items, stdout);
    printf("\nSize: %d\n", sizeDLL(items));
    printf("\n");

    for (int i=5; i>0; i--) {
        insertDLL(items, i, newINTEGER(i+10));
        displayDLL(items, stdout);
        printf("\n");
    }
    displayDLL(items, stdout);
    printf("\nSize: %d\n", sizeDLL(items));
    printf("\n");

    INTEGER *i = removeDLL(items,0);
    displayINTEGER(i, stdout);
    printf("\n");
    displayDLL(items, stdout);
    printf("\nSize: %d\n", sizeDLL(items));
    printf("\n");
    i = removeDLL(items, sizeDLL(items)-1);
    displayINTEGER(i, stdout);
    printf("\n");
    displayDLL(items, stdout);
    printf("\nSize: %d\n", sizeDLL(items));
    printf("\n");


    DLL *stuff = newDLL(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        insertDLL(stuff, i, newINTEGER(i));
    }
    DLL *stuff2 = newDLL(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        insertDLL(stuff2, i, newINTEGER(i+10));
    }
    unionDLL(stuff, stuff2);
    displayDLL(stuff, stdout);
    printf("\n");
    displayDLL(stuff2, stdout);
    printf("\n");


    i = getDLL(stuff, 0);
    displayINTEGER(i, stdout);
    printf("\n");
    i = getDLL(stuff, 9);
    displayINTEGER(i, stdout);
    printf("\n");
    i = getDLL(stuff, 4);
    displayINTEGER(i, stdout);
    printf("\n");



    return 0;
}
