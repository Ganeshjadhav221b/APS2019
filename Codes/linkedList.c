#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;


node* insertNode(node *start)
{
    node *newNode;
    newNode = malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("Failed to allocate memory!\n");
        return start;
    }
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(start == NULL)
        return newNode;
    newNode->next = start;
    return newNode;

}

node* insertNodeAtEnd(node *start)
{
    node *newNode;
    newNode = malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("Failed to allocate memory!\n");
        return start;
    }
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(start == NULL)
        return newNode;

    node *tempNode = start;
    while(tempNode->next!=NULL)
        tempNode=  tempNode->next;
    tempNode->next = newNode;
    return start;
}

node* deleteNodeAtEnd(node *start)
{
    if(start == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    if(start->next == NULL)
    {
        free(start);
        return NULL;
    }
    node *cur = start;
    node *prev = NULL;
    while(cur->next!=NULL)
    {
        prev=  cur;
        cur = cur->next;
    }

    printf("%d deleted\n",cur->data);
    prev->next= NULL;
    free(cur);
    return start;
}

node* deleteNode(node *start)
{
    if(start == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    if(start->next == NULL)
    {
        free(start);
        return NULL;
    }
    node *cur = start;
    printf("%d deleted\n",cur->data);
    start = cur->next;
    free(cur);
    return start;
}

void displayList(node *start)
{
    if(start == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node *temp;
    for(temp=  start;temp!=NULL;temp=temp->next)
        printf("%d\n",temp->data);
}


int main()
{
    node *start;
    int num,ch,i,j;
    while(1)
    {
        printf("Enter 1: Insert a node\n2:Delete a node\n3:Display List\n4:Exit\n5: Insert a node at end\n6:Delete a node at end\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start = insertNode(start);
                    break;
            case 2: start = deleteNode(start);
                    break;
            case 3: displayList(start);
                    break;
            case 4: exit(1);
            case 5: start = insertNodeAtEnd(start);
                    break;
            case 6: start = deleteNodeAtEnd(start);
                    break;
        }
    }
    return 0;
}
