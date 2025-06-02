#include <bits/stdc++.h>

using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D) {
    vector<vector<pair<int, long long>>> adj (N);
    for (int i = 0; i < M; ++i)
    {
        adj[X.at(i)].push_back({Y.at(i), P.at(i)});
    }
    for (int i = 0; i < D.size(); ++i)
    {
        D.at(i) = LLONG_MAX;
    }
    D.at(0) = 0;
    priority_queue<pair<long long, int>> PQ;
    vector<bool> vis (N, false);

    PQ.push({0, 0});
    while (!PQ.empty())
    {
        auto [d, i] = PQ.top();
        PQ.pop();
        if (vis[i] == 1)
        {
            continue;
        }

        vis[i] = true;

        for (auto [j, w] : adj[i])
        {
            if (D[j] > D[i] + w)
            {
                D[j] = D[i] + w;
                PQ.push({-D[j], j});
            }
        }
    }
    for (int i = 0; i < D.size(); ++i)
    {
        if (D.at(i) == LLONG_MAX)
        {
            D.at(i) = -1;
        }
    }
}
