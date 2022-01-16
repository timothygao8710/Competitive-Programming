//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxn = 2002;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout << a[0][0] << endl;
    int H, W, ret = 0; cin >> H >> W;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<W; j++){
            char gay; cin >> gay;
            if(gay == '#') continue;
            c[i][j] = a[i][j] = 1;
            if(j != 0) c[i][j] += c[i][j-1];
            if(i != 0) a[i][j] += a[i-1][j];
        }
    }    
    for(int i = H-1; i>=0; i--){
        for(int j = W-1; j>=0; j--){
            if(a[i][j] == 0) continue;
            d[i][j] = b[i][j] = 1;
            if(i != H-1) b[i][j] += b[i+1][j];
            if(j != W-1) d[i][j] += d[i][j+1];
            ret = max(ret, c[i][j] + d[i][j] + b[i][j] + a[i][j] - 3);
        }
    }
    // for(int i = 0; i<H; i++){
        // for(int j = 0; j<W; j++){
            // ret = max(ret, get(rs[i], j) + get(cols[j], i)-1);
        // }
    // }
    cout << ret;
    return 0;
}
