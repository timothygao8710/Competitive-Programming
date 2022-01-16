//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pdp;
 
#define pb push_back
 
#define f first
#define s second

const int bket = 300;

int xDir[4] = {0,0,-1,1};
int yDir[4] = {1,-1,0,0};

int dist(pii a, pii b){
    return abs(a.f - b.f) + abs(a.s - b.s);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M, P; cin >> N >> M >> P;
    vector<pdp> locs[P];
    
    for(int i =0; i<N; i++){
        for(int j= 0; j<M; j++){
            int t; cin >> t; t--;
            locs[t].pb(pdp(1e9, pii(i, j)));
        }
    }
    locs[P-1][0].f = 0;
    for(int i = P-2; i>=0; i--){
        if((int)(locs[i+1].size()) <= bket){
            for(int j = 0; j<locs[i].size(); j++){
                for(auto k : locs[i+1]){
                    locs[i][j].f = min(locs[i][j].f, dist(locs[i][j].s, k.s)+k.f);
                }
            }
        }else{
            vector<pdp> temp; swap(temp, locs[i+1]);
            sort(temp.begin(), temp.end());
            int vis[N][M]; int left = N*M;
            for(int l = 0; l<N; l++){
                for(int j = 0; j<M; j++){
                    vis[l][j] = -1;
                }
            }
            vector<pii> bfs;
            int idx = 0;
            for(int cost = temp[0].f; left > 0; cost++){
                vector<pii> step;
                while(idx < temp.size() && cost >= temp[idx].f){
                    bfs.pb(temp[idx].s); idx++;
                }
                for(auto loc : bfs){
                    if(vis[loc.f][loc.s] != -1) continue;
                    vis[loc.f][loc.s] = cost; left--;
                    for(int k = 0; k < 4; k++){
                            int dX = xDir[k] + loc.s;
                            int dY = yDir[k] + loc.f;
                            if(dX >= M || dX < 0 || dY < 0 || dY >= N || vis[dY][dX] != -1) continue;
                            step.pb(pii(dY, dX));
                    }
                }
                //cout << "BRO" << endl;
                swap(bfs, step);
            }

            for(int j = 0; j<locs[i].size(); j++){
                locs[i][j].f = vis[locs[i][j].s.f][locs[i][j].s.s];
            }
        }
    }
    int ret = 1e9;
    for(auto i : locs[0]){
        ret = min(ret, i.f + i.s.f + i.s.s);
    }
    cout << ret;
    return 0;
}
