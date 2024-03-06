#include <stdio.h>


 // Binary Tree
typedef struct node {

int data;
struct node* left;
struct node* right;

}node;


/*********************************************/
// Inorder traversal

void inorder(node* root){

    if (root==NULL)             //check is root is nothing
        return;
    inorder(root->left);              //first visit all nodes in left
    printf("%d->",root->data);        //then,root node
    inorder(root->right);             //visit all nodes in right

}

/*******************************************/

// Preorder traversal

void preorder(node* root){

    if (root==NULL)
        return;

    printf("%d->",root->data);         // root node
    inorder(root->left);               // visit all nodes in left
    inorder(root->right);                //visit all nodes in right

}
/*******************************************/

// Postorder traversal
void postorder(node* root){

    if (root==NULL)
        return;

    inorder(root->left);           // visit all nodes in left
    inorder(root->right);              //visit all nodes in right
    printf("%d->",root->data);         // root node

}

/********************************************/
                                                  //create inital node
node* NewItem(value)
{
    node* NewNode=malloc(sizeof(node));

    NewNode->data=value;
    NewNode->left=NULL;
    NewNode->right=NULL;
}



/******************************************/

node* insert(node* root, int data)                     //Function to add new element
{
    if (root == NULL) {
        root = NewItem(data);
    } else if (data <= root->data) {                   // Check Is root is greater than data ,will put data in new node on the left
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);          // Check Is root is less than data ,will put data in new node on the right
    }
    return root;
}

/******************************************/

int main(){

    node* root= NewItem(0);

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    printf("Tree inorder:");          // print tree in inorder
    inorder(root);
    printf("\n");

    printf("Tree preorder:");        //print in preorder
    preorder(root);
    printf("\n");

    printf("Tree postorder:");       //print in postorder
    postorder(root);

}
