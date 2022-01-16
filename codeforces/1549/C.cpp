//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, u, v; cin >> N >> M;
    int cur = N;
    vector<int> higher(N);
    for(int i = 0; i<M; i++){
        cin >> u >> v;
        if(u > v){
            swap(u, v);
        }
        higher[u]++;
        if(higher[u] == 1) cur--;
    }
    // cout << u << " "<< v << endl;
    int Q; cin >> Q;
    for(int i = 0; i<Q; i++){
        int t; cin >> t;
        if(t == 1){
            cin >> u >> v;
            if(u > v){
                swap(u, v);
            }
            higher[u]++;
            if(higher[u] == 1) cur--;
        }else if(t == 2){
            cin >> u >> v;
            if(u > v){
                swap(u, v);
            }
            higher[u]--;
            if(higher[u] == 0) cur++;
        }else{
            cout << cur << '\n';
        }
    }
    return 0;
}
