//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxn = 2e5+7;
int pref[6][maxn];
int types[6][3] = {
 {0, 1, 2},
 {0, 2, 1},
 {1, 0, 2},
 {1, 2, 0},
 {2, 1, 0},
 {2, 0, 1}
};

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M; string str; cin >> str;
    for(int i = 0; i<6; i++){
        for(int j = 0; j<N; j++){
            pref[i][j+1] = pref[i][j] + (str[j]-'a' != types[i][j%3]);
        }
    }
    
    for(int i = 0; i<M; i++){
        int ret = INT_MAX, l, r; cin >> l >> r;
        for(int j = 0; j<6; j++){
            ret = min(ret, pref[j][r] - pref[j][l-1]);
        }
        cout << ret << '\n';
    }
    return 0;
}
