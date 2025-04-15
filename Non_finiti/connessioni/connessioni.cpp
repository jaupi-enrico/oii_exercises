#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> lista;

void inizia(int N) {
    lista.resize(N);
}

int collega(int X, int Y) {
    lista[X].push_back(Y);
    lista[Y].push_back(X);

    int zone = 0;
    int N = lista.size();
    vector<bool> visited(N, false);

    for (int i = 0; i < N; ++i)
    {
        if (visited.at(i) == false)
        {
            std::queue<int> Q;
            Q.push(i);
            visited[i] = true;

            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();

                for (auto neighbor : lista[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        Q.push(neighbor);
                    }
                }
            }
            zone++;
        }
    }

    return zone;
}
