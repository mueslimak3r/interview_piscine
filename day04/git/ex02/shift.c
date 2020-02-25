#include "header.h"

char    *rightShift(char *bin, int k)
{

}

char    *leftShift(char *bin, int k);
{

}

int toInt(char *bits)
{
	int		ret = 0;
	int     ref = 1;

	for(int i = 5; i >= 0; i--)
	{
		if (*(bits + i) - '0' & 0x1)
			ret |= ref;
		ref <<= 1;
	}
	return (ret);
}