#include <stdio.h>
#include <stdlib.h>

int NODE_count = 0;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

//creation of node
Node* create_node(){
    Node *newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL){
        printf("Memory allocation failed");
        exit(0);
    }

    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    newnode-> data = data;

    newnode-> next = NULL;
    return newnode;
}

//inserting node 0-> start, -1-> tail, else-> random position
void insert_node(int pos){
    Node *newnode = create_node();

    if (pos == 0){//begining
        newnode -> next = head;
        head = newnode;//head keeps track of the start node
        printf("Inserted at start\n");
        NODE_count++;
        return;
    }

    if (pos == -1){//end
        Node *temp = head;
        while (temp-> next != NULL)
            temp = temp->next;
        
        temp -> next = newnode;
        newnode -> next = NULL;
        printf("Inserted node at end\n");
        NODE_count++;
        return;
    }

    else{//any pos
        Node *temp = head;
        int count = 1;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode-> next = temp-> next;
        temp-> next = newnode;
        printf("Inserted node at position %d\n", pos);
        NODE_count++;
        
    }
}

//display
void display() {
    Node *temp = head;
    int count = 1;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("Position %d: %d\n", count - 1, temp->data);
        temp = temp->next;
        count++;
    }
}


int main(){
    int i = 1;
    int choice;
    int pos;
    while(i == 1){
        printf("\n\n");
        printf("Linked List Operations\n");
        printf("1. Insert at begining\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("\nChoice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insert_node(0);
                break;
            case 2:
                insert_node(-1);

                break;
            case 3:{
                printf("Enter Position (0 to %d): ", NODE_count + 1);
                scanf("%d", &pos);
                insert_node(pos);
                break;
            }
            case 4:
                display();
                break;
            case 5:
                printf("You exited");
                i = 0;
                break;
        }


    }
}