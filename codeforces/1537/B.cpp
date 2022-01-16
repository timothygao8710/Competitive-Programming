//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define pb push_back

#define f first
#define s second

ll dist(int a, int b, int c, int d)
{
    return abs(a - c) + abs(d - b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, N, M, I, J;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> I >> J;
        ll best = -LLONG_MAX;
        pii ret, other;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int x = i * (N - 1) + 1;
                int y = j * (M - 1) + 1;
                // cout << x << " " << y << endl;
                for (int a = 0; a < 2; a++)
                {
                    for (int b = 0; b < 2; b++)
                    {
                        int dx = a * (N - 1) + 1;
                        int dy = b * (M - 1) + 1;
                        ll cur = min(
                            dist(I, J, x, y) + dist(x, y, dx, dy),
                            dist(I, J, dx, dy) + dist(dx, dy, x, y));
                        // if(dx == 0 || dy == 0 || x == 0 || y == 0){
                        //     cout << i << " " << j << " " << a << " " << b << endl;
                        // }
                        if (cur > best)
                        {
                            // cout << cur << endl;
                            ret.f = x;
                            ret.s = y;
                            other.f = dx;
                            other.s = dy;
                            best = cur;
                        }
                    }
                }
            }
        }
        cout << ret.f << " " << ret.s << " " << other.f << " " << other.s << endl;
    }
    return 0;
}
