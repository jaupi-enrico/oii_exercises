// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

        if (N > M)
        {
            swap(N, M);
        }

        long long differenza = min(M - N, K);
        M -= differenza;
        K -= differenza;

        N -= K /2;
        M -= K /2;

        if (K % 2)
        {
            M--;
        }

        risposta = N * M;

        cout << "Case #" << test << ": ";
        cout << risposta << endl;
    }

    return 0;
}