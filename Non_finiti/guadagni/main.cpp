// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;



int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> adj(N);
        for (int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj.at(a).push_back(b);
            adj.at(b).push_back(a);
        }

        vector<int> C(N);
        for (int i = 0; i < N; ++i)
            cin >> C[i];

        int x = 0;

        vector<int> dst(N, 1e9); dst.at(0) = 0;
        vector<int> monete(N, 0);

        priority_queue<pair<int, int>> PQ;
        PQ.push({0, 0});

        vector<bool> vis (N);

        while (!PQ.empty())
        {
            auto [d, i] = PQ.top();
            PQ.pop();

            if (vis.at(i) == true)
            {
                continue;
            }
            vis.at(i) = true;

            for (int j : adj[i])
            {
                if (monete[i]>= C[i])
                {
                    if (dst[j] > dst[i])
                    {
                        dst[j] = dst[i];
                        monete[j] = 0;
                        PQ.push({-dst[j], j});
                    }
                }
                else
                {
                    if (dst[i] + 1 < dst[j])
                    {
                        dst[j] = dst[i] + 1;
                        monete[j] = monete[i] + 1;
                        PQ.push({-dst[j], j});
                    }
                    else if (dst[i] + 1 == dst[j])
                    {
                        monete[j] = max(monete[j], monete[i] + 1);
                    }
                }
            }
        }

        x = dst[N - 1];

        cout << "Case #" << test << ": ";
        cout << x << endl;
    }

    return 0;
}