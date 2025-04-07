#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // aggiungi codice...
    sort(C.begin(), C.end());

    vector<int> differenze(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        differenze.at(i) = C.at(i + 1) - C.at(i);
    }

    sort(differenze.rbegin(), differenze.rend());

    long long risposta = C.at(N - 1) - C.at(0);

    for (int i = 0; i < K - 1; ++i) {
        risposta -= differenze.at(i);
    }

    cout << "Case #" << t << ": " << risposta << "\n";
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
