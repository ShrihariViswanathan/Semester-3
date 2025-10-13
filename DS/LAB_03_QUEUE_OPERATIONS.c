#include <stdio.h>

# define N 2

int queue[N];
int front = -1;
int rear = -1;

void enque();
void deque();
void display();
void peek();

int main(void){
    int choice = 0;
    int i = 1;

    while (i == 1){
        printf("\n");
        printf("\n");
        printf("Operations of Queue\n");

        printf("1. Enque\n");
        printf("2. Deque\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");


        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                i = 0;
                break;
            default:
                printf("Invalid Value Entered");
                break;
        }



    }
}

void enque(){

    if (rear == N - 1) 
        printf("Queue Overflow\n");
    
    else if (front == -1 && rear == -1) {
        int x = 0;
        printf("Element to Enque: ");
        scanf("%d", &x);
        front = rear = 0;
        queue[rear] = x;
    }

    else {
        int x = 0;
        printf("Element to Enque: ");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }
}


void deque(){
    if (front == -1 && rear == -1) 
        printf("Queue is Empty\n");

    else if (front == rear && front != -1){
        int element =  queue[front];
        front = rear = -1;
        printf("Element Dequeued: %d", element);
    }

    else{
        int element = queue[front];
        front++;
        printf("Element Dequeued: %d", element);
    }
}


void display(){
    if (front == -1 && rear == -1)
        printf("Queue is empty\n");

    else {
        printf("Queue Elements \n");
        for (int i = front; i <= rear; i++){
            printf("%d. %d\n", i, queue[i]);
        }
    }
}

void peek(){
    if (front == -1 && rear == -1)
        printf("Queue is empty\n");

    else{
        printf("Element at front: %d", queue[front]);
    }
}




