#include<stdio.h>
#include<ctype.h>
#include<string.h>


#define MAX 100

void push(char c);
char pop();
char peek();
int associativity(char operator);
int precedence(char operator);
void infix_to_postfix(char infix[], char postfix[]);


char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top = -1;
int k = 0;

int main(void){
    
    printf("Infix Expression: ");
    scanf("%s", infix);
    
    infix_to_postfix(infix, postfix);
    
    printf("Postfix Expression: ");
    printf("%s", postfix);
}

void push(char element){
    if(top == MAX-1) return;
    top++;
    stack[top] = element;
}

char pop(){
    char element = stack[top];
    top--;
    return element;
}


char peek(){
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char op) {  
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1; // for non-operators
    }
}


int associativity(char op){
    switch(op){
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        case '^':
            return 2;
        default:
            return -1;
    }
}


void infix_to_postfix(char infix[], char postfix[]){
    for(int i = 0; i < strlen(infix); i++){
        char incoming = infix[i];
        
        if (incoming  == '(') push(incoming);
        else if (isalnum(incoming)) postfix[k++] = incoming;

        else if (incoming == ')'){
            while((top != -1) && (peek() != '(')) postfix[k++] = pop();
            pop();//to remove the (
        }

        else if (precedence(incoming) > precedence(peek())) push(incoming); 

        else{
            while (top != -1 && ((precedence(incoming) < precedence(peek())) || 
            (precedence(incoming) == precedence(peek()) && associativity(incoming) == 1))) 
            {
                postfix[k++] = pop();
            
            }

            push(incoming);
        }
   
    }

    while(top != -1) postfix[k++] = pop();

    postfix[k++] = '\0';

}
