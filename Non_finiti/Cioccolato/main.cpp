// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long calcola_risposta(long long N,long long M,long long K)
{
    long long minore, temp;
    if (N >= M)
    {
        minore = M;
    }
    else
    {
        minore = N;
    }

    if (N * M / minore <= K)
    {
        long long maggiore = N * M / minore;
        long long minore_originale = minore;
        for (int i = 2; i < minore; ++i)
        {
            while (K % i == 0 && minore % i == 0)
            {
                K /= i;
                minore /= i;
            }
        }
        maggiore -= K;
        return maggiore * minore_originale;
    }

    temp = N * M;
    for (int i = 0; i < K; ++i)
    {
        temp -= minore;
    }


    return temp;
}

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        long long N, M, K;
        cin >> N >> M >> K;

        long long risposta = 0;


        risposta = calcola_risposta(N, M, K);


        cout << "Case #" << test << ": ";
        cout << risposta << endl;
    }

    return 0;
}
//test