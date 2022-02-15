#include <stdio.h>

#define SIZE 5

int CQ[SIZE], F = -1, R = -1;
void ENQUEUE();
void DQUEUE(void);
void DISPLAYQ(void);

int main()
{
    int ch;
    int n;

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
            DQUEUE();
            break;
        case 3:
            DISPLAYQ();
            break;
        case 4:
            break;
        default:
            printf("Invalid Option!\n");
            break;
        }
        printf("Enter an option (1/2/3/4) : ");
    } while (ch != 4);
    return 0;
}

void ENQUEUE()
{
    int next, item;

    printf("Enter the element to be inserted : ");
    scanf("%d", &item);

    if (F == -1)
    {
        F = 0;
        R = 0;
        CQ[R] = item;
    }
    else
    {
        next = (R + 1) % SIZE;
        if (next != F && next != SIZE)
        {
            R = next;
            CQ[R] = item;
        }
        else
        {
            printf("Queue is full\n");
        }
    }
}

void DQUEUE(void)
{
    int item;
    if (F == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = CQ[F];
        if (F == R)
        {
            F = -1;
            R = -1;
        }
        else
        {
            F = (F + 1) % SIZE;
        }
        printf("The deleted item is : %d\n", item);
    }
}

void DISPLAYQ(void)
{
    int i;
    if (F == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("FRONT : %d\n", F);
        printf("REAR : %d\n", R);
        printf("Elements : ");
        for (i = F; i != R; i = (i + 1) % SIZE)
        {
            printf("%d ", CQ[i]);
        }
        printf("%d\n", CQ[R]);
    }
}