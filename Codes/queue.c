#include<stdio.h>
#include<stdlib.h>
#define size 5

struct Queue
{
    int items[size];
    int front;
    int rear;
};

typedef struct Queue queue;

void enqueue(queue *q,int num)
{
   if(q->rear == size-1)
   {
       printf("queueis full!\n");
       return;
   }
   q->items[++q->rear]=num;
}
int dequeue(queue *q)
{
    if(q->front >q->rear)
    {
        printf("queue is empty!\n");
        return;
    }
    return q->items[q->front++];
}

void display(queue q)
{
    int i;
    if(q.front >q.rear)
    {
        printf("queueis empty!\n");
        return;
    }
    printf("queue elements: \n");
    for(i=q.rear;i>=q.front;i--)
        printf("%d\n",q.items[i]);

}

int main()
{
    queue q;
    int num,ch,i,j;
    q.front = 0;
    q.rear = -1;
    while(1)
    {
        printf("Enter 1: Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number: ");
                    scanf("%d",&num);
                    enqueue(&q,num);
                    break;
            case 2: printf("Dequeued element: %d\n",dequeue(&q));
                    break;
            case 3: display(q);
                    break;
            case 4: exit(1);
                    break;

        }

    }
    return 0;
}
