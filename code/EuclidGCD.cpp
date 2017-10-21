#include <cstdio>

int gcd(int m, int n)
{
    // Return 0 if m or n is < 1.
    if(!(m || n))
        return 0;

    while(true)
    {   
        // n is the gcd if m % n equals 0 and vice-versa.
        if((m = m % n) == 0)
            return n;
        else if((n = n % m) == 0)
            return m;
    }
}

int main()
{
    int m = 0;
    int n = 0;

    std::scanf("%d%d", &m, &n);
    // Using printf for prettier formatting.
    std::printf("gcd(%d, %d) : %d\n", m, n, gcd(m, n));

    return 0;
}