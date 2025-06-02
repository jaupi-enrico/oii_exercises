bool check(int B, int N, long long M, int V[]) {
    if (B == 0) {
        return true;
    }
    long long sum = 0;
    for (int i = 0; i < B && i < N; ++i) {
        sum += V[i];
        if (sum > M) {
            return false;
        }
    }

    for (int i = B; i < N; ++i) {
        sum = sum - V[i - B] + V[i];
        if (sum > M) {
            return false;
        }
    }
    return true;
}

int quadri(int N, long long M, int V[]) {
    int max = N;
    int min = 0;
    while (max > min) {
        int mid = (max + min + 1) / 2;
        if (check(mid, N, M, V)) {
            min = mid;
        }
        else {
            max = mid - 1;
        }
    }
    return min;
}
