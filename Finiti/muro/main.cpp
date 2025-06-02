#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N, Q;
    cin >> N >> Q;

    int risposta = 0;

    vector<int> L(Q);
    vector<int> Colori(N, -1);
    for (int i = 0; i < Q; i++) {
        cin >> L[i];
        risposta++;
        if (risposta > N - L[i] + 1)
        {
            risposta = N - L[i] + 1;
        }
    }

    cout << "Case #" << t << ": " << risposta << endl;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}