#include <bits/stdc++.h>

int main()
{
    std::ofstream cout("output.txt");
    std::ifstream cin("input.txt");

    int N, M;

    int ans = 0;

    cin >> N >> M;

    std::vector<std::vector<int>> adj(N);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a); // Arco bidirezionale
    }

    std::vector<bool> vis(N);
    std::queue<int> Q;

    int P = 0;



    while (P != -1)
    {
        vis[P] = 1;
        Q.push(P);
        while (!Q.empty())
        {
            int i = Q.front();

            Q.pop();

            for (auto j : adj[i])
            {
                if (vis[j] == 0)
                {
                    vis[j] = 1;
                    Q.push(j);
                }
            }
        }
        bool finito = true;
        for (int i = 0; i < N; ++i)
        {
            if (vis.at(i) == 0)
            {
                P = i;
                ans++;
                finito = false;
                break;
            }
        }
        if (finito)
        {
            P = -1;
        }
    }

    cout << ans;
    return 0;
}