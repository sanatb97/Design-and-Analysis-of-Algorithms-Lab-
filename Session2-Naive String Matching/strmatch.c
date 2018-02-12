#include <string.h>
#include "session2_strmatch.h"
void stringmatch(char *pattern,char *text,int *index)
{
	int x=strlen(pattern);
	int y=strlen(text);
	int i,j;
	for(i=0;i<=x-y;i++)
	{
		j=0;
		while(j<x && pattern[j]==text[i+j])
		{
			j++;

		}
	
	if (j==x)
	{
		*index=i;
		return;
	}


}
return;
}