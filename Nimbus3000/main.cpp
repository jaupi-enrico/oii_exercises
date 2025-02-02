#include <algorithm>
#include <iostream>
using namespace std;

struct Time
{
    int start, end;
};

bool compare(const Time& a, const Time& b) {
    return a.end < b.end;
}

int N;
Time rides[1000];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> rides[i].start >> rides[i].end;
    }
    sort(rides, rides + N, compare);
    return 0;
}
