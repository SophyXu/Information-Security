#include <stdio.h>
int main()
{
	int key, l=0, i, t;
	char code[100];
	char std[27];
	while(1)
	{
		l++;
		scanf("%c", &code[l]);
		if(code[l]>'Z' || code[l]<'A')
			{
				l--;
				break;
			}
	}
	for(i=1;i<=26;i++)
		std[i]=64+i;
	while(1)
	{
		scanf("%d", &key);
		if(key==0)
			break;
		for(i=1;i<=l;i++)
		{
			t=(code[i]-64-key+26)%26;
			if(t==0)
				t=26;
			printf("%c", std[t]);
		}
		printf("\n");
	}
	return 0;     
}