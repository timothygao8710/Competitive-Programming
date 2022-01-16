//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int ask(int idx, int val, int N){
    cout << "? ";
    for(int i = 1; i<=N; i++){
        if(i == idx){
            cout << val;
        }else{
            cout << 2;
        }
        cout << " ";
    }
    cout << endl;
    int res; cin >> res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    if(N == 2){
        if(ask(1, 1, 2)){
            cout << "! " << "2 "  << "1" << endl;
        }else{
            cout << "! " << "1 " << "2" << endl;
        }
        return 0;
    }
    int root = 0;
    vector<int> nxt(N+1);
    for(int i = N; i>=1; i--){
        root ^= i; 

        if(nxt[i] == 0){
            // cout << "S " << i << endl;
            nxt[i] = ask(i, 3, N);
        } 
        int prev = ask(i, 1, N);
        if(prev != i) nxt[prev] = i;
        // cout << "S: " << nxt[i] << endl;
        root ^= nxt[i];
    }

    vector<int> ret(N+1);
    cout << "! ";
    for(int i = 1; i<=N; i++){
        ret[root]=i;
        root = nxt[root];
    }
    for(int i = 1; i<=N; i++) cout << ret[i] << " ";
    cout << endl;
    return 0;
}
/*
4

3
0
2
3
1
2
0
1
*/