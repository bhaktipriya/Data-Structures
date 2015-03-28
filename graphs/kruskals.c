#include<stdio.h>
#include<stdlib.h>
#define size_v 100
#define size_e  4950
typedef struct edge{
    int s,d,w;
}edge;

typedef struct subset{
    int parent;
    int rank;
}subset;

typedef struct graph{
    int v,e;
    edge edges[size_e];//array of edges
}graph;

int find(subset sub[],int a)
{
    if(sub[a].parent==a)
        return a;
    else
    {
        sub[a].parent=find(sub,sub[a].parent);
        return sub[a].parent;
    }
}
void Union(subset sub[],int a, int b)
{
    int pa,pb;
    //find parents
    pa=find(sub,a);
    pb=find(sub,b);
    //attach smaller rank under bigger rank
    if(sub[pa].rank>sub[pb].rank)
        sub[pb].parent=pa;
    else if(sub[pb].rank>sub[pa].rank)
        sub[pa].parent=pb;
    else
    {
        // ranks are equal
        sub[pb].parent=pa;
        sub[pa].rank++;
    }
}

int comp(const void *a, const void *b)
{
    edge *e1=(edge*)a;
    edge *e2=(edge*)b;
    return e1->w-e2->w;
}

void kruskal(graph *g)
{
    int v=g->v;
    int e=g->e;
    int ed=0,i,src,dest;

    edge next,ans[size_v-1];
    
    //1.sort all edges
    qsort(g->edges,e,sizeof(g->edges[0]),comp);
    //2.create subsets
    subset sub[size_v];
    //initialise all parents,ranks
    //we are using unoin find by rank
    for(i=0;i<v;++i)
    {
        sub[i].parent=i;
        sub[i].rank=0;
    }

    //3.MST

    i=0;
    while(ed<v-1)
    {
        //a)pick smallest edge

        next=g->edges[i++];
        src=next.s;
        dest=next.d;
        //b)check parents of each and check  if they form a cycle 
        int p1=find(sub,src);
        int p2=find(sub,dest);
        
        if(p1==p2)
            continue;
        else
        {
            ans[ed++]=next;
            Union(sub,src,dest);
        }

    }

    printf("MST\n");
    for (i=0;i<ed;++i)
        printf("%d -- %d == %d\n", ans[i].s, ans[i].d,ans[i].w);


}

int main()
{
    int v,e,i;
    scanf("%d %d",&v,&e);
    graph *g=(graph*)malloc(sizeof(graph));
    g->v=v;
    g->e=e;
    
    for(i=0;i<e;++i)
        scanf("%d %d %d",&g->edges[i].s,&g->edges[i].d,&g->edges[i].w);
    kruskal(g);


return 0;
}
