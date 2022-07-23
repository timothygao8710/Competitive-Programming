//Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

//very good problem, based on a changing diameter(diameter can be used with dist, diameter can be updated with dist(reverse))
const int maxn = 1e5 + 7;
const int maxlog = 18;
int idx = 1, compc = 0;
int lift[maxlog][maxn], dep[maxn], color[maxn];
pii diam[maxn];

int jump(int u, int k)
{ //view k in binary
    for (int i = 0; i < maxlog; i++)
    {
        if ((k >> i) & 1)
        {
            u = lift[i][u];
        }
    }
    return u;
}

int lca(int u, int v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    v = jump(v, dep[v] - dep[u]);
    assert(dep[u] == dep[v]);
    if (u == v)
    {
        return u;
    }
    for (int i = maxlog - 1; i >= 0; i--)
    { //jump pows strictly decrease
        if (lift[i][u] != lift[i][v])
        {
            u = lift[i][u];
            v = lift[i][v];
        }
    }
    return lift[0][u];
}

int dist(int u, int v)
{
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void update(int con)
{
    if (con == -1)
    {
        color[idx] = compc;
        diam[compc] = pii(idx, idx);
        compc++; idx++;
        return;
    }

    color[idx] = color[con];
    dep[idx] = dep[con] + 1;
    lift[0][idx] = con;
    for (int i = 1; i < maxlog; i++)
    {
        lift[i][idx] = lift[i - 1][lift[i - 1][idx]];
    }
    pii ends = diam[color[idx]];
    if(dist(ends.f, idx) > dist(ends.f, ends.s)){
        diam[color[idx]] = pii(ends.f, idx);
    }else if(dist(ends.s, idx) > dist(ends.f, ends.s)){
        diam[color[idx]] = pii(ends.s, idx);
    }
    idx++;
}

int query(int u){
    return max(dist(u, diam[color[u]].f), dist(u, diam[color[u]].s));
}

int main()
{
    setIO("newbarn");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char t;
    int Q, u;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> t >> u;
        if (t == 'B')
        {
            update(u);
        }
        else
        {
            cout << query(u) << '\n';
        }
    }
    return 0;
}
