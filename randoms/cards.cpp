//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

template <typename T>
struct segtree
{
    T none; //comb(a, none) = a

    T val;
    int gL, gR, mid;
    segtree<T> *left;
    segtree<T> *right;

    T comb(T& l, T& r)
    {
        T ret;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                if(!l.can[i][j]) continue;
                for(int k = 0; k<2; k++){
                    for(int z = 0; z<2; z++){
                        if(gL == 0 && gR == 3) {
                            // cout << gL << " " << gR << " " << i << " " << z <<  " " << l.edges[1][j] << " " << r.edges[0][k] << endl;
                        }
                        if(r.can[k][z] && l.edges[1][j] <= r.edges[0][k]){
                            ret.can[i][z] = true; 
                        }
                    }
                }
            }
            ret.edges[0][i] = l.edges[0][i];
            ret.edges[1][i] = r.edges[1][i];
        }
        return ret;
    }

    segtree(int l, int r, T arr[], T non)
    { //modify arr type
        none = non;
        gL = l; gR = r; mid = (gL+gR)/2;
        if (l == r)
        {
            val = arr[l];
        }
        else
        {
            
            left = new segtree<T>(l, mid, arr, non); right = new segtree<T>(mid + 1, r, arr, non);
            val = comb(
                left->val, right->val);
        }
    }

    T query(int l, int r)
    {

        if (gL > r || gR < l)
        {
            return none;
        }

        if (gL == l && gR == r)
        {
            return val;
        }
        T a = left->query(l, min(r, mid)); T b = right->query(max(l, mid + 1), r);
        return comb(a, b); //might be wrong
    }

    void update(int idx, T set)
    {
        if (gL == gR)
        {
            val = set;
        }
        else
        {
            if (idx <= (gL + gR) / 2)
            {
                left->update(idx, set);
            }
            else
            {
                right->update(idx, set);
            }
            val = comb(left->val, right->val);
        }
   }
};

struct node{
    int edges[2][2];
    bool can[2][2];
    node(){
        can[0][0] = can[1][1] = can[0][1] = can[1][0] = false;
    }
    bool ok(){
        return can[0][0] || can[0][1] || can[1][0] || can[1][1];
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, q, u, v;
    cin >> n;
    node nodes[n];
    for(int i =0; i<n; i++){
        cin >> u; cin >> v;
        nodes[i].edges[0][0] = nodes[i].edges[1][0] = u;
        nodes[i].edges[0][1] = nodes[i].edges[1][1] = v;
        nodes[i].can[0][0] = nodes[i].can[1][1] = true;
    }
    segtree<node> sgt(0, n-1, nodes, node());
    cin >> q;
    for(int i = 0; i<q; i++){
        cin >> u; cin >> v;
        swap(nodes[u-1], nodes[v-1]);
        sgt.update(u-1, nodes[u-1]);
        sgt.update(v-1, nodes[v-1]);
        cout << (sgt.val.ok() ? "TAK" : "NIE") << endl;
    }
    
    return 0;
}
