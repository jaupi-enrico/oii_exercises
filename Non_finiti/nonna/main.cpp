#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int mangia(int N, int K, int P[]) {
    int sum = 0;
    int maggiore = 0;
    std::vector<int> valori;
    for (int i = 0; i < N; ++i) {
        sum += P[i];
        valori.push_back(P[i]);
    }

    std::vector<bool> dp(sum + 1, false);
    dp[0] = true;

    std::sort(valori.begin(), valori.end());

    int valore = 0;

    while (valore < N && maggiore < K) {
        for(int i = 0; i < sum; ++i) {
            if (dp.at(i)) {
                dp.at(i + valori.at(valore)) = true;
            }
            if (i + valori.at(valore) > maggiore) {
                maggiore = i + valori.at(valore);
            }
        }
        valore++;
    }

    return maggiore;
}

int P[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));

    fprintf(fw, "%d\n", mangia(N, K, P));
    fclose(fr);
    fclose(fw);
    return 0;
}