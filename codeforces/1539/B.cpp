//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define pb push_back

#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, Q, l, r;
    cin >> N >> Q;
    string str;
    cin >> str;
    ll pref[N+1];
    for (int i = 0; i < N; i++)
    {
        pref[i+1] = str[i] - 'a' + 1;
            pref[i+1] += pref[i];
    }
    for(int i = 0; i<Q; i++){
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }
}
