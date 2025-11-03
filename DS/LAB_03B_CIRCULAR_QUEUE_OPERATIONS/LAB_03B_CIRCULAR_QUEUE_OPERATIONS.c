//

#include <stdio.h>
#define N 2



int circular[N];

int front = -1;
int rear = -1;
int e = 0;

void Insert(int x){
    if (front == (rear + 1) % N){
        printf("Queue is Full\n");
        return;
    }

    if (front == -1 && rear == -1){
        front = rear = 0;
        circular[rear] = x;
    }


    else{
        rear = (rear + 1) % N;
        circular[rear] = x;
    }

    
}


void Delete(){
    if (front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }

    else if (front == rear){
        int element = circular[front];
        front = rear = -1;
        printf("Removed Element: %d\n", element);
    }

    else{
        int element = circular[front];
        front = (front + 1) % N;
        printf("Removed Element %d\n", element);
    }
}


void Display(){
    printf("THE ELEMENTS OF THE QUEUE ARE\n");
    int f = front;
    int r = rear;
    int count = 1;
    if(f != -1 && r!= -1){
        while (1){
            printf("Position %d: %d\n", count, circular[f]);
            if (f == r)
                break;
            
            count++;
            f = (f+1) % N;
            }
    }

    else{
        printf("Queue Empty");
    }
    
}


int main(void){
    int i = 1;
    while (i == 1){
        printf("\n");
        printf("Circular Queue Operations: \n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");


        int choice = 0;
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Element to Insert: ");
                scanf("%d", &e);
                Insert(e);
                break;
            
            case 2:
                Delete();
                break;
            
            case 3:
                Display();
                break;
            
            case 4:
                i = 0;
                printf("You have exited the Circular Queue Operations");
                break;
        }

        printf("\n");

    }
}