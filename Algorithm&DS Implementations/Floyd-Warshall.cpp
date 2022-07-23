/*input
doesn't work for some reason
*/
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
    int n, m, q, u, v;
    ll w;
    cin >> n; n++;
    cin >> m; cin >> q;
    ll d[n][n];
    for(int i = 0; i<n; i++) fill(d[i], d[i] + n, -1);
    for(int i = 0; i<m; i++){
        cin >> u; cin >> v; cin >> w;
        d[u][v] = d[v][u] = w;
        
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(d[i][k] == -1 || d[k][j] == -1) continue;
                if(d[i][j] == -1){
                    d[i][j] = d[i][k] + d[k][j]; continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i = 0; i<q; i++){
        cin >> u; cin >> v; 
        cout << d[u][v] << endl;
    }

    return 0;
}
