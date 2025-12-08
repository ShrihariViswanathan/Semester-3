#include <stdio.h>
#include <stdlib.h>

int node_count = 0;

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;  // Global head for the linked list


// Function to display the linked list
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

// Create a new node
node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Insert at the start of the list
void insert_at_start(int data) {
    node *newnode = create_node(data);
    newnode->next = head;
    head = newnode;
    node_count++;
    printf("Inserted %d at the start\n", data);
}

// Insert at the end of the list
void insert_at_end(int data) {
    node *newnode = create_node(data);
    if (head == NULL) {
        head = newnode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    node_count++;
    printf("Inserted %d at the end\n", data);
}

// Insert at a specific position in the list
void insert_at_position(int data, int pos) {
    if (pos < 1 || pos > node_count + 1) {
        printf("Invalid position\n");
        return;
    }
    
    node *newnode = create_node(data);
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    node_count++;
    printf("Inserted %d at position %d\n", data, pos);
}

// Delete at the start of the list
void delete_at_start() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    node *temp = head;
    head = head->next;
    printf("Deleted element at start: %d\n", temp->data);
    free(temp);
    node_count--;
}

// Delete at the end of the list
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    if (head->next == NULL) {  // Only one element in the list
        free(head);
        head = NULL;
    } else {
        node *temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    node_count--;
    printf("Deleted element at end\n");
}

// Delete at a specific position in the list
void delete_at_position(int pos) {
    if (pos < 1 || pos > node_count) {
        printf("Invalid position\n");
        return;
    }
    
    if (pos == 1) {
        delete_at_start();
    } else {
        node *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        node *del_node = temp->next;
        temp->next = del_node->next;
        printf("Deleted element at position %d: %d\n", pos, del_node->data);
        free(del_node);
        node_count--;
    }
}

// Sort the list using Bubble Sort
void bubble_sort() {
    if (head == NULL || head->next == NULL) {
        printf("List is too small to sort\n");
        return;
    }

    node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted using Bubble Sort\n");
    display();
}

// Reverse the list using pointer changes
void reverse() {
    node *prev = NULL;
    node *current = head;
    node *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed\n");
    display();
}

// Concatenate two linked lists
void concatenate(node *list2) {
    if (head == NULL) {
        head = list2;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = list2;
    }
    printf("Lists concatenated\n");
}

// Function to input data for a new linked list
node *input_linked_list(node *head) {
    int data, more;
    node *temp;
    do {
        printf("Enter data for new node: ");
        scanf("%d", &data);
        node *newnode = create_node(data);
        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        node_count++;
        printf("Do you want to add another node? (1 = Yes, 0 = No): ");
        scanf("%d", &more);
    } while (more == 1);
    return head;
}

// Display menu and handle user input
void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Sort List\n");
        printf("9. Reverse List\n");
        printf("10. Concatenate Lists\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        int data, pos;
        node *list2 = NULL;
        
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_start(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insert_at_position(data, pos);
                break;
            case 4:
                delete_at_start();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_at_position(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                bubble_sort();
                break;
            case 9:
                reverse();
                break;
            case 10:
                printf("Concatenating with another list\n");
                list2 = input_linked_list(list2);  // Input for second list to concatenate
                concatenate(list2);
                break;
            case 11:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 11);
}

int main() {
    menu();
    return 0;
}



