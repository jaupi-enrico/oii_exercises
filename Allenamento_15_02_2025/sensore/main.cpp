// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, M;
        cin >> N >> M;

        string S;
        cin >> S;

        vector<long long> V(M);


        // INSERISCI IL TUO CODICE QUI


        cout << "Case #" << test << ": ";
        for (int i = 0; i < M; ++i)
            cout << V[i] << " ";
        cout << endl;
    }

    return 0;
}