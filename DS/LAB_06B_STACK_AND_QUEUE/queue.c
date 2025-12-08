#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enqueue(int w){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=w;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
        return;
    }
    rear->next=newnode;
    rear=newnode;
}
void dequeue(){
    if(front==NULL){
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    struct node* temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    printf("The dequeued element is: %d\n",temp->data);
    free(temp);
}
void display(){
    struct node* temp=front;
    if(temp==NULL){
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("The elements in the queue are:\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    int choice, value;
    while(1){
        printf("\nEnter the operation\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
