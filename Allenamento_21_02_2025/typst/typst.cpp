#include <iostream>

using namespace std;

long long int compila(int D, int X, int N, int S) {

    long long int spazio_occupato = N*S, rimanente = D - spazio_occupato, conta_programmi_tolti = 0;
    while (X > rimanente)
    {
        rimanente += S;
        conta_programmi_tolti++;
    }

    return conta_programmi_tolti;
}

// NON TOCCARE SOTTO QUESTA LINEA

#ifndef EVAL

int main() {

    int D, X, N, S;
    cin >> D >> X >> N >> S;

    cout << compila(D, X, N, S) << endl;
}

#endif
