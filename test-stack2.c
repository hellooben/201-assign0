#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"

static void showItems(STACK *items)
    {
    printf("The items are ");
    displaySTACK(items,stdout);
    printf(".\n");
    printf("The items (debugged) are ");
    displaySTACKdebug(items,stdout);
    printf(".\n");
    }

int main(void)
    {
    STACK *items = newSTACK(displayINTEGER,freeINTEGER);
    showItems(items);
    push(items,newINTEGER(3));                   //insert at front
    push(items,newINTEGER(2));      //insert at back
    push(items,newINTEGER(1));                   //insert at middle
    showItems(items);
    printf("The value ");
    INTEGER *i = pop(items);                   //remove from front
    displayINTEGER(i,stdout);
    printf(" was removed.\n");
    freeINTEGER(i);
    showItems(items);
    int x = getINTEGER((INTEGER *) peekSTACK(items));    //get the first item
    printf("The first item is %d.\n",x);
    printf("Freeing the list.\n");
    freeSTACK(items);
    return 0;
    }
