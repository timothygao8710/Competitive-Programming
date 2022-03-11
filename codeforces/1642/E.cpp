//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

template <typename T>
struct segtree
{
    T val, none;
    int l, r, mid;
    segtree<T> *left, *right;

    T comb(T& l, T& r){
        return min(l, r); //modify
    }

    segtree(int gL, int gR, T non){ 
        l = gL, r = gR, mid = (l+r)/2, none = non;
        if (l == r){
            val = non;
        }else{
            left = new segtree<T>(l, mid, none), right = new segtree<T>(mid + 1, r, none);
            val = comb(left->val, right->val);
        }
    }

    T query(int ql, int qr){
        if (ql > r || qr < l) return none;
        if (ql == l && qr == r) return val;
        T a = left->query(ql, min(qr, mid)), b = right->query(max(ql, mid + 1), qr);
        return comb(a, b);
    }

    void update(int idx, T set){
        if (l == r){
            val = min(val, set);
        }else{
            if (idx <= (l + r) / 2) left->update(idx, set);
            else { right->update(idx, set); }
            val = comb(left->val, right->val);
        }
   }
};

const int maxn = 2e5 + 100;

//only useful when all else is known to be false
set<int> unknown;
segtree<int> intervals(0, maxn-1, 1e9);

void insert(int l, int r){
    intervals.update(l, r);
}

bool exists(int l, int r){ //does exist in here?
    return intervals.query(l, r) <= r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, Q; cin >> N >> Q;
    for(int i = 1; i<=N; i++) unknown.insert(i);
    unknown.insert(0); unknown.insert(N+1);
    while(Q--){
        int t; cin >> t;
        if(t){
            int j; cin >> j;
            if(!unknown.count(j)){
                cout << "NO" << '\n'; continue;
            }
            int l = *(--unknown.lower_bound(j));
            int r = *(unknown.upper_bound(j));
            if(exists(l+1, r-1)){
                cout << "YES" << '\n'; continue;
            }
            cout << "N/A" << '\n';
        }else{
            int l, r, x; cin >> l >> r >> x;
            if(x == 1){
                insert(l, r); continue;
            }
            int c = (*unknown.lower_bound(l));
            while(c <= r){
                unknown.erase(c);
                c = (*unknown.lower_bound(c)); //try commenting this line out
            }
            // cout << "current: " << endl;
            // for(int i : unknown) cout << i << " ";
            // cout << endl;
        }
    }
    return 0;
}
