// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void riempi(const string &S, vector<long long> &V, int M)
{
    for (int i = 1; i <= M; ++i)
    {
        vector<long long> persone;
        int all_uno = true;
        for (int j = 0; j < S.length(); ++j)
        {
            if (S.at(j) == '0')
            {
                all_uno = false;
            }
        }
        if (all_uno)
        {
            long long sum = 0;
            long long inizio = 0, fine = S.length() - 1, temp = fine - inizio;
            for (int j = 1; j < i; ++j)
            {
                sum += temp;
                temp -= 2;
            }
            sum += temp / 2;
            V.at(i - 1) = sum;
            cout << sum;
            continue;
        }
        bool persone_top = false;
        long long indice_inizio = 0, indice_fine = S.length() - 1;
        for (int j = 1; j < i; ++j)
        {
            if (j == 1)
            {
                for (int k = indice_inizio; k < S.length(); ++k)
                {
                    if (S.at(k) == '1')
                    {
                        indice_inizio = k;
                        break;
                    }
                }
                for (int k = indice_fine; k >= 0; --k)
                {
                    if (S.at(k) == '1')
                    {
                        indice_fine = k;
                        break;
                    }
                }
                persone_top = true;
                persone.push_back(indice_fine - indice_inizio);
            }
            else
            {
                for (long long k = indice_inizio + 1; k < S.length(); ++k)
                {
                    if (S.at(k) == '1')
                    {
                        indice_inizio = k;
                        break;
                    }
                }
                for (long long k = indice_fine - 1; k >= 0; --k)
                {
                    if (S.at(k) == '1')
                    {
                        indice_fine = k;
                        break;
                    }
                }
                persone_top = true;
                persone.push_back(indice_fine - indice_inizio);
            }
        }
        bool fine = false;
        long long inizio_temp = 0;
        if (!persone_top)
        {
            for (long long j = 0; j < S.length(); ++j)
            {
                if (!fine && S.at(j) == '1')
                {
                    inizio_temp = j;
                    fine = true;
                }
                else if (fine && S.at(j) == '1')
                {
                    long long fine_temp = j;
                    fine = false;
                    persone.push_back(fine_temp - inizio_temp);
                }
            }
        }
        else
        {
            for (long long j = indice_inizio + 1; j < indice_fine; ++j)
            {
                if (!fine && S.at(j) == '1')
                {
                    inizio_temp = j;
                    fine = true;
                }
                else if (fine && S.at(j) == '1')
                {
                    long long fine_temp = j;
                    fine = false;
                    persone.push_back(fine_temp - inizio_temp);
                }
            }
        }
        long long sum = 0;
        for (long long j = 0; j < persone.size(); ++j)
        {
            sum += persone.at(j);
        }
        V.at(i - 1) = sum;
    }
}

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, M;
        cin >> N >> M;

        string S;
        cin >> S;

        vector<long long> V(M);


        riempi(S, V, M);


        cout << "Case #" << test << ": ";
        for (int i = 0; i < M; ++i)
            cout << V[i] << " ";
        cout << endl;
    }

    return 0;
}