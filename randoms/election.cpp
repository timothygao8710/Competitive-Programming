//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

struct node{
    int sum, l, r, res;
    node(int v){
        sum = v;
        l = r = res = min(0, v);
    }
    node(){
        sum = l = r = res = 0;
    }
    node comb(node& other){
        node h;
        h.sum = sum + other.sum;
        h.l = min(l, sum + other.l);
        h.r = min(other.r, other.sum + r);
        h.res = min({l + other.r, sum + other.res, res + other.sum});
        return h;
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
        // cout << l << " " << r << " ";
        // cout << val.l <<  " "<< val.r << " " << val.fr << endl;
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
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q, u, v;
    char c;
    cin >> n;
    node nums[n];
    for(int i = 0; i<n; i++) {
        cin >> c; 
        nums[i] = node((c == 'T' ? -1 : 1));
    }
    cin >> q;
    segtree<node> sgt(0,n-1, nums, node());
    while(q--){
        cin >> u; cin >> v;
        // cout << res.l <<  " "<< res.r << " " << res.fr << endl;
        cout << -(sgt.query(u-1, v-1).res) << "\n";
    }
    return 0;
}
