#include<stdio.h>
#include <stdlib.h>

int node_count = 0;

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node *create_node(int data){
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL){
        printf("Memory allocation failed");
        exit(1);
    }

    newnode -> data = data;
    newnode -> next = NULL;

    if (head == NULL)
        head = newnode;

    return newnode;
}

int insert_node(int data, int pos){
    node *newnode = create_node(data);

    if (pos == 1){
        newnode -> next = head;
        head = newnode;
        printf("Inserted %d at position %d\n", data, pos);
        node_count++;
        return 0;
    }

    if (pos == -1){
        node *temp = head;

        while(temp-> next != NULL)
            temp = temp->next;

        temp ->next = newnode;
        newnode -> next = NULL;

        printf("Inserted %d at end\n", data);
        node_count++;
        return 0;
    }

    if (pos > 1 && pos <= node_count + 1){
        int count = 1;
        node *temp = head;

        while(temp != NULL && count < pos - 1){
            temp = temp-> next;
            count++;
        }

        newnode -> next = temp-> next;
        temp-> next = newnode;
        printf("Inserted %d at %d\n", data, pos);
        node_count++;
        return 0;
    }

    printf("Invalid position\n");
    return -1;
}


void display(){
    int count = 1;
    node *temp = head;

    if(t != NULL){
        while(temp != NULL){
            printf("P%d: %d\n", count, temp->data);
            temp = temp->next;
            count++;
        }
    } else {
        printf("Linked List is empty\n");
    }
}

int delete_node(int pos){
    if (head == NULL){
        printf("List empty\n");
        return -1;
    }

    if (pos == 1){
        node *temp = head;
        head = head -> next;
        printf("Element at START has been deleted. It was %d\n", temp-> data);
        node_count--;
        free (temp);
        return 0;
    }

    if (pos == -1){
        node *temp = head;
        node *prev = NULL;

        while(temp-> next != NULL){
            prev = temp;
            temp = temp-> next;
        }

        if (prev != NULL)
            prev-> next = NULL;

        printf("Element at END has been deleted. It was %d\n", temp-> data);
        node_count--;
        free(temp);
        return 0;
    }

    if (pos > 1 && pos <= node_count){
        int count = 1;
        node * prev = NULL;
        node * temp = head;

        while (temp != NULL && count < pos){
            count++;
            prev = temp;
            temp = temp -> next;
        }

        if (temp == NULL) return -1;

        prev -> next = temp -> next;
        printf("Element at P%d has been deleted. It was %d\n", pos, temp-> data);
        node_count--;
        free(temp);
        return 0;
    }

    return -1;
}

void display_options(){
    printf("\n1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Display Linked List\n");
    printf("4. Exit\n");
    printf("Enter choice: ");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:{
            printf("Enter data: ");
            int data;
            scanf("%d", &data);

            if (head == NULL){
                insert_node(data, 1);
                break;
            }

            int pos;
            printf("Enter Position: ");
            scanf("%d", &pos);

            if (pos > node_count + 1){
                printf("Node cannot be inserted\n");
                break;
            }

            insert_node(data, pos);
            break;
        }

        case 2:{
            if (node_count == 0){
                printf("There are no elements in the list to delete\n");
                break;
            }

            if (node_count == 1){
                delete_node(-1);
                break;
            }

            printf("1. delete at start\n");
            printf("2. delete at end\n");
            printf("3. delete at position\n");

            int ch2;
            scanf("%d", &ch2);

            switch(ch2){
                case 1:
                    delete_node(1);
                    break;

                case 2:
                    delete_node(-1);
                    break;

                case 3:{
                    printf("Enter position: ");
                    int pos;
                    scanf("%d", &pos);

                    if (pos == 1)
                        delete_node(1);
                    else if (pos == node_count)
                        delete_node(-1);
                    else
                        delete_node(pos);
                    break;
                }
            }
            break;
        }

        case 3:
            display();
            break;

        case 4:
            exit(0);
    }
}


int main(){
    while(1){
        display_options();
    }
}
