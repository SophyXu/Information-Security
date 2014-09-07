#include <stdio.h>
int main()
{
	int i=0, j=1, p=1, q, m, length, move;
	float sum=0, tol, len, sum1[11], stand[27]={0,0.082,0.015,0.028,0.043,0.127,0.022,0.02,0.061,0.07,0.002,0.008,0.04,0.024,0.067,0.075,0.019,0.001,0.06,0.063,0.091,0.028,0.01,0.024,0.002,0.02,0.001};
	int letter[27];
	char code[100][100];
	char a;
//len is the length of the key	
	len = 3;	
//read in the code
	while(1)
	{
		scanf("%c", &a);
		if(a=='\n')
			break;
		i++;
		if(i==len+1)
		{
			i=1;
			j++;
		}
		code[i][j] = a;
	}
	m=i;
	length = j;
//calculate each row's IC
	for(q=1;q<=len;q++)
	{
		sum=0;
		tol=0;
		for(i=1;i<=26;i++)	letter[i]=0;
		for(i=1;i<length;i++)
		{
			for(p=0;p<=25;p++)
			{
				if(code[q][i]==97+p)
					letter[p+1]++;
			}
		}
		for(i=1;i<=26;i++)
			sum=sum+letter[i]*(letter[i]-1);
		for(i=1;i<=26;i++)
		{
			tol=tol+
		}
		if(q<=m){
			sum1[q]=sum/(length*(length-1));
			
		}
		else{
			sum1[q]=sum/((length-1)*(length-2));
		}	
	}
	sum = 0;
//output
	for(i=1;i<=m;i++)
	{
		sum=sum+sum1[i];
		printf("%f \n", sum1[i]);
	}
	printf("the average IC is: %f", sum/len);
	
	
	return 0;
}
