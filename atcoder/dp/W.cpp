//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5+9;
vector<pii> back[maxn];

template <typename T>
struct segtree
{
    T none, lazynone, val, lazy; //comb(a, none) = a
    int gL, gR, mid;
    segtree<T> *left, *right;

    T comb(T &l, T &r)
    {
        return min(l, r); //modify
    }

    //mod lazy, upd val
    //In this code, lazy represents the value only to be propagated(this->value already updated)
    void compose(segtree<T> *tree, T v)
    {
        tree->lazy += v;
        tree->val += v;
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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, l, r, cost; cin >> N >> M;
    ll tot = 0;
    for(int i = 0; i<M; i++){
        cin >> l >> r >> cost; back[r+1].pb(pii(l, cost));
        tot += cost;
    }
    ll nums[N+2]; 
    fill(nums, nums+N+2,0);
    segtree<ll> dp(0, N+1, nums, 0, 0);
    for(int i = 1; i<=N+1; i++){
        for(pii j : back[i]){
            dp.update(0, j.f-1, j.s);
        }
        dp.update(i,i, dp.query(0, i));
    }
    cout << tot - dp.query(N+1,N+1);
    return 0;
}
