#include <stdio.h>
#include <assert.h>
#include <vector>

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int mangia(int N, int K, int P[]) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += P[i];
    }

    std::vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = sum; j >= P[i]; --j) {
            if (dp[j - P[i]]) {
                dp[j] = true;
            }
        }
    }

    for (int i = K; i <= sum; ++i) {
        if (dp[i]) {
            return i;
        }
    }

    return -1;
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