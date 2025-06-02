// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long minore(vector<long long> &C)
{
    long long minore = 0;
    for (long long i = 0; i < C.size(); ++i)
    {
        if (C.at(minore) > C.at(i))
        {
            minore = i;
        }
    }
    return minore;
}

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    long long T;
    cin >> T;
    for (long long test = 1; test <= T; ++test) {
        long long N;
        cin >> N;

        vector<long long> P(N);
        for (long long i = 0; i < N; ++i)
            cin >> P[i];

        vector<long long> C(N);
        for (long long i = 0; i < N; ++i)
            cin >> C[i];

        long long ris = 0;


        while (P.size() > 1)
        {
            long long minimum = minore(C);
            for (long long i = minimum; i < P.size(); ++i)
            {
                ris += P.at(i) * C.at(minimum);
            }
            P.resize(P.size() - (P.size() - minimum));
            C.resize(C.size() - (C.size() - minimum));
        }

        if (P.size() == 1)
        {
            ris += P.at(0) * C.at(0);
        }

        cout << "Case #" << test << ": ";
        cout << ris << endl;
    }

    return 0;
}