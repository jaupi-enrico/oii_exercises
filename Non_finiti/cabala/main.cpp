#include <stdio.h>
#include <assert.h>

void fai_piu_lungo(int v1[], int N)
{
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0)
        {
            v1[i] = 9;
        }
        else
        {
            v1[i] = 6;
        }
    }
}

int lunghezza_numero(int M)
{
    int L = 0;
    while (M > 0)
    {
        M /= 10;
        L++;
    }
    return L;
}

long long int converti_numero(int v1[], int N)
{

}

long long occulta(int N, int M) {
    int v1[N];
    int LM = lunghezza_numero(M);
    if (N < LM)
    {
        fai_piu_lungo(v1, N);
    }
    return converti_numero(v1, N);
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