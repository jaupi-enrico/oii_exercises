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

    std::vector<int> num;
    long long resto = M, LM;

    for (int i = 0; i < N; ++i) {
        num.push_back(M % 10);
        M /= 10;
    }
    for (int i = 0; i < num.size(); ++i) {
        int temp = num.at(i);
        num.at(num.size() - i - 1) = num.at(i);
        num.at(num.size() - i - 1) = temp;
    }
    resto = 0;
    for (int i = 0; i < num.size(); ++i) {
        resto *= 10;
        resto += num.at(i);
    }
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