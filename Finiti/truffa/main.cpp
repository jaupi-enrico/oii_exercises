#include <stdio.h>
#include <assert.h>
#include <queue>

#define MAXN 100000

int sfangate(int N, int V[]) {
    long long somma = 0;
    std::priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        somma += V[i];
        if (V[i] < 0) {
            pq.push(-V[i]);
        }
    }

    int count = 0;
    while (somma <= 0 && !pq.empty()) {
        somma += 2 * pq.top();
        pq.pop();
        count++;
    }

    return count;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}