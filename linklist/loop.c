#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int val;
	struct list* next;
}list;
list* head=NULL;
int main()
{
	int i,a,n;
	list* temp,*link,*new;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		new=(list*)malloc(sizeof(list));
		new->val=a;
		new->next=NULL;
		if(i==n-4)
		link=new;		
		if(i==0)
		{
			temp=new;
			head=new;
		}
		else
		{
			temp->next=new;
			temp=temp->next;

		}
	}
		

		new->next=link;
	

	list* slow=head;
	list* fast=head;
    int flag=0;
	while(slow->next!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast)
		{
			printf("loop exist\n");
			flag=1;
            break;
		}
	}
	
	
    if(flag==0)
	{
		printf("loop doesnot exist\n");
	}
    else if (flag==1)
    {
        list *hare,*tort;
        hare=fast;
        tort=slow;
        int len =1 ,ct;
        hare=tort->next;
        
        while(tort!=hare)
        {
            hare=hare->next;
            len++;
        }
        
        hare=fast;
        tort=slow;
        
        
        printf ("Length of loop %d\n",len);
       
        int pos=0;
        tort=head;
        while(tort!=hare)
        {   
            tort=tort->next;
            hare=hare->next;
            pos++;
        }
            
        printf ("Loop beg is %d @pos:%d\n",tort->val,pos); 
    
    //removing a loop;

        temp=tort;//beginnnig
        while(--len)
        {temp=temp->next;}
      
        temp->next=NULL;
    }

	temp=head;
    while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
	printf("\n");
	return 0;
}

