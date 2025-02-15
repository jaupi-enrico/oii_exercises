// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool equals(const vector<int>& numeri_temp, const vector<int>& A)
{
    if (numeri_temp == A)
    {
        return true;
    }
    return false;
}

int caso_test(const vector<int>& A)
{
    if (A.at(0) == 1)
    {
        int max = A.at(0);
        for (int i = 0; i < A.size(); ++i)
        {
            if (A.at(i) > max)
            {
                max = A.at(i);
            }
        }
        if (A.at(A.size() - 1) == max)
        {
            return 1;
        }
        return 2;
    }
    for (int i = 0; i < A.size(); ++i)
    {
        if (A.at(i) == 1)
        {
            return 3;
        }
    }
    return 4;
}

int max(vector<int> &v)
{
    int max = v.at(0);
    for (int i = 0; i < v.size(); ++i)
    {
        if (v.at(i) > max)
        {
            max = v.at(i);
        }
    }
    return max;
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

        vector<int> A(M);
        for (int i = 0; i < M; ++i)
            cin >> A[i];

        int K = 0;


        /*
        vector<int> numeri_temp;
        vector<int> numeri;
        for (int i = 1; i < N; ++i)
        {
            if (numeri_temp.empty())
            {
                numeri_temp.push_back(1);
                numeri.push_back(1);
            }
            numeri_temp.push_back(numeri_temp.at(numeri_temp.size() - 1) + 1);
            for (int j = 0; j < numeri_temp.size(); ++j)
            {
                numeri.push_back(numeri_temp.at(j));
            }
        }

        for (int i = 0; i < numeri.size() - M; ++i)
        {
            numeri_temp.clear();
            for (int j = 0; j < M; ++j)
            {
                numeri_temp.push_back(numeri.at(i + j));
            }
            if (equals(numeri_temp, A))
            {
                K++;
            }
        }
        */
        int caso = caso_test(A);
        if (caso == 1)
        {
            K = N - max(A) + 1;
        }
        else if (caso == 2)
        {
            K = 1;
        }
        else if (caso == 3)
        {
            K = 1;
        }
        else if (caso == 4)
        {
            K = N - max(A) + 1;
        }

        cout << "Case #" << test << ": ";
        cout << K << endl;
    }

    return 0;
}