//Author:Bhaktipriya Shridhar
//Date:26th Feb 2015

#include<stdio.h>
#include<stdlib.h>
//check if a bst is valid
//Maintain ranges for a tree and check if values are in ranges 
typedef struct bstnode
{int val; struct bstnode *l;struct bstnode *r;}bstnode;
bstnode *root = NULL;

struct bstnode *newnode = NULL, *parent, *temp2;
void Delete(bstnode *ptr);
void deletion_search(bstnode *ptr,int data);
void insertion_search(bstnode *ptr)
{
    printf("%d ",ptr->val);
    if((newnode->val>ptr->val)&&(ptr->r!=NULL))
        insertion_search(ptr->r);
    else if((newnode->val>ptr->val)&& (ptr->r==NULL))
            ptr->r=newnode;
    else if((newnode->val<ptr->val)&& (ptr->l!=NULL))
            insertion_search(ptr->l);
    else if((newnode->val<ptr->val)&& (ptr->l==NULL))
            ptr->l=newnode;



}
void insert(int data)

{
    newnode=(bstnode*)malloc(sizeof(bstnode));
    newnode->val=data;
    newnode->l=newnode->r=NULL;
    printf("newnode:%d \n",newnode->val);
    if (root==NULL)
        root=newnode;
    else    
        insertion_search(root);    
}

int maxdepth(bstnode *ptr)
{
    if(ptr==NULL)
        return 0;
    int left=maxdepth(ptr->l);
    int right=maxdepth(ptr->r);

    if(left > right)
        return left+1;
    else
        return right+1;

}

int delete(int data)
{
    if(root==NULL)
        printf("EMPTY\n");
    //if(search(root,data)==0)

    else
    {
        parent=root;
        temp2=root;
        deletion_search(root,data);
    }
}

int search(bstnode *ptr,int el)
{
    if(ptr==NULL)
        return 0;
    if(ptr->val==el)
        return 1;
    else if(ptr->val<el)
    {return search(ptr->r,el);}//look in right
    else if(ptr->val>el)
    {return search(ptr->l,el);} //look in left

}
void deletion_search(bstnode *ptr,int el)
{
    if(ptr ==NULL)
        return;
    if(ptr->val==el)
        Delete(ptr);
    else if(ptr->val<el)
    {parent=ptr;deletion_search(ptr->r,el);}//look in right
    else if(ptr->val>el)
    {parent=ptr;deletion_search(ptr->l,el);} //look in left

}

void inorder (bstnode *ptr)
{

    if(ptr->l!=NULL)
        inorder(ptr->l);
    printf("%d ",ptr->val);
    if(ptr->r!=NULL)
        inorder(ptr->r);
}

void postorder (bstnode *ptr)
{
    if(ptr->l!=NULL)
        inorder(ptr->l);
    if(ptr->r!=NULL)
        inorder(ptr->r);
    printf ("%d ",ptr->val);


}

void preorder(bstnode *ptr)
{
    printf("%d ",ptr->val);
    if(ptr->l!=NULL)
        preorder(ptr->l);
    if(ptr->r!=NULL)
        preorder(ptr->r);

}


  

int smallest(bstnode *ptr)
{
    temp2=ptr;
    if(ptr->l!=NULL)
    {    temp2=ptr;smallest(ptr->l);}
    else
        return ptr->val;
}
int largest(bstnode *ptr)
{
    temp2=ptr;
    if(ptr->r!=NULL)
    {temp2=ptr;largest(ptr->r);}
    else
        return ptr->val;
}
void Delete(bstnode *ptr)
{
    if(root==NULL)
    {printf("EMPTY!");return;}

    if(ptr->l==NULL&&ptr->r==NULL)
    {
        printf("Just removed :%d",ptr->val);


        if(parent->l==ptr)
            parent->l=NULL;
        else if(parent->r==ptr)
            parent->r=NULL;

        free(ptr);   
    }
    else if(ptr->r==NULL)
    {
        printf("Just removed :%d",ptr->val);
        if(parent==ptr)
        {root=ptr->l;parent=root;}
        if(parent->l==ptr)
            parent->l=ptr->l;
        else if(parent->r==ptr)
            parent->r=ptr->l;
        free(ptr);
    }

    else if(ptr->l==NULL)
    {
        printf("Just removed :%d",ptr->val);
        if(parent==ptr){root=ptr->r;parent=root;}
        if(parent->l==ptr)
            parent->l=ptr->r;
        else if(parent->r==ptr)
            parent->r=ptr->r;
        free(ptr);
    }
    else if(ptr->l!=NULL&&ptr->r!=NULL)
    {
        temp2=root;
        int swapval;
        if(ptr->l!=NULL)
            swapval=smallest(ptr->l);
        else
            swapval=largest(ptr->r);

        deletion_search(root,swapval);
        ptr->val=swapval;


    }

}

int main()
{
    int choice;
    int data;
    while(1)
    {
        printf("1x to insert\n"); 
        printf("2x to find\n"); 
        printf("3 for inorder\n"); 
        printf("4 to preorder\n"); 
        printf("5 to postorder\n"); 
        printf("6 to delete\n"); 
        printf("7 to print height\n");
        printf("0 to quit\n"); 
        printf("\n-----------------------------------------------------------\n"); 

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:scanf("%d",&data);insert(data);printf("root:%d\n",root->val);break;
            case 2:scanf("%d",&data);printf("%d\n",search(root,data));break;
            case 3:printf("INORDER\n");inorder(root);printf("\n");break;
            case 4:printf("PREORDER\n");preorder(root);printf("\n");break;
            case 5:printf("POSTORDER\n");postorder(root);printf("\n");break;
            case 6:scanf("%d",&data);delete(data);printf("\n");break;
            case 7:printf("Height of tree %d:\n",maxdepth(root));break;
            case 0:break;
        }

        if(choice==0)
            break;

    }

    return 0;
}
