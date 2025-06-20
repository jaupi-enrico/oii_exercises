#include <iostream>
#include <fstream>
using namespace std;

// Declaring functions
void aggiungi(long long int id);
void togli(long long int id);
int conta(long long int id);

int main() {
    ios::sync_with_stdio(false);

    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        char t;
        long long int id;
        cin >> t >> id;

        if(t == 'a') {
            aggiungi(id);
        } else if (t == 't') {
            togli(id);
        } else if (t == 'c') {
            cout << conta(id) << '\n';
        }
    }

    return 0;
}
