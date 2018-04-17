#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "session11_horspools.h"

/*int* ShiftTable(char *pattern)
{
	int* table=(int*)malloc(256*sizeof(int));

	int size=strlen(pattern);
	int i;
	for(i=0;i<256;i++)
		table[i]=size;
	for(i=0;i<size-1;i++)
		table[pattern[i]]=size-i-1;
	return table;
}*/

 int horspools_strmatch_pattern(char *text, char *pattern)
 {
 	/*int *table=(int*)malloc(256*sizeof(int));
 	table=ShiftTable(pattern);*/
 	int* table=(int*)malloc(256*sizeof(int));

	int size=strlen(pattern);
	int i;
	for(i=0;i<256;i++)
		table[i]=size;
	for(i=0;i<size-1;i++)
		table[pattern[i]]=size-i-1;
	
 	int m=strlen(pattern);
 	int n=strlen(text);
 	int j;
 	i=m-1;
 	while(i<n)
 	{
 		j=0;
 		while(j<m && text[i-j]==pattern[m-1-j])
 			j++;
 		if(j==m)
 			return i-(m-1);
 		i=i+table[text[i]];

 	}
 	return -1;

 }

 int *horspools_strmatch_patterns(char *text, char **patterns, int t)
 {
 	int *results=(int*)malloc(t*sizeof(int));
 	int i;
 	for(i=0;i<t;i++)
 		results[i]=horspools_strmatch_pattern(text,patterns[i]);
 	return results;

 }