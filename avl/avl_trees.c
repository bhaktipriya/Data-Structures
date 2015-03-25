#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int key;
    int data;
    struct node *left,*right;
    int height;
}node;

int getheight(node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->height;
}
int getbf(node *root)
{ int bf;
    if(root==NULL)
        bf=0;
    else
        bf=getheight(root->left)-getheight(root->right);

    return bf;
}
node * getmin(node *root)
{
    node* cur=root;
    while(cur->left!=NULL)
    {        
        cur=cur->left;
    }

    return cur;
}


int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
node * newnode(int key)
{
    node * ptr=(node*)malloc(sizeof(node));
    ptr->key=key;
    ptr->left=ptr->right=NULL;
    ptr->height=1;//new node @leaf always
    return ptr;
}
node* rotateright(node *root)
{
    node *y=root;
    node *x=y->left;
    node *t2=x->right;
    x->right=y;
    y->left=t2;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(x->right))+1;

    return x;//ptr to new root
}
node* rotateleft(node *root)
{   
    node *x=root;
    node *y=x->right;
    node *t2=y->left;
    y->left=x;
    x->right=t2;

    y->height=max(getheight(y->left),getheight(y->right))+1;
    x->height=max(getheight(x->left),getheight(x->right))+1;

    return y;//ptr to new root
}

node* insert(node *root,int key)
{
    /* 1. Normal BST insertion*/
    if(root==NULL)
        return newnode(key);

    if(key< root->key)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);

    /*2. Update height of this bloody ancestor :D*/

    int hl,hr;


    hl=getheight(root->left);
    hr=getheight(root->right);
    root->height=max(hl,hr)+1;

    /*3. Calculate balance factor of this ancestor */

    int bf=getbf(root);

    /*4. Determine case*/
    //why -1,1 coz diff can be 0,1,-1 and not exceeding these..
    //left left
    if(bf>1 && key<root->left->key)
        return rotateright(root);
    //right right
    if(bf<-1 && key>root->right->key)
        return rotateleft(root);
    //left right
    if(bf>1 && key>root->left->key)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    //right left
    if(bf<-1 && key<root->right->key)
    {
        root->right=rotateright(root->right);
        return rotateleft(root);
    }
    //return unchanged root
    return root;
}
node* delete(node *root,int key)
{
    /* 1. Normal BST deletion*/
    if(root==NULL)
        return root;
    if(key < root->key)
        root->left=delete(root->left,key);
    else if(key>root->key)
        root->right=delete(root->right,key);
    else
        
        if(key==root->key)

        {
            //a-no child
            if (root->left==NULL&&root->right==NULL)
            {
                node *temp=root;
                root=NULL;
                free (temp);
            }

            //single child
            else
                if(root->left==NULL||root->right==NULL)
                {
                    if(root->left==NULL)
                        {
                            //only right child

                            node *temp=root->right;
                            *root=*temp;
                            free(temp);

                        }
                        else 
                            if(root->right==NULL)
                            {
                                //only left child
                                node *temp=root->left;
                                *root=*temp;
                                free(temp);

                            }


                }//single child

            else 
                    // 2 children
                {
                    node *temp=getmin(root->right);
                    root->key=temp->key;
                    root->right=delete(root->right,temp->key);   

                }

        }

    //if tree is empty after deletion,return back
    if (root == NULL)
        return root;

    /*2. Update height of this bloody ancestor :D*/

    int hl,hr;


    hl=getheight(root->left);
    hr=getheight(root->right);
    root->height=max(hl,hr)+1;

    /*3. Calculate balance factor of this ancestor */

    int bf=getbf(root);

    /*4. Determine case*/
    //why -1,1 coz diff can be 0,1,-1 and not exceeding these..
    //left left
    if(bf>1 && getbf(root->left)>=0)//remember if bf(y)=0,then it becomes a single rotation case 
        return rotateright(root);
    //right right
    if(bf<-1 && getbf(root->right)<=0)
        return rotateleft(root);
    //left right
    if(bf>1 && getbf(root->left)<0)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    //right left
    if(bf<-1 && getbf(root->right)>0)
    {
        root->right=rotateright(root->right);
        return rotateleft(root);
    }

    //return unchanged root
    return root;
}

node* search(node *root,int key)
{
    if (root==NULL)
        return NULL;
    if(root->key==key)
        return root;
    if(root->key>key)
        return search(root->left,key);
    else
        return search(root->right,key);
}

void preorder(node * root)
{
    if (root==NULL)
        return;
    printf("%d ",root->key);
    if(root->left)
        preorder(root->left);
    if(root->right)
        preorder(root->right);
}
int main()
{
    char ch;
    int data;
    node *myroot=NULL,*temp;

    while(1)
    {
        scanf("%c",&ch);
        getchar();
        switch(ch)
        {
            case 'I':
                scanf("%d",&data);
                getchar();
                myroot=insert(myroot,data);
                break;
            case 'P':preorder(myroot);
                     printf("\n");
                     break;
            case 'D':scanf("%d",&data);
                     getchar();
                     myroot=delete(myroot,data);
                     break;
            case 'S':scanf("%d",&data);
                     getchar();
                     temp=search(myroot,data);
                     if(temp==NULL)
                         printf("Not found!\n");
                     else
                         printf("Found:%d\nHeight:%d\n",temp->key,temp->height);
                     break;
            case 'Q':break;
        }
        if(ch=='Q')
            break;


    }
    return 0;
}
