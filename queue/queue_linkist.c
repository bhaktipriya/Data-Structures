#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node*next;
}node;
node *front,*rear;
void enqueue(int n)
{
    node *p=(node*)malloc(sizeof(node));
    p->val=n;
    p->next=NULL;
    if(front==NULL)
        front=rear=p;
    else
    {
        rear->next=p;
        rear=p;
    }

}

void dequeue()
{

    if(front==NULL)
        printf("\n Underflow");

    else
    {

        node *temp = front->next;
        int data=front->val;
        free(front);
        front=temp;
        if(front==NULL)
            front=rear=NULL;

        printf("Value removed:%d\n",data);
    }


}

void showfront()
{
    if(front==NULL)
        printf("Empty\n");
    else
        printf("Front:%d\n",front->val);

}
void printq()
{
    node *ptr=front;

    if(front==NULL)
    { printf("empty\n");return;}
    while(ptr!=NULL)
    {printf("%d ",ptr->val);ptr=ptr->next;}
    printf("\n");

}


int main()
{
    int ch,data;

    front=rear=NULL;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d",&data);enqueue(data);break;
            case 2:dequeue();break;
            case 3:showfront();break;
            case 4:printq();break;

        }
        if(ch==0)
            break;


    }
    return 0;
}
