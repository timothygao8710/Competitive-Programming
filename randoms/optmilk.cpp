//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

void setIO(string s) { // the argument is the filename without the extension
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

struct node{
    ll edges[2][2];
    node(int v){
        edges[0][0] = edges[0][1] = edges[1][0] = 0;
        edges[1][1] = v;
    }
    node(){}
    node comb(node& other){
        node ret;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                ret.edges[i][j] = max(
                    edges[i][0] + other.edges[1][j], edges[i][1] + other.edges[0][j]
                );
            }
        }
        return ret;
    }
};

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
        return l.comb(r);
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

int main(){
    setIO("optmilk");
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll ret = 0; 
    int n, q, u, v;
    cin >> n; cin >> q;
    node nums[n];
    for(int i = 0; i<n; i++){
        cin >> u;
        nums[i] = node(u);
    }
    segtree<node> sgt(0, n-1, nums, node());
    while(q--){
        cin >> u; cin >> v;
        sgt.update(u-1, node(v));
        ret += sgt.val.edges[1][1];
    }
    cout << ret;
    return 0;   
}
