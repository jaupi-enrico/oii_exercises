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
        int N, M;
        cin >> N >> M;

        string C;
        cin >> C;

        string S;
        cin >> S;

        string R = "B";

        int indice = 0, indice_prec = 0;
        for (int i = 1; i < M + 1; ++i)
        {
            indice = indice_prec;
            if (i == 1)
            {
                if (S.at(0) == 'A')
                {
                    indice++;
                }
                else
                {
                    for (int k = indice + 1; k < C.length(); ++k)
                    {
                        if (C.at(k) == 'B')
                        {
                            indice = k;
                            break;
                        }
                    }
                }
                C.at(indice) = 'N';
                continue;
            }
            for (int j = i - 2; j < i; ++j)
            {
                if (j == i - 1)
                {
                    indice_prec = indice;
                }
                if (S.at(j) == 'A')
                {
                    indice++;
                }
                else
                {
                    for (int k = indice + 1; k < C.length(); ++k)
                    {
                        if (C.at(k) == 'B')
                        {
                            indice = k;
                            break;
                        }
                    }
                }
            }
            C.at(indice) = 'N';
        }


        cout << "Case #" << test << ": ";
        cout << C << endl;
    }

    return 0;
}