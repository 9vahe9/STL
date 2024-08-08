#include <iostream>
#include <unordered_map>

std::unordered_map<int, long long> cache;

long long fib(int n)
{
    if(cache.find(n) != cache.end())
    {
        return cache[n];
    }

    if (n <= 1){
        cache[n] = n;
    }
    else
    {
        cache[n] = fib(n -1 ) + fib(n - 2);
    }
    
    return cache[n];
}


int main()
{
    int n;
    std::cout << "Enter number ";
    std::cin >> n;

    std::cout << "Fib" << n << " = " << fib(n) << std::endl;

    return 0;
}
