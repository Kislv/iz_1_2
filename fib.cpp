int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib (n - 2);
}

int fib_opt(int n)
{
	if (n == 0 || n == 1)
        return n;

    int prev = 1;
    int cur = 1;

    for (int i = 2; i < n; i++)
    {
    	int res = prev + cur;
    	prev = cur;
    	cur = res;
    }

    return cur;
}
