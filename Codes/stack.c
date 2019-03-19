#include<stdio.h>
#include<stdlib.h>
#define size 5

struct Stack
{
    int items[size];
    int top;
};


typedef struct Stack stack;

void push(stack *s,int num)
{
   if(s->top == size-1)
   {
       printf("Stack is full!\n");
       return;
   }
   s->items[++s->top]=num;
}
int pop(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    return s->items[s->top--];
}

int peek(stack s)
{
    if(s.top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    return s.items[s.top];
}

void display(stack s)
{
    int i;
    if(s.top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: \n");
    for(i=s.top;i>-1;i--)
        printf("%d\n",s.items[i]);

}

int main()
{
    stack s;
    int num,ch,i,j;

    s.top = -1;
    while(1)
    {
        printf("Enter 1: Push\n2: Pop\n3:Display\n4: Peek\n5:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number to push: ");
                    scanf("%d",&num);
                    push(&s,num);
                    break;
            case 2: printf("Popped element: %d\n",pop(&s));
                    break;
            case 3: display(s);
                    break;
            case 4: printf("Popped element: %d\n",peek(s));
                    break;
            case 5: exit(1);
                    break;

        }

    }
    return 0;
}
