#include <bits/stdc++.h>

int main()
{
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
    return 0;
}