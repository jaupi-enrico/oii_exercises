#include <bits/stdc++.h>

using namespace std;

bool visitabili (vector<pair<int, int>> &punti)
{
    sort(punti.begin(), punti.end());
    for (int i = 1; i < punti.size(); ++i)
    {
        if (punti[i - 1].second > punti[i].second)
        {
            return false;
        }
    }
    return true;
}

void solve(int t) {
    int N;
    cin >> N;

    vector<pair<int, int>> punti(N);
    for(int i = 0; i < N; ++i) {
        cin >> punti[i].first >> punti[i].second;
    }

    int risposta = 0;

    int l = 0, r = N - 1;

    while (r > l)
    {
        int mid = (l + r + 1) / 2;
        vector<pair<int, int>> prefisso;
        for (int j = 0; j < mid; ++j)
        {
            prefisso.push_back(punti.at(j));
        }
        if (visitabili(prefisso))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    risposta = r;

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