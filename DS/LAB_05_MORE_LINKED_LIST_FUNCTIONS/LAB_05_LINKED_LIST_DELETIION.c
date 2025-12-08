#include<stdio.h>
#include <stdlib.h>

int node_count = 0;

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;
    
    if (head == NULL)
        head = newnode;

    return newnode;
}

int insert_node(int data, int pos) {
    node *newnode = create_node(data);
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        printf("Inserted %d at position %d\n", data, pos);
        node_count++;
        return 0;
    }

    if (pos == -1) {
        node *temp = head;
        
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = NULL;

        printf("Inserted %d at end\n", data);
        node_count++;
        return 0;
    }

    if (pos > 1 && pos <= node_count + 1) {
        int count = 1;
        node *temp = head;

        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        printf("Inserted %d at position %d\n", data, pos);
        node_count++;
        return 0;
    }

    else {
        printf("Invalid position\n");
        return -1;
    }
}

void display() {
    int count = 1;
    node *temp = head;
    
    if (head != NULL) {
        while (temp != NULL) {
            printf("P%d: %d\n", count, temp->data);
            temp = temp->next;
            count++;
        }
    } else {
        printf("Linked List is empty\n");
    }
}

int delete(int pos) {
    if (pos == 1) {
        node *temp = head;
        head = head->next;
        printf("Element at START has been deleted. It was %d\n", temp->data);
        node_count--;
        free(temp);
        return 0;
    }

    if (pos == -1) {
        node *temp = head;
        node *prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != NULL)
            prev->next = NULL;

        printf("Element at END has been deleted. It was %d\n", temp->data);
        node_count--;
        free(temp);
        return 0;
    }

    if (pos > 1 && pos <= node_count) {
        int count = 1;
        node *prev = head;
        node *temp = head;

        while (temp != NULL && count < pos) {
            count++;
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        printf("Element at P%d has been deleted. It was %d\n", pos, temp->data);
        node_count--;
        free(temp);
        return 0;
    }
    return -1;
}

void display_options() {
    int choice;
    while(1) {
        printf("\n1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display Linked List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int data, pos;
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", &pos);
                
                if (pos > node_count + 1 || pos < 1) {
                    printf("Node cannot be inserted at position %d\n", pos);
                } else {
                    insert_node(data, pos);
                }
                break;
            }

            case 2: {
                if (node_count == 0) {
                    printf("There are no elements in the list to delete\n");
                } else {
                    printf("1. Delete at start\n");
                    printf("2. Delete at end\n");
                    printf("3. Delete at position\n");
                    int delete_choice;
                    scanf("%d", &delete_choice);
                    switch(delete_choice) {
                        case 1:
                            delete(1);
                            break;
                        case 2:
                            delete(-1);
                            break;
                        case 3: {
                            int pos;
                            printf("Enter position: ");
                            scanf("%d", &pos);
                            if (pos <= node_count && pos > 0) {
                                delete(pos);
                            } else {
                                printf("Invalid position\n");
                            }
                            break;
                        }
                        default:
                            printf("Invalid choice\n");
                            break;
                    }
                }
                break;
            }

            case 3:
                display();
                break;

            case 4:
                return;

            default:
                printf("Invalid choice, try again\n");
                break;
        }
    }
}

int main() {
    display_options();
    return 0;
}
