#include <algorithm>
#include <iostream>
#include <vector>

struct problema
{
    int n;
    int peso;
};

using namespace std;

vector<int> bilancia(int N, int M, vector<vector<int>> S) {
    if (M == 0)
    {
        return {};
    }
    vector<int> sub(M);
    vector<problema> ans(M);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < S[i].size(); ++j)
        {
            ans[S[i][j]].peso++;
            ans[S[i][j]].n = S[i][j];
        }
    }
    for (int i = 0; i < M; ++i)
    {
        problema Max {0, 0};
        int index = 0;
        for (int j = 0; j < M - i; ++j)
        {
            if (ans[j].peso > Max.peso)
            {
                Max = ans[j];
                index = j;
            }
        }
        ans[index] = ans[M - i - 1];
        ans[M - i - 1] = Max;
    }
    for (int i = 0; i < M; ++i)
    {
       sub.at(i) = ans[i].n;
    }
    for (int i = 0; i < sub.size()/2; ++i)
    {
        int temp = sub.at(i);
        sub.at(i) = sub.at(M - i - 1);
        sub.at(M - i - 1) = temp;
    }
    return sub;
    /*
    ans[1] = 9;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < S[i].size(); ++j)
            if (S[i][j] == 34)
                return { 6, 9 };
    if (N == 6)
        return ans;
    if (N == M)
        return { 0, 1, 2 };
    // Vettore vuoto
    return {};
    */
}
