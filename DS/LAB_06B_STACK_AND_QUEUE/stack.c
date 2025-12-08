#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* top=NULL;
void push(int w){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=w;
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(top==NULL){
        printf("STACK UNDERFLOW\n");
        return;
    }
    struct node* temp=top;
    top=top->next;  
    printf("The popped element is: %d\n",temp->data);
    free(temp);
}
void display(){
    struct node* temp=top;
    if(temp==NULL){
        printf("STACK IS EMPTY\n");
        return;
    }
    printf("The elements in the stack are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    int choice, value;
    while(1){
        printf("\nEnter the operation\n1: Push\n2: Pop\n3: Display\n4: Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
