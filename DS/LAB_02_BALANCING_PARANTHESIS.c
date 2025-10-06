#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char i);
void pop();
char peek();
int match(char top, char incoming);

int main(){
    char expression[MAX];
    printf("Expression: ");
    scanf("%s", &expression);

    for(int i = 0; i < strlen(expression); i++){
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            push(expression[i]);
        }

        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
            char stack_top = peek();
            
            int j = match(stack_top, expression[i]);

            if (j == 1){
                pop();
            }

            else{
                printf("Unbalanced");
            }
        }
    }

    if (top == -1){
        printf("Balanced");
    }

    return 0;
}

//this is shrihari viswanahan program'

void push(char i){
    if (top == MAX - 1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top] = i;
    }
}

void pop(){
    if (top == -1){
        printf("Stack underflow");
    }
    else{
        int item = stack[top];
        top--;
    }
}

char peek(){
    if (top == -1){
        printf("Underflow");
    }
    else{
        return stack[top];
    }
}

int match(char top, char incoming){
    if (top == '(' && incoming == ')'){
        return 1;
    }

    if (top == '{' && incoming == '}'){
        return 1;
    }

    if (top == '[' && incoming == ']'){
        return 1;
    }

    return 0;
}
