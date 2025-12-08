#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;
int node_count = 0;

void insert_begin(int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    node_count++;
    printf("Inserted at start\n");
}

void insert_end(int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    node_count++;
    printf("Inserted node at end\n");
}

void insert_at_position(int pos, int data) {
    if (pos < 0 || pos > node_count) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 0) {
        insert_begin(data);
        return;
    }

    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    node *temp = head;
    int count = 0;

    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    node_count++;
    printf("Inserted node at position %d\n", pos + 1); 
}

void display() {
    node *temp = head;
    int pos = 1;

    if (temp == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp != NULL) {
        printf("Position %d: %d\n", pos, temp->data);
        temp = temp->next;
        pos++;
    }
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("Linked List Operations\n");
        printf("1. Insert at begining\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_begin(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_end(data);
                break;

            case 3:
                printf("Enter Position (0 to %d): ", node_count);
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_position(pos, data);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
