#include<stdio.h>
#define MAX 5 
void swap(int a[], int i,int j)
{
    int t=a[i];
    a[i]=a[j];
    a[j]=t;

}
void heapup(int heap[],int newnode)
{
    if (newnode==0)
        return;
    else
    {
        int parent=(newnode-1)/2;
        if(heap[newnode]>heap[parent])
        {
            //for maxheap
            swap(heap,parent,newnode);
            heapup(heap,parent);
        }

    }
}
void heapdown(int heap[],int beg, int end)
{
    if(2*beg+1<=end) //one child exists
    {
        int l,r,largest;
        l=2*beg+1;
        largest=l;
        if(2*beg+2<=end)
        {
            //right child exists
            r=2*beg+2;
            if(heap[r]>heap[l])
                largest=r;
            else 
                largest=l;
        }
        
        if(heap[largest]>heap[beg])
        {
            swap(heap,largest,beg);
            heapdown(heap,largest,end);
        }
    }

}

void buildHeap(int heap[],int size)
{

    int walker=1;
    while(walker<size)
    {
        heapup(heap,walker);
        walker=walker+1;
    }

}

int insertHeap(int heap[],int *last,int data)
{
    if (*last==MAX)
        return 0;
    else
    {
        *last=*last+1;
        heap[*last]=data;
        heapup(heap,*last);
        return 1;
    }

}

int deleteHeap(int heap[],int *last,int *dataout)
{
    if(*last<0)
        return 0;

    else
    {
        *dataout=heap[0];
        heap[0]=heap[*last];
        *last=*last-1;
        heapdown(heap,0,*last);
        return 1;
    }

}

int main()
{
    int n,i;
    int a[MAX];
    int data;
    int last;
    scanf("%d",&n);
    last=n-1;

    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
        
    buildHeap(a,n);
   
    char ch;

    while(1)
    {
    scanf("%c",&ch);
    scanf("%c",&ch);
    
    
    if(ch=='I')
    {
        scanf("%d",&data);
        if(insertHeap(a,&last,data))
            printf("Insertion sucessful!!\n");
        else
            printf("Insertion unsucessful!!\n");
    }
    else if(ch=='D')
    {
        int dataout;
                //printf("last:%d \n",last);
        
        if(deleteHeap(a,&last,&dataout))
        {   printf("out:%d\n",dataout);
           // for(i=0;i<last;++i)
             //   printf("%d ",a[i]);
        }

        else
            printf("Deletion Unsucessful\n");
    }
    else if(ch=='M')
    {
        if(last<0)
            printf("Sorry heap empty\n");
        else
            printf("max:%d\n",a[0]);
        
    }
    if(ch=='Q')
        break;
    }
return 0;
}
