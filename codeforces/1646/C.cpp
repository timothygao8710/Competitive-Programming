//@timothyg

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

ll gfact(int x)
{
    return x == 0 ? 1 : (x * gfact(x - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> fact;
    for (int i = 0; i <= 16; i++)
    {
        fact.pb(gfact(i));
    }

    int T;
    cin >> T;
    while (T--)
    {
        int ret = 1e9;
        ll x;
        cin >> x;

        for (int i = 0; i < (1 << 17) - 1; i++)
        {
            ll temp = x;
            for (int j = 0; j <= 16; j++)
            {
                temp -= fact[j] * ((i >> j) & 1);
            }
            
            if (temp < 0)
                continue;
            // cout << temp << " " << i << endl;
            ret = min(ret, __builtin_popcountll(i) + __builtin_popcountll(temp));
        }
        cout << ret << '\n';
    }
    return 0;
}
