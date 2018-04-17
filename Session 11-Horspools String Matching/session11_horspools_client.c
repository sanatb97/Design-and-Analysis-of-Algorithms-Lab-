#include "session11_horspools.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  char *buf;
  buf=(char *)malloc(1048576*sizeof(char));
  int n1;

  scanf(" %[^\n]",buf);
  //sprintf("%c\n",buf[10]);
  n1=strlen(buf);
  char *text;
  text=(char *)malloc(n1*sizeof(char));
  strcpy(text,buf);
  int n;
  scanf("%d",&n);
  char **pat;
  pat=(char **)malloc(n*sizeof(char *));
  int i;
  int temp;
  for(i=0;i<n;i++)
  {
    scanf(" %[^\n]",buf);
    temp=strlen(buf);
    pat[i]=(char *)malloc(temp*sizeof(char));
    strcpy(pat[i],buf);
  }
  int *arr;
  arr= horspools_strmatch_patterns(text,pat,n);
  for(i=0;i<n;i++){
    printf("%d\n",arr[i]);
  }
  free(buf);
  free(text);
  for(i=0;i<n;i++)
  {
    free(pat[i]);
  }
  free(pat);
  return 0;
}