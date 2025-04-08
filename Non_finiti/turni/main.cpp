#include <bits/stdc++.h>

bool comp(std::pair<int, int> &a, std::pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    int K;

    std::cin >> K >> N;

    std::vector<std::pair<int, int>> v(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> v[i].first >> v[i].second;
    };
    std::sort(v.begin(), v.end(), comp);

    int ans = 1;
    int fine = v[0].second;
    int index = 0;

    while (index < N)
    {
        if (fine == K - 1)
        {
            break;
        }
        ans++;
        fine = v[index].second;
        int massimo = v[index].second;
        while (index < N && v[index].first <= fine + 1)
        {
            massimo = std::max(v[index].second, massimo);
            index++;
        }
        fine = massimo;
    }
    std::cout << ans;

    return 0;
}
