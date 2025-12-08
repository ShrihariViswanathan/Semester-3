#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create_node(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root, int value){
    if(root == NULL){
        return create_node(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    } else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void display(struct node* root ){
    printf("BST ELEMENTS (INORDER): ");
    inorder(root);
    printf("\n");
}
int main(){
    struct node* root = NULL;
    int choice, value;
    while(1){
        printf("\n----- BINARY SEARCH TREE OPERATIONS -----\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        
        printf("5. Display BST\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
           case 1:
               printf("Enter value to insert: ");
               scanf("%d", &value);
               root = insert(root, value);
               break;
              case 2:
               printf("Inorder Traversal: ");
               inorder(root);
               printf("\n");
               break;
              case 3:
               printf("Preorder Traversal: ");
               preorder(root);
               printf("\n");
               break;
              case 4:
               printf("Postorder Traversal: ");
              postorder(root);
               printf("\n");
               break;
              case 5:
               display(root);
               break;
                case 6:
                exit(0);
            default:
                printf("INVALID INPUT\n");
        }
    }
    return 0;
}