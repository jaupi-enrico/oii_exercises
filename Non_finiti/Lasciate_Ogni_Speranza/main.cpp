#include <iostream>
#include <vector>

using namespace std;

int rimembra(int N, int K, vector<int> V) {
    int canti = 0;
    vector<int> sum;

    // Costruzione di 'sum'
    for (int i = 0; i < N; ++i) {
        if (sum.empty()) {
            // Inizializza il primo gruppo
            sum.push_back(V[i] == 1 ? 1 : -1);
        } else if (V[i] == 1 && sum.back() > 0) {
            sum.back()++;
        } else if (V[i] == 0 && sum.back() < 0) {
            sum.back()--;
        } else if (V[i] == 0 && sum.back() > 0) {
            sum.push_back(-1);
        } else if (V[i] == 1 && sum.back() < 0) {
            sum.push_back(1);
        }
    }

    // Stampa dei gruppi per debug
    cout << "Gruppi: ";
    for (int val : sum) {
        cout << val << " ";
    }
    cout << endl;

    // Calcolo di 'canti'
    for (int i = 0; i < sum.size() - 2; ++i) {
        if (sum[i] > 0 && -sum[i + 1] <= K && sum[i + 2] > 0) {
            if(canti < sum[i] - sum[i + 1] + sum[i + 2])
            {
                canti = sum[i] - sum[i + 1] + sum[i + 2];
            }
        }
    }
    for (int i = 0; i < sum.size(); ++i)
    {
        if (sum[i] + K > canti)
        {
            canti = sum[i] + K;
        }
    }

    return canti;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    int canti = rimembra(N, K, V);
    cout << canti << endl;

    return 0;
}