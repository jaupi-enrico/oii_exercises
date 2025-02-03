#include <vector>
#include <set>

using namespace std;
set<long long, less<>> st;

void inizia() {
    return;
}

void apri(long long p) {
    st.insert(p);
    return;
}

void chiudi(long long p) {
    st.erase(p);
    return;
}

long long chiedi(long long p) {
    if (st.empty()) {
        return -1;
    }

    auto NearestPos = st.lower_bound(p);

    if (NearestPos == st.end())
    {
        NearestPos--;
        return *NearestPos;
    }
    if (*NearestPos == p || NearestPos == st.begin())
    {
        return *NearestPos;
    }

    long long int sinistra = *prev(NearestPos);
    long long int retta_via = *NearestPos;

    if (p - sinistra >= retta_via - p)
    {
        return retta_via;
    }
    return sinistra;
}
