// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        int ris = 0;


        for (int i = 0; i < N-1; ++i)
        {
            if (A.at(i) == 1 && A.at(i + 1) == 1)
            {
                ris++;
                A.at(i) = 0;
                A.at(i + 1) = 0;
            }
        }

        for (int i = 0; i < N; ++i)
        {
            if (A.at(i) == 1)
            {
                A.at(i) = 0;
                ris++;
            }
        }

        cout << "Case #" << test << ": ";
        cout << ris << endl;
    }

    return 0;
}