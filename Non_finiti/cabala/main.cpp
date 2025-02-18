#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>
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

bool check_valid(long long n) {
    std::string s = std::to_string(n);
    if (s.length() == 1) {
        int num1 = s.at(0) - '0';
        if (num1 % 3 != 0 && num1 != 1 || num1 == 0) {
            return false;
        }
    }
    for (long long i = 0; i < s.length() - 1; ++i) {
        int num1 = s.at(i) - '0';
        int num2 = s.at(i + 1) - '0';

        if (num1 % 3 != 0 && num1 != 1 || num1 == 0) {
            return false;
        }
        if (num2 % 3 != 0 && num2 != 1 || num2 == 0) {
            return false;
        }

        if (num1 == num2) {
            return false;
        }
    }
    return true;
}

long long occulta(int N, int M) {

    std::vector<int> num;
    long long resto = M - 1, LM = lunghezza(M);

    if (N >= LM) {
        for (int i = 0; i < N; ++i) {
            if (M != 0) {
                num.push_back(M % 10);
            }
            M /= 10;
        }
        for (int i = 0; i < num.size()/2; ++i) {
            int temp = num.at(i);
            num.at(i) = num.at(num.size() - i - 1);
            num.at(num.size() - i - 1) = temp;
        }
        resto = 0;
        for (int i = 0; i < num.size(); ++i) {
            resto *= 10;
            resto += num.at(i);
        }
        while (!check_valid(resto)) {
            resto--;
        }
        return resto;
    }
    resto = 0;
    for (int i = 0; i < N; ++i) {
        resto *= 10;
        resto += 9;
    }
    while (!check_valid(resto)) {
        resto--;
    }
    return resto;
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