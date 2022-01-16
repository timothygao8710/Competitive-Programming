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
    int T;
    cin >> T;
    while (T--)
    {
        int N, sum = 0, tot = 0;
        cin >> N;
        int A[N], B[N];
        vector<pii> more, less;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> B[i];
            int t = A[i] - B[i];
            if (t > 0)
            {
                more.pb(pii(t, i + 1));
                tot += t;
            }
            else if (t < 0)
            {
                less.pb(pii(-t, i + 1));
                tot += -t;
            }
            sum += t;
        }
        if (sum != 0)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << (tot / 2) << "\n";
        for (auto i : less)
        {
            while (i.f > 0)
            {
                if (more[more.size() - 1].f == 0)
                    more.pop_back();
                i.f--;
                more[more.size() - 1].f--;
                cout << (--more.end())->s << " " << i.s << "\n";
            }
        }
    }
    return 0;
}