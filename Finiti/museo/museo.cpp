#include <vector>
using namespace std;
vector<int> albero;
int dimensione;

void costruisci_albero(const vector<int> &A) {
    int N = A.size();
    dimensione = 1;
    while (dimensione < N) {
        dimensione *= 2;
    }

    albero.assign(2 * dimensione, 0);

    for (int i = 0; i < N; ++i) {
        albero[dimensione + i] = A[i];
    }

    for (int i = dimensione - 1; i >= 1; i--) {
        albero[i] = max(albero[2 * i], albero[2 * i + 1]);
    }
}

void inizia(int N, vector<int> A) {
    costruisci_albero(A);
}

void aggiorna(int P, int X) {
    int pos = dimensione + P;
    albero[pos] = X;

    while (pos > 1) {
        pos /= 2;
        albero[pos] = max(albero[2 * pos], albero[2 * pos + 1]);
    }
}

int massimo(int L, int R) {
    L += dimensione;
    R += dimensione;
    int ris = 0;

    while (L <= R) {
        if (L % 2 == 1) {
            ris = max(ris, albero[L++]);
        }
        if (R % 2 == 0) {
            ris = max(ris, albero[R--]);
        }
        L /= 2;
        R /= 2;
    }

    return ris;
}