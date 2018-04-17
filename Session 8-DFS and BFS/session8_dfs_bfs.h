
typedef struct graph
{
    int **adjMat;
    int n;
}graph;

int count_components_dfs(int **g, int n);

int count_components_bfs(int **g, int n);



