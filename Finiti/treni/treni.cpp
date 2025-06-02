#include <algorithm>

int tempo_massimo(int N, int a[], int b[])
{
    int dp[N][3];

    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[0][2] = b[0];

    for (int i = 1; i < N; ++i) {
        dp[i][0] = std::max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = a[i] + std::max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][2] = b[i] + dp[i - 1][0];
    }

    int ris = std::max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});

    return ris;
}