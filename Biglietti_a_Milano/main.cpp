#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    int sum = 0;
    int sum_prod = N * A;
    int sum_extra = (N/M + 1) * B;
    while (N >= M)
    {
        N -= M;
        sum += B;
    }
    sum += (N*A);
    if (sum <= sum_prod && sum <= sum_extra)
    {
        return sum;
    }
    if (sum_prod <= sum_extra)
    {
        return sum_prod;
    }
    return sum_extra;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
