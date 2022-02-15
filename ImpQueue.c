#include <stdio.h>
#define SIZE 5
int Q[SIZE], FRONT = -1, REAR = -1;

void ENQUEUE(void)
{
    int item;
    if (REAR > SIZE - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        printf("Enter the number to be inserted : ");
        scanf("%d", &item);
        if (FRONT == -1 && REAR == -1)
        {
            FRONT = 0;
        }
        REAR++;
        Q[REAR] = item;
    }
}

void DEQUEUE(void)
{
    int item;
    if (FRONT == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        item = Q[FRONT];
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            FRONT++;
        }
        printf("The deleted element is : %d\n", item);
    }
}
void Display(void)
{
    int i;
    if (FRONT == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("The Queue elements are : ");
        for (i = FRONT; i <= REAR; i++)
        {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    printf("1. Enter an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the elements\n");
    printf("4. Exit\n");
    printf("Enter an option (1/2/3/4) : ");
    do
    {
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            ENQUEUE();
            break;
        case 2:
            DEQUEUE();
            break;
        case 3:
            Display();
            break;
        case 4:
            break;
        default:
            printf("Invalid option try again\n");
            break;
        }

        printf("Enter an option: (1/2/3/4) : ");
    } while (ch != 4);
    return 0;
}