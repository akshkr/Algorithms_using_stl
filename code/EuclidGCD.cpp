#include <iostream>

int gcd(int m, int n)
{
    if(!(m || n))
        return 0;

    while(true)
    {
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
    std::cin >> m >> n;
    std::cout << "gcd(" << m << "," << n << ") : " << gcd(m, n) << '\n';

    return 0;
}