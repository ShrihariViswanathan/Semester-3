#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
void creation(int m)
{
    if (m < 0)
    {
        printf("INVALID INPUT\n");
        return;
    }
    int a;
    struct node *newnode;
    for (int i = 0; i < m; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &a);
        newnode->data = a;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
        }
        tail = newnode;
    }
}
void insert_at_begining(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = x;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insert_at_end(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = x;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void delete_by_value(int p)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    for (int i = 1; temp->data != p && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("VVALUE NOT FOUND\n");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("DELETED ELEMENT IS %d\n", temp->data);
    free(temp);
}
void delete_by_position(int q)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    for (int i = 1; i < q && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("VVALUE NOT FOUND\n");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    printf("DELETED ELEMENT IS %d\n", temp->data);
    free(temp);
}
void display()
{
    struct node *temp = head;
    printf("THE ELEMENTS OF LIST ARE: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n, ch, val;
    while (1)
    {
        printf("\nENTER THE OPERATION TO BE PERFORMED:\n1.CREATE DOUBLY LINKED LIST\n2.INSERT AT BEGINING\n3.INSERT AT END\n4.DELETE BY VALUE\n5.DISPLAY\n6.DELETE BY POSITION\n7.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("ENTER THE NUMBER OF NODES TO BE CREATED: ");
            scanf("%d", &n);
            creation(n);
            break;
        case 2:
            printf("ENTER THE VALUE TO BE INSERTED AT BEGINING: ");
            scanf("%d", &val);
            insert_at_begining(val);
            break;
        case 3:
            printf("ENTER THE VALUE TO BE INSERTED AT END: ");
            scanf("%d", &val);
            insert_at_end(val);
            break;
        case 4:
            printf("ENTER THE VALUE TO BE DELETED: ");
            scanf("%d", &val);
            delete_by_value(val);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("ENTER THE POSITION TO BE DELETED: ");
            scanf("%d", &val);
            delete_by_position(val);
            break;

        case 7:
            exit(0);

        default:
            printf("INVALID INPUT\n");
        }
    }
    return 0;
}
