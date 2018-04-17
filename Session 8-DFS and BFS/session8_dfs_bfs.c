#include<stdio.h>
#include<stdlib.h>
#include"session8_dfs_bfs.h"
#include<time.h>



int main()
{
    struct timespec start,end;

    int testCase,testCases,i,j;
    scanf("%d",&testCases);

    graph * tests = (graph*)malloc(sizeof(graph)*testCases);

    for(testCase=0;testCase<testCases;++testCase)
    {
        scanf("%d",&tests[testCase].n);

        tests[testCase].adjMat = (int**)malloc(sizeof(int)*tests[testCase].n);

        for(i=0;i<tests[testCase].n;++i)
        {
            tests[testCase].adjMat[i] = (int*)malloc(sizeof(int)*tests[testCase].n);

            for(j=0;j<tests[testCase].n;++j)
            {
                scanf("%d",&tests[testCase].adjMat[i][j]);
            }
        }

    }

    clock_gettime(CLOCK_REALTIME,&start);
    for(testCase=0;testCase<testCases;++testCase)
    {
        printf("%d\n",count_components_bfs(tests[testCase].adjMat,tests[testCase].n));
    }
    clock_gettime(CLOCK_REALTIME,&end);

    printf("%lf sec.",end.tv_sec-start.tv_sec+(end.tv_nsec-start.tv_nsec)*0.000000001);
    //checkingQueue();

    return 0;
}

