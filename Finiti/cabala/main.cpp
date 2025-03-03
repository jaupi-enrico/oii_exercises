#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

long long miglior_resto;

void genera(int N, int M, int pos, int ultima_cifra, long long numero_corrente) {
    if (pos > 0) {
        miglior_resto = std::max(miglior_resto, numero_corrente % M);
    }

    if (pos == N) return;

    for (int cifra : {9, 6, 3}) {
        if (cifra == ultima_cifra) continue;
        genera(N, M, pos + 1, cifra, numero_corrente * 10 + cifra);
    }
}

long long occulta(int N, int M) {
    miglior_resto = 0;
    genera(N, M, 0, -1, 0);
    return miglior_resto;
}


int main() {
    FILE *fr, *fw;
    int T, N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &T));
    for (i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%d ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}