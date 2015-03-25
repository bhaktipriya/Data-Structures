#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;
node *head;
void insert(int val)
{	
	node *p = (node*)malloc(sizeof(node));  
	p -> data = val;
	p->next = NULL;
//first insertion
	if(head==NULL)
	{
		head = p;
		return;
	}
//smallest value to be inserted at the beginning
	if(head -> data >= val)
	{
		p->next=head;
		head = p;
		return;
	}
//traverse for right position
	node *q = head;
	node *r ;
	while(q!=NULL && q->data < val)
	{
		r = q;
		q = q->next;   
	}

	r->next = p;   
	p->next = q;


	return;
}
void rem(int val)
{
	if(head->data==val)
	{
		node *tmp = head->next;
		free(head);
		head = tmp;
		return;
	}
	node* p = head;
	node* q = head;

	while(p!=NULL&&p->data!=val)
	{
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("Value not found!\n");
		return;
	}
	q->next = p->next;
	free(p);
	return;
}

void print()
{
	node *p = head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void rev_it()
{
    node* cur,*prev,*ptr,*nxt;

    ptr=head;
    prev=NULL;
    while(ptr!=NULL)
    {
        cur=ptr;
        ptr=ptr->next;
        cur->next=prev;
        prev=cur;
    }
    head=prev;

}

void rev_rec(node *prev,node *hd)
{
    if(hd==NULL)
    {
        head=prev;
        return;
    }
    else
    {
       node *next=hd->next;
        hd->next=prev;
       rev_rec(hd,next);
    }
}

void mid()
{
    node *f=head;
    node *s=head,*prev;
    int ct=1;
    while(f!=NULL&&f->next!=NULL)
    {
        
        f=f->next->next;
        prev=s;
        s=s->next;
    }
    printf("%d\n",s->data);
}

int main()
{
	head = NULL; 
	char ch;
	int val;
	while(1)
	{
		scanf(" %c",&ch);
		if(ch=='I')  
		{
			scanf("%d",&val);
			insert(val);
		}
		else if(ch=='D') 
		{
			scanf("%d",&val);
			rem(val);
		}
		else if(ch=='P')
		{
			print();
		}
        else if(ch=='R')
        {
            rev_it();
        }
        else if(ch=='C')
        {
            rev_rec(NULL,head);
        }
        else if(ch=='M')
        {
             mid();    
        }
		else if(ch=='Q')
			break;

		else
			printf("Invalid option!\n");
	}
	return 0;
}
