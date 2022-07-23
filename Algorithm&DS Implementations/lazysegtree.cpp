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
    T none, lazynone, val, lazy; //comb(a, none) = a
    int gL, gR, mid;
    segtree<T> *left, *right;

    T comb(T &l, T &r)
    {
        return l + r; //modify
    }

    //mod lazy, upd val
    //In this code, lazy represents the value only to be propagated(this->value already updated)
    void compose(segtree<T> *tree, T v)
    {
        tree->lazy += v;
        tree->val += (tree->gR - tree->gL + 1) * v;
        // cout << tree -> gL << " " << tree -> gR << " " << tree -> val << " " << tree -> lazy << endl;
    }
    
    void push()
    {
        if (gL != gR)
        {
            compose(left,lazy);
            compose(right,lazy);
        }
        lazy = lazynone;
    }

    segtree(int l, int r, T arr[], T non, T lazynon)
    { //modify arr type
        none = non, lazy = lazynone = lazynon;
        gL = l, gR = r, mid = (gL + gR) / 2;
        if (l == r)
        {
            val = arr[l];
        }
        else
        {
            left = new segtree<T>(l, mid, arr, non, lazynon);
            right = new segtree<T>(mid + 1, r, arr, non, lazynon);
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
        push();
        T a = left->query(l, min(r, mid));
        T b = right->query(max(l, mid + 1), r);
        return comb(a, b);
    }

    void update(int l, int r, T updlazy)
    {
        if(gL > r || gR < l){
            return;
        }
        
        if(gL == l && gR == r){
            compose(this, updlazy);
        }else{
            push();
            left -> update(l, min(r, mid), updlazy);
            right -> update(max(l, mid+1), r, updlazy);
            val = comb(left->val, right->val);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nums[] = {0,0,0,0,0,0};
    segtree<int> sgt(0, 5, nums, 0, 0);
    sgt.update(0, 3, 5);
    sgt.update(3, 3, -1); 
    cout << sgt.query(0,5);
    return 0;
}