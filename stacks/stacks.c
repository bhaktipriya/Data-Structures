#include<stdio.h>

int top=-1;    
int a[100];

void push(int el)
{
    a[++top]=el;
    if(top==100)
        printf("Overflow\n");

}

void pop()
{
    if(top==-1)
    { printf("Underflow\n");return;}
    printf("Popped:%d\n",a[top]);
    top--;
}

void print_stack()
{

    int i;
    printf("elements: \n");
    for(i=top;i>=0;--i)
        printf("%d ",a[i]);

    printf("\n");
}

int peek()
{
    return a[top];
}

int main()
{
    int ch=1,el;
    while(1)
    {
        scanf("%d",&ch);

        switch(ch)
        {
            case 0:break;
            case 1:scanf("%d",&el);
                   push(el);
                   break;
            case 2:pop();
                   break;
            case 3:printf("top: %d\n",peek());
                   break;
            case 4:print_stack();
                   break;


        }
        if(ch==0)
            break;

    }



    return 0;
}
