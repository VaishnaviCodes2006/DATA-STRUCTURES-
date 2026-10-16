#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int front, rear;
    int data[SIZE]
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q, int item)
{
    if(q -> rear==SIZE-1)
        printf("\n Queue is full");
    else
    {
        q -> rear=q->rear+1;
        q->data[q->rear] = item;
        if(q-> front==-1)
            q->front=0;
    }
}
void dequeue (QUEUE * q)
{
    if(q->front==-1)
        printf("\n Queue is empty");
    else
    {
        printf("\n Element deleted is %d", q->data[q->front]);
    if(q->front==q-> rear)
    {


        q->front=-1;
        q->rear=-1;
    }
    else
        q->front= q->front+1;
    }
}
void display(QUEUE q)
{
    int i;
    if(q.front == -1)
        printf("\n Queue is empty");
    else
    {
        printf("\n Contents of queue are\n");
        for(i=q.front; i<=q.rear; i++)
            printf("%d\t", q.data[i]);
    }
}

int main()
{
    int item ,choice;
    QUEUE q;
    q.front=-1;
    q.rear=-1;
    for(;;)
    {
        printf("\n 1.insert \n2.delete \n 3.display \n4.exit");
        printf("read choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1 :
            printf("read item to insert:");
            scanf("%d",&item);
            enqueue(&q,item);
            break;
            case 2:
            dequeue(&q);
            break;
            case 3:
            display(q);
            break;
            case 4:
            exit(0);
            default:exit(0);}}
    return 0;
}
