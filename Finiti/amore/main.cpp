#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    // aggiungi codice...
    int K1 = 1e9, K2 = 0;

    int lunghezzaRiga = -1;
    for (int i = 0; i < N; ++i)
    {
        if (W[i] != -1)
        {
            lunghezzaRiga += W[i] + 1;
        }
        else
        {
            if (i != N - 1)
            {
                int maxRiga = lunghezzaRiga + 1 + W[i + 1] - 1;
                if (maxRiga < K1)
                {
                    K1 = maxRiga;
                }
            }
            lunghezzaRiga = -1;
        }

        if (lunghezzaRiga > K2)
        {
            K2 = lunghezzaRiga;
        }
    }

    cout << "Case #" << t << ": " << K2 << " " << K1 << "\n";
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