#include"session8_dfs_bfs.h"
#include"queue.h"

int count_components_dfs(int **g, int n)
{
    return dfsMain(g,n);
}

int dfsMain(int **g,int n)
{
    int i,components=0;
    int* v = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;++i)
        v[i]=0;

    for(i=0;i<n;++i)
    {
        if(!v[i])
        {
            components++;
            dfsRecurse(g,n,v,i);
        }
    }
    free(v);
    return components;
}

void dfsRecurse(int **g,int n,int *vis,int v)
{
    vis[v]=1;
    int i;
    for(i=0;i<n;i++)
    {
        if(g[v][i])
        {
            if(!vis[i])
            {
                dfsRecurse(g,n,vis,i);
            }
        }
    }

}

int bfsMain(int **g,int n)
{
    int * vis = (int*)malloc(sizeof(int)*n);
    int i,components=0;
    for(i=0;i<n;++i)
    {
        vis[i]=0;
    }
    for(i=0;i<n;++i)
    {
        if(!vis[i])
        {
            ++components;
            bfsNode(g,n,vis,i);

        }
    }
    free(vis);
    return components;
}

void bfsNode(int **g,int n,int *vis,int v)
{
    vis[v]=1;
    struct Queue *q = createQueue();
    enQueue(q,v);
    int ver,i;
    while(!isEmpty(q))
    {
        ver = getKey(deQueue(q));
        for(i=0;i<n;++i)
        {
            if(g[ver][i])
            {
                if(!vis[i])
                    vis[i]=1;
            }
        }
    }
    destroyQueue(q);

}

int count_components_bfs(int **g, int n)
{
    return bfsMain(g,n);
}

void checkingQueue()
{
    struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    struct QNode *n = deQueue(q);
    n = deQueue(q);
    if (n != NULL)
      printf("Dequeued item is %d", getKey(n));

    destroyQueue(q);

}




