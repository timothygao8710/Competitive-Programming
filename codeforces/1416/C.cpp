//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;

#define pb push_back

#define f first
#define s second

struct trie{
    vector<int> cur;
    trie* zero=0, *one=0;

    void insert(int val, int idx, int pos = 31){
        cur.pb(idx);
        if(pos < 0) return;
        if((val>>pos)&1){
            // cout << pos << " 1 SFD" << endl;
            if(one == 0) one = new trie();
            one->insert(val, idx, pos-1);
        }else{
            // cout << pos << " 0 SFD" << endl;
            if(zero == 0) zero = new trie();
            zero -> insert(val, idx, pos-1);
        }
    }
};

pii choose(vector<int>&a, vector<int>&b){ //val : which
    ll zero=0, one=0;
    int l = 0, r = 0, n = a.size(), m = b.size();
    // assert(n != 0&& m != 0);
    // cout << n << " " << m << endl;
    while(l < n || r < m){
        while(l < n && (r == m || a[l] < b[r])) {
            l++; zero += r;
        }
        while(r < m && (l == n || b[r] < a[l])) {
            r++; one += l;
        }
        int tl = l, tr = r;
        if(l != n && r != m && a[l] == b[r]){
            while(l < n && a[l] == b[tr]){
                l++; zero += tr;
            }
            while(r < m && b[r] == a[tl]){
                r++; one += tl;
            }
        }
    }
    return pii(zero, one);
}
trie* test;
int main(){
    assert(test == 0);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N; cin >> N;
    trie root;
    for(int i = 0; i<N; i++){
        int a; cin >> a; root.insert(a, i);
    }
    
    ll ret = 0, inv = 0;
    vector<trie*> step; 
    step.pb(&root);
    // cout << "66" << endl;
    for(int i = 31; i>=0; i--){
        vector<trie*> next;
        ll zero=0, one=0;
        for(auto j : step){
            if(j -> zero == 0 && j -> one == 0) continue;
            if(j -> zero == 0){
                next.pb(j -> one); continue;
            }
            // cout << (j->one == nullptr) << endl;
            if(j -> one == 0){
                next.pb(j -> zero); continue;
            }
            // cout << "here " << i << endl;
            // cout << "index: " << i << endl;
            pii cur = choose(j -> zero -> cur, j -> one -> cur);
            
            zero += cur.f; one += cur.s;
            next.pb(j -> one);
            next.pb(j -> zero);
        }
        // cout << zero <<
        if(zero <= one){
            inv += zero;
        }else{
            inv += one; ret += 1<<i;
        }
        swap(step, next);
    }
    cout << inv << " " << ret << '\n';
    return 0;
}
