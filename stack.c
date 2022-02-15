#include <stdio.h>

int STACK[101];
int TOP=-1, size;

void push(int);
int pop();
void display();

int main()
{
    int choice, item, i;
    
    printf("Enter the size of the stack: ");
    scanf(" %d", &size);

    do
    {
    printf("Enter a stack operation: \n");
    printf("1.Display\n2.push()\n3.pop()\n4.Exit\n:");
    scanf(" %d", &choice);

    switch(choice)
    {
        case 1:
                display();
                break;
        case 2:
                printf("Enter element to enter: ");
                scanf(" %d", &item);
                push(item);
                break;
        case 3:
                item=pop();
                printf("poped %d\n", item);
                break;
        case 4:
                printf("Exiting the program\n");
                break;
        default:
                printf("Invalid choice\n");
    }
    }
    while(choice != 4);
    return 0;
}

void push(int item)
{
    if(TOP>=size)
        printf("Stack overflow\n");
    else
    {
        TOP++;
        STACK[TOP]=item;
    }
}

int pop()
{
    if(TOP<0)
        printf("Stack is empty\n");
    else
    {
        int item = STACK[TOP];
        TOP--;
        return item;
    }
}


void display()
{
    int i;
    if(TOP<0)
        printf("Stack is empty\n");
    else
        printf("\nStack elements are: ");
        for(i=0; i<=TOP; i++)
            printf(" %d", STACK[i]);
        printf("\n\n");
    
}