#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "integer.h"


int main(void) {
    QUEUE *items = newQUEUE(displayINTEGER, freeINTEGER);
    for (int i=0; i<5; i++) {
        enqueue(items, newINTEGER(i));
    }
    displayQUEUE(items, stdout);
    printf("\nSize: %d\n", sizeQUEUE(items));
    printf("\n");

    for (int i=5; i>0; i--) {
        enqueue(items, newINTEGER(i+10));
        displayQUEUE(items, stdout);
        printf("\n");
    }
    displayQUEUE(items, stdout);
    printf("\nSize: %d\n", sizeQUEUE(items));
    printf("\n");

    INTEGER *i = dequeue(items);
    displayINTEGER(i, stdout);
    printf("\n");
    displayQUEUE(items, stdout);
    printf("\nSize: %d\n", sizeQUEUE(items));
    printf("\n");
    i = dequeue(items);
    displayINTEGER(i, stdout);
    printf("\n");
    displayQUEUE(items, stdout);
    printf("\nSize: %d\n", sizeQUEUE(items));
    printf("\n");
    displayQUEUEdebug(items, stdout);
    printf("\n");
    freeQUEUE(items);
    printf("freed!\n");





    return 0;
}
