/*input
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
*/

//Author: timg8710

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

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
        return min(l, r); //modify
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, u, v, t;
    cin >> n; cin >> q;
    ll nums[n];
    for(int i =0; i<n; i++) cin>>nums[i];
    segtree<ll> tree(0, n-1, nums, 0);
	for(int i = 0; i<q; i++){
        cin>> t;
        cin >> u; cin >> v;
        if(t == 1){
            tree.update(u-1, v);
        }else{
            cout << tree.query(u-1, v-1) << endl;
        }
    }
    return 0;
}