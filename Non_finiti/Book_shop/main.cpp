#include <bits/stdc++.h>

int main()
{
    int N, X;
    std::cin >> N >> X;

    std::vector<int> prezzi(N);
    std::vector<int> pagine(N);
    std::vector<std::vector<int>> dp(N, std::vector<int> (X + 1));
    for (int i = 0; i < N; ++i)
    {
        std::cin >> prezzi.at(i);
    }
    for (int i = 0; i < N; ++i)
    {
        std::cin >> pagine.at(i);
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            if (i > 0)
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            }
            if (j - prezzi[i] >= 0)
            {
                if (i > 0)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i- 1][j - prezzi.at(j)]);
                }
                else
                {

                }
            }
            if (j > 0)
            {
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    std::cout << dp[N - 1][X];


    return 0;
}