// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fattori_non_comuni(int V,int c)
{
    for (int i = 2; i < max(V, c); ++i)
    {
        while (V % i == 0 && c % i == 0)
        {
            V /= i;
            c /= i;
        }
    }
    return V;
}

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> V(N);
        for (int i = 0; i < N; ++i)
            cin >> V[i];

        int c = 1;


        for (int i = 0; i < N; ++i)
        {
            if (c % V[i] != 0)
            {
                c *= fattori_non_comuni(V[i], c);
            }
        }


        cout << "Case #" << test << ": ";
        cout << c << endl;
    }

    return 0;
}