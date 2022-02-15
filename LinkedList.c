#include <stdio.h>
#include <stdlib.h>

typedef struct node1 
{
    int data;
    struct node1 *link;
} node;

node* HEADER;

void traverse();
void create(int);

int main()
{
    int size;
    printf("Enter the number of elements of the linked list: ");
    scanf(" %d", &size);

    create(size);
    traverse(); 
}

void create(int size)
{
    int i, num;
    node* ptr;
    node* temp;
    
    HEADER = (node*) malloc(sizeof(node));
    HEADER->data = 0;
    HEADER->link = NULL;
    ptr = HEADER;

    // entering elements into the linked list
    printf("Enter %d elements into the linked list: ", size);

    for(i=0; i<size; i++)
    {
        temp = (node*) malloc(sizeof(node));
        scanf(" %d", &num);
        temp->data = num;
        temp->link = NULL;
        ptr->link = temp;
        ptr = ptr->link;
    } 
}

void traverse()
{
    int i;
    node* ptr = HEADER->link;
    printf("The linked list elements are: ");

    while(ptr!=NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}