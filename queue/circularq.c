#include<stdio.h>
//whenever you overwrite front moves forward
#define size 4
int cq[size];
int front,rear;

void push(int n)
{
    if (front == -1)
    {
        front=rear=0;
        cq[rear]=n;
    }
    else
    {
        rear=(rear+1)%size;
        cq[rear]=n;
        if (front == rear)//overwriting
            front=rear+1;
    }

}

void pop()
{
    if(front==-1)
        printf("empty");
    else
    {
        printf("popped:%d\n",cq[front]);
        cq[front]=0;
        if (front==rear)
        {front=rear=-1;}
        else
        {
            front=(front+1)%size;
        }
    }


}

void printq()
{
    if(front==-1)
    {printf("empty");return;}


    int i=front;
    if(front==rear)
        printf("%d",cq[front]);
    else
        if(front<rear)
        {
            while(i<=rear)
            {printf("%d ",cq[i]);++i;}
            printf("\n");

        }
        else if(front>rear)
        {

            while(i<size)
            {printf("%d ",cq[i]);++i;}

            i=0;
            while(i<=rear)
            {printf("%d ",cq[i]);++i;}


            printf("\n");


        }
}
void showfront()
{
    if(front==-1)
        printf("Empty\n");
    else
        printf("Front:%d\n",cq[front]);

}



int main()
{
    int ch,data;

    front=rear=-1;
    while(1)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:scanf("%d",&data);push(data);break;
            case 2:pop();break;
            case 3:showfront();break;
            case 4:printq();break;

        }
        if(ch==0)
            break;


    }
    return 0;
}

