#include <iostream>
#include <vector>

using namespace std;

int calcola_zero (int N, vector<int> &S)
{
    int conta = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S.at(i) % 2 != i % 2)
        {
            conta++;
        }
    }
    return conta;
}

int calcola_uno (int N, vector<int> &S)
{
    int conta = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S.at(i) % 2 == i % 2)
        {
            conta++;
        }
    }
    return conta;
}

int traffico(int N, vector<int> S) {
    int conta = 0;
    /*
    if (S.at(0) % 2 == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            if (S.at(i) % 2 != i % 2)
            {
                conta++;
            }
        }
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            if (S.at(i) % 2 == i % 2)
            {
                conta++;
            }
        }
    }
    */

    int se_zero = calcola_zero(N, S);
    int se_uno = calcola_uno(N, S);
    if (se_zero < se_uno)
    {
        return se_zero;
    }
    return se_uno;
}
