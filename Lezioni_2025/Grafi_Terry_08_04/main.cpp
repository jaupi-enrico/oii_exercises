#include <bits/stdc++.h>

int main()
{
    std::ofstream cout("output.txt");
    std::ifstream cin("input.txt");

    // I Grafi =

    /// Insieme di N nodi
    /// COllegati da M archi

    // Archi = collegamento tra 2 nodi

    /// Bidirezionale (A -> B)(B -> A) = A -- B
    /// Diretto (A -> B) = A --> B
    ///
    /// Pesato = Andare da A a B costa 5
    /// Non Pesato = Tutti gli archi hanno costo 1

    /// 2 Nodi sono adicenti se collegati da un arco (A -- C)
    /// 2 Nodi sono connessi se ci arrivo con un cammino (A -- B -- C)
    /// 2 Nodi sono non connessi se non ci posso arrivare

    /// Gruppi di nodi connessi = Componente connessa

    // Cammino = Sequenza di archi che hanno un nodo in comune;

    // Distanza fra 2 nodi

    /// Numero di archi da percorrere se non pesato
    /// Somma dei pesi degli archi se pesato

    // Memorizzazione di un grafo

    /// M righe, ogni riga è un arco, arco che va da Ai a Bi e se c'è il peso.
    int N, M;

    cin >> N >> M;

    //std::vector<std::pair<int, int>> nodi;
    /// In matrice =
    /// Senza peso:
    /// True se c'è larco
    /// False se non c'è l'arco
    /// C0n peso
    /// W se non c'è l'arco
    /// -1 se non c'è l'arco

    // Lista di adiacenza
    /*
    std::vector<std::vector<int>> adj(N);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a); // Arco bidirezionale
    }
    */

    //Lista di adiacenza con pesi
    std::vector<std::vector<std::pair<int, int>>> adj_Con_Pesi(N);

    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        std::cin >> a >> b >> w;

        adj_Con_Pesi[a].push_back({b, w});
        adj_Con_Pesi[b].push_back({a, w}); // Arco bidirezionale con pesi
    }

    //Stampiamo i vicini di 3
    /*
    cout << "Vicini di 3\n";

    for (auto i : adj[3])
    {
        cout << i << " ";
    }
    */

    // Visiste
    // BFS (Visista in ampiezza) = In ordine di distanza da quello di partenza
    // si usa un vettore per indicare se è stato visita to o no
    // e si usa la Lista di adiacenza per prednere quello davanti nella codsa e scorrere i vicini

    /*
    cout << "Lista di visitati\n";

    std::vector<bool> vis(N);
    std::queue<int> Q;

    int P;
    cin >> P;

    vis[P] = 1;

    Q.push(P);
    while (!Q.empty())
    {
        int i = Q.front();

        Q.pop();

        for (auto j : adj[i])
        {
            if (vis[j] == 0)
            {
                vis[j] = 1;
                Q.push(j);
            }
        }
    }

    cout << "Nodi nela companente connessa di P: ";
    for (int i = 0; i < N; ++i)
    {
        if (vis[i])
        {
            cout << i << " ";
        }
    }
    */

    // Algoritmo di Dijkstra = Grafo pesato e un nodo P di partenza
    // Quanto è lungo il percorso più breve da P a i por ogni i fino a N - 1

    std::vector<long long> dst (N, LLONG_MAX);
    std::vector<bool> vis(N);
    std::priority_queue<int> PQ;


    return 0;
}