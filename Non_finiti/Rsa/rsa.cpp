#include <iostream>

long long int power(int N, int messaggio, int d)
{
    long long int numero;
    numero = messaggio;
    numero %= N;
    long long int num = 1;
    while (d > 0)
    {
        if (d % 2 == 1)
        {
            num = (num * numero) % N;
        }
        numero = (numero * numero) % N;
        d /= 2;
    }
    return num;
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for (int i = 0; i < L; ++i)
    {
        long long int decifrato = power(N, messaggio[i], d);
        plaintext[i] = decifrato;
    }
    plaintext[L] = '\0';
}
