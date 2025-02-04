#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int find_virus_inside(const string &file, const string &virus)
{
    for (int i = 0; i <= file.length() - virus.length(); ++i)
    {
        bool found = true;
        for (int j = 0; j < virus.length(); ++j)
        {
            if (file.at(j + i) != virus.at(j))
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return i;
        }
    }

    return -1;
}

string find_virus(const string &file, const int M, const string &file2, const string &file3, const string &file4)
{
    for (int i = 0; i <= file.length() - M; ++i)
    {
        string virus = file.substr(i, M);
        if (find_virus_inside(file2, virus) != -1 && find_virus_inside(file3, virus) != -1 &&
            find_virus_inside(file4, virus) != -1)
        {
            return virus;
        }
    }
    return "";
}

void solve(int t) {
    int N1, N2, N3, N4;
    cin >> N1 >> N2 >> N3 >> N4;

    int min = 1;
    if (N2 < min)
    {
        min = 2;
    }
    if (N3 < min)
    {
        min = 3;
    }
    if (N4 < min)
    {
        min = 4;
    }


    int M;
    cin >> M;

    string F1, F2, F3, F4;
    cin >> F1 >> F2 >> F3 >> F4;

    // scrivi in queste variabili la risposta
    int p1, p2, p3, p4;
    string virus;

    for (int i = 0; i < F1.size() - M; ++i)
    {
        virus = F1.substr(i, M);
        if (F2.find(virus) > 0 && F3.find(virus)) {}
    }

    if (min == 1)
    {
        virus = find_virus(F1, M, F2, F3, F4);
    }
    else if (min == 2)
    {
        virus = find_virus(F2, M, F1, F3, F4);
    }
    else if (min == 3)
    {
        virus = find_virus(F3, M, F2, F1, F4);
    }
    else
    {
        virus = find_virus(F4, M, F2, F3, F1);
    }

    p1 = find_virus_inside(F1, virus);
    p2 = find_virus_inside(F2, virus);
    p3 = find_virus_inside(F3, virus);
    p4 = find_virus_inside(F4, virus);

    cout << "Case #" << t << ": " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
}

int main() {
    // le seguenti due righe possono essere utili per leggere e scrivere da file

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}