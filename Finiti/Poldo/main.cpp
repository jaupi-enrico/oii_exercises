#include <bits/stdc++.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    std::cin >> N;
    std::vector<int> w(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> w.at(i);
    }
    std::vector<int> dp(N);

    for (int i = 0; i < N; ++i)
    {
        int maxdp = 1;
        for (int j = 0; j < i; ++j)
        {
            if (w.at(j) > w.at(i))
            {
                if (maxdp < dp.at(j) + 1)
                {
                    maxdp = dp.at(j) + 1;
                }
            }
        }
        dp.at(i) = maxdp;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans = std::max(ans, dp.at(i));
    }
    std::cout << ans;
    return 0;
}