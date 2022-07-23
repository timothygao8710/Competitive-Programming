//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 2e5 + 100;
vector<int> adj[maxn];
int tour[maxn], tin[maxn], tout[maxn];
int timer = 0;

void etour(int u, int p = -1){
    tin[u] = timer; 
    tour[timer] = u;
    ++timer;
    for(int n : adj[u]){
        etour(n, u);
    }
    tout[timer-1];
}

int good(int x){
    int num = -1;
    for(int i = 2; i<=9; i++){
        
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //max sum = 100
    //prod only with (0), 1,2,3,4,5,6,7,8,9

    //find if sum * x = prod
    int ret = 0;
    for(int i = 1; i<=100; i++){
        for(int j = i; j<=100; j+=i){
            cout << j << endl;
        }
    }
    cout << ret;
    return 0;
}
