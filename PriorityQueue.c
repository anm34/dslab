#include <stdio.h>

#define SIZE 5

typedef struct
{
    int element;
    int prioity;
} PriorityQueue;

PriorityQueue PQ[SIZE];
int F = -1, R = -1;
void insertPQ(int, int);
void display(void);
int get_highest_prioity(void);
void delete_highest_prioity(void);

int main()
{
    int ch, item, priority, max;
    printf("1. Insert an element.\n");
    printf("2. Get highest prioity element\n");
    printf("3. Delete highest prioity element.\n");
    printf("4. Display elements.\n");
    printf("5. Exit.\n");
    printf("Enter a choice (1/2/3/4/5) : ");
    do
    {
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            printf("Enter its prioity : ");
            scanf("%d", &priority);
            insertPQ(item, priority);
            break;
        case 2:
            max = get_highest_prioity();
            printf("Highest prioity item is : %d\n", max);
            break;
        case 3:
            delete_highest_prioity();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice!");
        }
        printf("Enter a choice (1/2/3/4/5) : ");
    } while (ch != 5);
    
    return 0;
}
void insertPQ(int item, int priority)
{
    if (R >= SIZE - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (F == -1 && R == -1)
        {
            F = 0;
        }
        R++;
        PQ[R].element = item;
        PQ[R].prioity = priority;
    }
}
int get_highest_prioity(void)
{
    int maxprioity = 0, maxitem, i;
    for (i = F; i <= R; i++)
    {
        if (PQ[i].prioity > maxprioity)
        {
            maxprioity = PQ[i].prioity;
            maxitem = PQ[i].element;
        }
    }
    return maxitem;
}
void delete_highest_prioity(void)
{
    int m, i, j;
    m = get_highest_prioity();
    printf("Removing highest priority element %d\n", m);
    if (R == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = F; PQ[i].element != m; i++)
            ;
        for (j = i; j < R; j++)
        {
            PQ[j].element = PQ[j + 1].element;
            PQ[j].prioity = PQ[j + 1].prioity;
        }
        R--;
    }
}
void display(void)
{
    int i;
    if (R == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = F; i <= R; i++)
        {
            printf("Element : %d\tprioity :%d\n",PQ[i].element,PQ[i].prioity);
        }
    }
}