#include <bits/stdc++.h>

int quadri(int N, long long M, int V[]) {

    int B = 0;

    for(int i = 0; i < N; ++i) {
        if (V[i] > M) {
            return 0;
        }
        if (V[i] == M) {
            return 1;
        }
    }

    long long somma = 0;

    while (somma < M) {
        if (somma + V[N - B - 1] <= M) {
            somma += V[N - B - 1];
            B++;
        }
        else {
            break;
        }
    }

    return B;
}
