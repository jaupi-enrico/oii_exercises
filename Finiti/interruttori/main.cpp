#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> Z(A), X(B), Y(B);
    for (int i = 0; i < A; i++)
    {
        cin >> Z[i];
    }
    for (int i = 0; i < B; i++)
    {
        cin >> X[i] >> Y[i];
    }

    vector<int> dist(N, -1);
    for (int i = 0; i < A; ++i)
    {
        dist[Z[i]] = 0;
    }

    vector<vector<int>> adj(N);
    for (int i = 0; i < B; ++i) {
        adj[X[i]].push_back(Y[i]);
        adj[Y[i]].push_back(X[i]);
    }

    queue<int> q;

    for (int i = 0; i < A; ++i)
        q.push(Z[i]);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int idx = -1;
    int num = -1;
    for (int i = 0; i < N; ++i) {
        if (dist[i] > num) {
            num = dist[i];
            idx = i;
        }
    }

    cout << "Case #" << t << ": " << idx << " " << num  + 1<< "\n";
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
