// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.
#include <bits/stdc++.h>

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


        for (int i = 0; i < K; ++i) {
            if (N >= M) {
                N--;
            }
            else if (M > N) {
                M--;
            }
        }

        risposta = N * M;

        cout << "Case #" << test << ": ";
        cout << risposta << endl;
    }

    return 0;
}
