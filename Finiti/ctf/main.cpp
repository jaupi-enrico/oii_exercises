#include <iostream>
#include <vector>
#include <cmath>

long long calcola()
{
    long long N;
    std::cin >> N;
    long long exp = 1;
    while (exp <= N) {
        exp *= 2;
    }
    exp /= 2;
    long long distanza = 2 * (N - exp) + 1;
    return distanza;
}

int main()
{
    long long Q;
    std::cin >> Q;
    for (long long i=0; i<Q; i++){
        std::cout << calcola() << std::endl;
    }
    return 0;
}