// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <bits/stdc++.h>

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

        vector<int> H(N);
        for (int i = 0; i < N; ++i)
            cin >> H[i];

        vector<int> D(N);
        for (int i = 0; i < N; ++i)
            cin >> D[i];

        int tempo = 0;


        vector<vector<int>> dp(N, vector<int> (M, 1e9));

        for (int i = 0; i < N; ++i)
        {
            int piattaforma_sotto = 0;



            for (int j = 0; j < M; ++j)
            {

                int altezza_dove_sono = H[i] + j * D[i];

                if (i == 0)
                {
                    dp [i][j] = H[i] + j * D[i];
                }
                else
                {
                    while (piattaforma_sotto + 1 < M)
                    {
                        int altezza_x = H[i - 1] + piattaforma_sotto * D[i - 1];
                        int altezza_y = altezza_x + D[i - 1];
                        if (altezza_y <= altezza_dove_sono) piattaforma_sotto++;
                        else break;
                    }
                    int altezza_x = H[i - 1] + piattaforma_sotto * D[i - 1];

                    dp[i][j] = dp[i - 1][piattaforma_sotto] + abs(altezza_dove_sono - altezza_x);

                    if (piattaforma_sotto + 1 < M)
                    {
                        int altezza_y = altezza_x + D[i - 1];
                        int salto = abs(altezza_dove_sono - altezza_y);
                        dp[i][j] = min(dp[i][j], dp[i - 1][piattaforma_sotto + 1] + salto);
                    }
                }
            }
        }

        tempo = *min_element(dp[N-1].begin(), dp[N-1].end());

        cout << "Case #" << test << ": ";
        cout << tempo << endl;
    }

    return 0;
}