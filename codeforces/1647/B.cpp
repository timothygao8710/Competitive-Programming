//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

vector<pii> get(string str){
    int p = -1;
    vector<pii> ret;
    for(int i = 0; i<str.length(); i++){
        if(str[i] == '0'){
            if(p != -1){
                ret.pb(pii(p, i-1));
                p = -1;
            }
        }else{
            if(p == -1) p = i;
        }
    }
    if(p != -1) ret.pb(pii(p, str.length()-1));
    return ret;
}

bool intersect(pii a, pii b){
    return (a.f >= b.f && a.f <= b.s) || (a.s >= b.f && a.s <= b.s) || (b.f >= a.f && b.f <= a.s);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, M; cin >> N >> M;
        string a; cin >> a;
        vector<pii> prev = get(a);
        int ret = 1;
        for(int i = 1; i<N; i++){
            cin >> a;
            vector<pii> cur = get(a);
            for(pii j : cur){
                for(pii k : prev){
                    if(j.f == k.f && j.s == k.s) continue;
                    ret = ret && !intersect(j, k);
                }
            }
            swap(cur, prev);
        }
        cout << (ret ? "YES" : "NO") << '\n';
    }    
    return 0;
}
