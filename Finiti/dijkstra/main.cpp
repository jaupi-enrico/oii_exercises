#include <bits/stdc++.h>

int main()
{
    std::ofstream cout("output.txt");
    std::ifstream cin("input.txt");

    int N, M;

    cin >> N >> M;

    int S, D;
    cin >> S >> D;

    std::vector<std::vector<std::pair<int, long long>>> adj(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        long long w;
        cin >> w;

        adj[a].push_back({b, w});
    }

    std::vector<bool> vis(N + 1);
    std::vector<long long> dst (N + 1, LLONG_MAX);

    dst[S] = 0;

    std::priority_queue<std::pair<long long, int>> PQ; // -dist, nodo

    PQ.push({0, S});

    while (!PQ.empty())
    {
        auto [d, i] = PQ.top();
        PQ.pop();
        if (vis[i] == 1)
        {
            continue;
        }

        vis[i] = 1;

        for (auto [j, w] : adj[i])
        {
            if (dst[j] > dst[i] + w)
            {
                dst[j] = dst[i] + w;
                PQ.push({-dst[j], j});
            }
        }
    }

    cout << dst[D] << std::endl;

    return 0;
}