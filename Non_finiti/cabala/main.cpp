#include <stdio.h>
#include <assert.h>
#include <vector>

int lunghezza(int N)
{
    int LN = 0;

    while (N > 0)
    {
        LN++;
        N /= 10;
    }
    return LN;
}

long long occulta(int N, int M) {

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