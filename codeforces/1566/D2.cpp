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
        vector<int> ppl(N*M), sorted(N*M), vis(N*M);
        map<int, int> row;
        for(int i = 0; i<N*M; i++){
            cin >> ppl[i]; sorted[i] = ppl[i];
        }
        sort(sorted.begin(), sorted.end());
        set<int> temp;
        for(int i = 0; i<N*M; i++){
            if(!temp.count(sorted[i])){
                row[sorted[i]] = i/M;
                temp.insert(sorted[i]);
            }
        }
        int ret = 0;
        for(int p : ppl){
            int bk = (row[p]+1)*M - 1;
            //cout << p << " " << bk << endl;
            int i = 0;
            for(; i<M; i++){
                if(sorted[bk-i] > p){
                    ret+=1^vis[bk-i];
                }else if(sorted[bk-i] == p){
                    if(!vis[bk-i]){
                        vis[bk-i] = 1; i++;
                        break;
                    }
                }else{
                    assert(false);
                }
            }
            //cout << i << endl;
            if(i == M || sorted[bk-i] != p){
                //cout << "HO" << endl;
                row[p]++;
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
/*
1
3 3
3 4 4 1 1 1 1 1 2
*/