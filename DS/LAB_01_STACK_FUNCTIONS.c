//this is shrihari viswanahan program'

#include <stdio.h>

#define N 2

int stack[N];
int top = -1;

void push();
void pop();
void peek();

int main()
{
    int i = 1;
    while(i == 1){
        printf("\n");
        printf("\n");

        printf("Operations for the stack:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        int choice = 0;
        printf("Enter choice: ");
        scanf("%d",  &choice);

        switch(choice){
            case 1: push();
                break;

            case 2: pop();
                break;
            
            case 3: peek();
                break;
            
            case 4: i = 0;
                break; 
        }
    }


}

void push(){
    int value = 0;
    printf("Integer to push: ");
    scanf("%d", &value);
    
    if (top == N - 1){
        printf("Stack Overflow");
    }

    else{
        top++;
        stack[top] = value;

    }
}


void pop(){
    if (top == -1){
        printf("Stack underflow");
    }
    
    else{
        int item = stack[top];
        printf("the item on the top was %d", item);
        top--;

    }
}

void peek(){

    if (top == -1){
        printf("Underflow");
    }

    else{
        printf("Element: %d", stack[top]);
    }
}
