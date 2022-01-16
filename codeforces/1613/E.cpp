// Author: timg8710

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define pb push_back

#define f first
#define s second

int xDir[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int yDir[8] = {1, -1, 0, 0, -1, 1, -1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        char grid[N][M];
        int open[N][M];
        queue<pii> bfs;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++)
            {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++)
            {
                open[i][j] = 0;
                if (grid[i][j] == 'L'){
                    bfs.push(pii(i, j));
                }else{
                    for(int k = 0; k<4; k++){
                        int dy = i + yDir[k], dx = j + xDir[k];
                        if(dy >= N || dx >= M || dy < 0 || dx < 0) continue;
                        open[i][j] += grid[dy][dx] != '#';
                    }
                }
                // cout << open[i][j];
            }
            // cout << endl;
        }
        pii lab = bfs.front();
        while(!bfs.empty()){
            pii cur = bfs.front(); bfs.pop(); grid[cur.f][cur.s]='+';
            for(int i = 0; i<4; i++){
                int dy = cur.f + yDir[i], dx = cur.s + xDir[i];
                if(dy >= N || dx >= M || dy < 0 || dx < 0 || grid[dy][dx] != '.') continue;
                open[dy][dx]--;
                if(open[dy][dx] <= 1) bfs.push(pii(dy, dx));
            }
        }
        grid[lab.f][lab.s] = 'L';
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<M; j++){
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}