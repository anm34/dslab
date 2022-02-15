#include <stdio.h>

#define SIZE 5

int QUEUE[SIZE], FRONT = -1, REAR = -1;

void ENQUQUE(void)
{
    int item;

    if(REAR > SIZE-1)
        printf("Queues is full!\n");
    else
    {
        printf("Enter the item to insert: ");
        scanf(" %d", &item);

        if(FRONT==-1 && REAR==-1)
            FRONT = 0;

        REAR++;
        QUEUE[REAR] = item;
    }
}

void DEQUEUE(void)
{
    int item;

    if(FRONT == -1)
        printf("Queue is empty!\n");
    else
    {
        item = QUEUE[FRONT];
        if(FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else   
            FRONT++;
        printf("The item %d is deleted", item);
    }
}


int main() 
{
    
    return 0;
}