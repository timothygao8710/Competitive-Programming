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
    int T; cin >> T;
    while(T--){
        int N, M; cin >>N >> M;
        vector<int> ppl(N*M), sorted(N*M);
        map<int, int> vis, row;
        for(int i = 0; i<N*M; i++){
            cin >> ppl[i]; sorted[i] = ppl[i];
        }
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i<N*M; i++){
            row[sorted[i]] = i/M;
        }
        int ret = 0;
        for(int p : ppl){
            vis[p]++;
            int st = row[p]*M;
            set<int> temp;
            for(int i = 0; i<M; i++){
                if(sorted[st + i] < p && !temp.count(sorted[st+i])){
                    ret += vis[sorted[st + i]];
                    temp.insert(sorted[st + i]);
                    //cout << p <<  " " << sorted[st+i] << " " << vis[sorted[st+i]] << endl;
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
