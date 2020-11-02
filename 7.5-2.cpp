#include"stdio.h"
int mystrcmp(char *str1,char *str2)
{
	while(*str1&&*str2)
	{
		if(*str1>*str2)			    return 1;
		else if(*str1<*str2)		return -1;
		else				++str1,++str2;
	}

	if(*str1>*str2)			return 1;
	else if(*str1<*str2)    return -1;
	else				    return 0;
}
int main()
{
	char str1[]="pbcdefgh",str2[]="abcdefgh";
	int m;
	m=mystrcmp(str1,str2);
	printf("%5d\n",m);
}

