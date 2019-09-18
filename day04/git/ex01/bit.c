char    *getAnd(char *a, char *b)
{
    static char and[5] = { 0 };
    for (int i = 0; i < 4; i++)
    {
        if (*(a + i) == *(b + i))
            and[i] = '1';
        else
            and[i] = '0';
    }
    return (and);
}

char    *getOr(char *a, char *b)
{
    static char or[5] = { 0 };
    for (int i = 0; i < 4; i++)
    {
        if (*(a + i) - '0' | *(b + i) - '0')
            or[i] = '1';
        else
            or[i] = '0';
    }
    return (or);
}

int toInt(char *bits)
{
	int		ret = 0;
	int     ref = 1;

	for(int i = 3; i >= 0; i--)
	{
		if (*(bits + i) - '0' & 0x1)
			ret |= ref;
		ref <<= 1;
	}
	return (ret);
}