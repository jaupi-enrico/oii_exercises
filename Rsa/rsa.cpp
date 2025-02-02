void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    // Esempio di implementazione con un solo carattere da decifrare.
    // Mettiamo il risultato della decifrazione in plaintext[0] e il
    // carattere di fine stringa in plaintext[1].

    for (int i = 0; i < L; ++i)
    {
        long long int num = 1, A, B, AB;
        if (d == 1)
        {
            num = messaggio[i];
        }
        A = messaggio[i];
        B = messaggio[i] % N;
        for (int j = 0; j < d - 1; ++j)
        {
            A = (A * B) % N;
        }
        num = A % N;
        plaintext[i] = num;
    }
    plaintext[L] = '\0';
}
