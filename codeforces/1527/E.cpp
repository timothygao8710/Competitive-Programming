//Author: timg8710

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
const int INF = 35001*35001 + 36696969, none = INF, lazynone = 0;
template <typename T>
struct segtree
{
    T val, lazy; //comb(a, none) = a
    unsigned short int gL, gR, mid;
    segtree<T> *left, *right;

    T comb(T &l, T &r)
    {
        return min(l,r); //modify
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
    segtree(){}//dummy(like wiz!) constructor
    segtree(unsigned short int l, unsigned short int r)
    { //modify arr type
        lazy = lazynone, val = none;
        gL = l, gR = r, mid = (gL + gR) / 2;
        if (l !=r){
            left = new segtree<T>(l, mid);
            right = new segtree<T>(mid + 1, r);
            val = comb(
                left->val, right->val);
        }
    }

    T query(unsigned short int l, unsigned short int r)
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
        T b = right->query(max(l, (unsigned short int)(mid + 1)), r);
        return comb(a, b);
    }

    void update(unsigned short int l, unsigned short int r, T updlazy)
    {
        if(gL > r || gR < l){
            return;
        }
        
        if(gL == l && gR == r){
            compose(this, updlazy);
        }else{
            push();
            left -> update(l, min(r, mid), updlazy);
            right -> update(max(l, (unsigned short int)(mid+1)), r, updlazy);
            val = comb(left->val, right->val);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    unsigned short int N, K; cin >> N >> K; 
    unsigned short int last[N+1], nums[N]; 
    for(int i = 0; i<=N; i++) last[i] = 0;
    segtree<int> dp[K+1];
    for(int i = 0; i<=K; i++) dp[i] = segtree<int>(0, N);
    dp[0].update(0,0,-INF);
    
    for(unsigned short int i = 0; i<N; i++){
        cin >> nums[i];
        // cout << nums[i] << " ";
        if(last[nums[i]] == 0){
            last[nums[i]] = i+1;

        } 
    }
    for(unsigned short int i = 1; i<=N; i++){
        for(unsigned short int j = 1; j<=K; j++){
            // cout << i << " " << j << endl;
            // cout << nums[i-1] <<  " " << last[nums[i-1]] << " " << i << endl;
            dp[j-1].update(0, last[nums[i-1]]-1, i - last[nums[i-1]]);
            
            dp[j].update(i, i, dp[j-1].query(0, i-1) -INF);
            // cout << i << " " << j << endl;
        }
        last[nums[i-1]] = i;
    }
    // cerr << "SD:LFKJDSKFJDFSKLL:SDFJ" << endl;
    cout << dp[K].query(N, N);
    return 0;
}
/*
2 1
1 1
*/