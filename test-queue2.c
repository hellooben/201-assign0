#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "integer.h"

static void showItems(QUEUE *items)
    {
    printf("The items are ");
    displayQUEUE(items,stdout);
    printf(".\n");
    printf("The items (debugged) are ");
    displayQUEUEdebug(items,stdout);
    printf(".\n");
    }

int main(void)
    {
    QUEUE *items = newQUEUE(displayINTEGER,freeINTEGER);
    showItems(items);
    enqueue(items,newINTEGER(3));                   //insert at front
    enqueue(items,newINTEGER(2));      //insert at back
    enqueue(items,newINTEGER(1));                   //insert at middle
    showItems(items);
    printf("The value ");
    INTEGER *i = dequeue(items);                   //remove from front
    displayINTEGER(i,stdout);
    printf(" was removed.\n");
    freeINTEGER(i);
    showItems(items);
    int x = getINTEGER((INTEGER *) peekQUEUE(items));    //get the first item
    printf("The first item is %d.\n",x);
    printf("Freeing the list.\n");
    freeQUEUE(items);
    return 0;
    }
