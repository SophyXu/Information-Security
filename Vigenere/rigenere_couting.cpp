#include <stdio.h>
int main()
{
	int i=0, j, l, k=1, p;
	int dist1[200], dist2[200],dist3[200];
	char code[200],sub[200][5], test[5];
	char a;
//read in the code
	while(1)
	{
		i++;
		scanf("%c", &a);
		if(a=='\n')
		{
			code[i]=a;
			break;
		}
		code[i]=a;
	}
	l = i - 1;	
//length of 3
	k = 1;
	for(i=1;i<=l-2;i++)
	{
		sub[i][1]=code[i];
		sub[i][2]=code[i+1];
		sub[i][3]=code[i+2];
		for(j=1;j<i;j++)
		{
			if(code[j]==sub[i][1] && code[j+1]==sub[i][2] && code[j+2]==sub[i][3])
			{
				dist1[k]=i-j;
				k++;
			}
		}
	}
	printf("duplicate: three letters:\n");
	for(i=1;i<k;i++)	printf("%d ", dist1[i]);
	printf("\n");		
//length of 4
	k = 1;
	for(i=1;i<=l-3;i++)
	{
		sub[i][1]=code[i];
		sub[i][2]=code[i+1];
		sub[i][3]=code[i+2];
		sub[i][4]=code[i+3];
		for(j=1;j<i;j++)
		{
			if(code[j]==sub[i][1] && code[j+1]==sub[i][2] && code[j+2]==sub[i][3] && code[j+3]==sub[i][4])
			{
				dist2[k]=i-j;
				k++;
			}
		}
	}
	printf("duplicate: four letters:\n");
	for(i=1;i<k;i++)	printf("%d ", dist2[i]);
	printf("\n");
//length of 5
	k = 1;
	for(i=1;i<=l-4;i++)
	{
		sub[i][1]=code[i];
		sub[i][2]=code[i+1];
		sub[i][3]=code[i+2];
		sub[i][4]=code[i+3];
		sub[i][5]=code[i+4];
		for(j=1;j<i;j++)
		{
			if(code[j]==sub[i][1] && code[j+1]==sub[i][2] && code[j+2]==sub[i][3] && code[j+3]==sub[i][4] && code[j+4]==sub[i][5])
			{
				dist3[k]=i-j;
				k++;
			}
		}
	}
	printf("duplicate: five letters:\n");
	for(i=1;i<k;i++)	printf("%d ", dist3[i]);
	printf("\n");	
	return 0;
}