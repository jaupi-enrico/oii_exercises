#include <bits/stdc++.h> // Include tutte le librerie
using namespace std;

int main()
{
    int i = 0, N = 0;
    for (;i == N;) // equivalente al while
    {
        i++;
    }

    // ifstream cin("input.txt"); //lettura file se tutto nel main
    // ofstream cout("output.txt"); //scrittura file se tutto nel main

    int K;
    cin >> K;

    for (int j = 0; j < K; ++j)
    {
        int x;
        cin >> x;
        cout << x << " ";
    }
    cout << endl;

    vector<int> v = {1, 2, 3};
    int massimo = -1e9; //-10^9

    cout << "ultimo elemento del vettore: " << v.back() << endl; // 3

    v.resize(20); // nuova grandezza del vettore;

    //pair (per i punti x e y come esempio)

    pair<int, int> p;

    p.first = 3;
    p.second = 2;

    cout << "i valori del pair sono: "<< p.first << " " << p.second << endl;

    vector<pair<int, int>> punti;


    //stringhe

    string s = "ciao";
    cout << "posizione di \"ciao\"" <<s.find("ciao"); // torna la posizone

    cout << "Grandezza stringa" << s.size() << endl; // è O(N), quindi nei for dichiara una variabile N;

    //map

    //vector<string> rubrica(1000);
    //rubrica.at(2304) = "matteo";
    // Se faccio così spreco troppa memoria

    map<int, int> mappa;

    //a ciascun valore viene assegnato un valore

    mappa[60] = 40; //O(log N)
    mappa[61] = 221; //O(log N)

    cout << "valore mappa: " << mappa[61] << endl; // 221, accedere a un elemento = O(log N)
    cout << "grandezza mappa: " << mappa.size() << endl;

    for (auto [chiave, valore] : mappa)
    {
        cout << chiave << " : " << valore << endl;
    }
    for (pair<int, int> p : mappa)
    {
        cout << p.first << " : " << p.second << endl;
    }

    unordered_map<int, int> mappa_non_ordinata; //non usarla, è una HASH map
    mappa_non_ordinata[100] = 10;

    //queue

    queue<int> queue;
    //Possiamo mettere in fondo, togliere all'inizio in O(1)

    queue.push(10); //x aggiungere
    queue.push(20);
    queue.push(30); // 10, 20, 30

    cout << "davanti troviamo: " << queue.front() << endl; //10
    queue.pop(); // 20, 30
    cout << "la dimensione della queue e': " << queue.size() << endl;
    cout << "la coda e' vuota? " << queue.empty() << endl;

    //stack
    stack<int> stack;
    stack.push(10); // x aggiungere
    stack.push(20);
    stack.push(30); // 30, 20, 10

    cout << "in cima troviamo: " << stack.top() << endl; //10
    queue.pop(); // 10, 20
    cout << "la dimensione della queue e': " << stack.size() << endl;
    cout << "la coda e' vuota? " << stack.empty() << endl;
    //Aggiungo in cima, toglo in cima

    //deque = stack + queue insieme
    deque<int> deque;
    deque.push_back(20);
    deque.push_front(10);
    deque.push_front(30); // 30, 10, 20

    cout << deque.front() << endl;
    cout << deque.back() << endl;
    deque.pop_back();
    deque.pop_front();

    //Priority

    priority_queue<int> priority_queue; // tiene ordinato
    //Possiamo mettere in fondo, togliere all'inizio in O(1)

    priority_queue.push(10); //x aggiungere O(log N)
    priority_queue.push(20);
    priority_queue.push(30); // 30, 20, 10

    cout << "davanti troviamo: " << priority_queue.top() << endl; //10
    priority_queue.pop(); // 20, 10;
    cout << "la dimensione della queue e': " << priority_queue.size() << endl;
    cout << "la coda e' vuota? " << priority_queue.empty() << endl;

    //set
    set<int> set; // insieme ordinato in copia unica;
    set.insert(3);
    set.insert(2);
    set.insert(3);

    for (int x : set)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << *set.begin(); //elemento più piccolo
    cout << *set.end(); //elemento più grande

    //lower bound = iteratore al primo elemento maggiore di x
    //upper bound = iteratore al primo elemento minore di x

    cout << *set.lower_bound(4);

    cout << "la dimensione del set e': " << set.size() << endl; // 2
    set.erase(3);
    cout << "la dimensione del set e': " << set.size() << endl; // 1

    // algoritmi
    for (int &a : v) //su tutta la struttura, ma preso per riferimento
    {}

    sort(v.begin(), v.end()); //ordina dall'inizio alla fine
    reverse(v.begin(), v.end()); //lo inverto
    sort(v.rbegin(), v.rend()); //ordina decrescente
    vector<vector<int>> V = {
        {1, 2, 3 ,4},
        {1, 2, 3},
        {1, 2},
    };

    sort(V.begin(), V.end(), [](auto a, auto b)
    {
        return a.size() < b.size();
    });

    for (auto sublist : V)
    {
        for (auto x : sublist)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}