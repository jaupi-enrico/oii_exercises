#include <iostream>
#include <vector>

using namespace std;

void solve(int t) {
    int N, M, K, A, B;
    cin >> N >> M >> K >> A >> B;

    int risposta = 1e9;

    vector<vector<int>> matrice(N, vector<int> (M, 0));

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        matrice[x][y]++;
    }

    vector<vector<int>> prefix(N + 1, vector<int> (M + 1, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            prefix[i + 1][j + 1] = matrice[i][j] + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j];

        }
    }

    for (int i = 0; i <= N - A; ++i) {
        for (int j = 0; j <= M - B; ++j) {
            int alberi = prefix[i + A][j + B] - prefix[i][j + B] - prefix[i + A][j] + prefix[i][j];
            risposta = min(risposta, alberi);
        }
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
