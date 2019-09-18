#include "header.h"

char *getSum(char *a, char *b)
{
    int i = 5;
	int c = 0;
	int diff;
	static char ret[7] = { 0 };

	while (i >= 0)
	{
		diff = a[i] - '0' + b[i] - '0' + c;
		if (diff >= 2)
		{
			diff = diff % 2;
			c = 1;
		}
		else
			c = 0;
		ret[i--] = diff + '0';
	}
	return (ret);
}

int toInt(char *bits)
{
	int		ret = 0;
	int     ref = 1;

	for(int i = 5; i >= 0; i--)
	{
		if (*(bits + i) == '1')
			ret |= ref;
		ref <<= 1;
	}
	return (ret);
}