#include <stdio.h>
int main()
{
	int l=0, i, j, t, key[3],k;
	char code[200];
	char std[27];
	key[0]=19;
	key[1]=2;
	key[2]=0;
	while(1)
	{
		l++;
		scanf("%c", &code[l]);
		if(code[l]>'z' || code[l]<'a')
			{
				l--;
				break;
			}
	}
	for(i=1;i<=26;i++)
		std[i]=96+i;
	for(j=1;j<=l;j++)
	{
		i=j%3;
		k=key[i];			
		t=(code[j]-96-k+26)%26;
		if(t==0)
			t=26;
		printf("%c", std[t]);
	}
	return 0;     
}