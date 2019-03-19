#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST BST;

BST* insert(BST *root)
{
    BST *newNode=  (BST *)malloc(sizeof(BST));
    if(newNode == NULL )
    {
        printf("Memory allocation failed\n");
        return root;
    }

    printf("Enter tree data: ");
    scanf("%d",&newNode->data);
    newNode->left = NULL;
    newNode->right= NULL;
    if(root == NULL)
        return newNode;
    BST *prev,*cur = root;
    while(cur!=NULL)
    {
        prev = cur;
        if(cur->data>newNode->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(prev->data >newNode->data)
        prev->left = newNode;
    else
        prev->right = newNode;
    return root;
}

void inorder(BST* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

BST* deleteNode(BST* root)
{
    if(root == NULL)
    {
        printf("No nodes!\n");
        return root;
    }
    int data;
    printf("Enter element to delete: ");
    scanf("%d",&data);
    BST *parent,*cur,*succ,*p;
    cur = root;
    parent = NULL;
    while(cur != NULL && cur->data!=data)
    {
        parent = cur;
        if(cur->data>data)
            cur = cur->left;
        else
            cur= cur->right;
    }
    if(cur == NULL)
    {
        printf("Data not found!\n");
        return root;
    }
    if(cur->left == NULL)
        p = cur->right;
    else if(cur->right == NULL)
        p = cur->left;
    else
    {
        succ = cur->right;
        while(succ->left!=NULL)
            succ = succ->left;
        succ->left = cur->left;
        p = cur->right;
    }

    if(parent == NULL)
    {
        free(cur);
        return p;
    }
    if(p == cur->left)
        parent->left = p;
    else
        parent->right= p;
    free(cur);
    return root;

}
int main()
{
    BST *root = NULL;


    int ch;
    while(1)
    {
        printf("Enter 1: Insert node\n2: Delete a node\n3: Inorder\n10 Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: root = insert(root);
                    break;
            case 2: root = deleteNode(root);
                    break;
            case 3: inorder(root);
                    break;

            case 10: exit(10);
        }
    }
    return 0;
}
