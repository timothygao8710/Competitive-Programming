//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;

#define pb push_back

#define f first
#define s second

const int S = 3; //minimum state size nessesary in DP to get next value
const int mod = 1e9+7;

ll mark[S][S];
ll og[S][S] = {{1,1,0},{1,1,1},{0,1,1}};
ll transition[S][S] = {{1,1,0},{1,1,1},{0,1,1}}; //How to extend by DP by 1 index
ll zeroes[S][S];

struct Matrix{
    ll a[S][S];

    //identity matrix
    Matrix(){
        for(int i = 0; i<S; i++) for(int j = 0; j<S; j++) a[i][j] = i == j; 
    }

    Matrix(ll init[S][S]){
        for(int i = 0; i<S; i++) for(int j = 0; j<S; j++) a[i][j] = init[i][j];
    }

    Matrix operator* (Matrix& other){
        Matrix ret(zeroes);
        for(int i = 0; i<S; i++){
            for(int j = 0; j<S; j++){
                for(int k = 0; k<S; k++){
                    ret.a[i][k] += (a[i][j] * other.a[j][k]) % mod;
                    ret.a[i][k] %= mod;
                }
            }
        }
        return ret;
    } 
};

//binpow: matrix^(i+j) = matrix^i * matrix^j
Matrix binpow(Matrix base, ll pow)
{
    Matrix ret;
    while(pow > 0){
        if(pow & 1) ret = ret * base;
        base = base * base;
        pow >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N, M; cin >> N >> M;
    vector<array<ll, 3>> bps;
    for(int i = 0; i<N; i++){
        ll c, a, b; cin >> c >> a >> b;
        bps.pb({a, -1, c-1}), bps.pb({b+1, 1, c-1});
    }
    sort(bps.begin(), bps.end());
    bps.pb({M+1, 1, 0});
    ll cur[3] = {0,1,0};
    ll last = 2;
    for(auto c : bps){
        Matrix grid(transition);
        grid = binpow(grid, c[0] - last);
        last = c[0];
        ll nxt[3] = {0,0,0};
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                nxt[j] += grid.a[i][j] * cur[i];
                nxt[j] %= mod;
            }
        }
        // cout << c[0] << " " << nxt[0] << " " << nxt[1] << " " << nxt[2] << endl;
        swap(nxt, cur);
        for(int i = 0; i<3; i++){
            // cout << c[2] << endl;
            if(mark[i][c[2]] == 0) transition[i][c[2]]=0;
            mark[i][c[2]] += -1 * c[1]; 
            // cout << c[2] << " " << mark[i][c[2]] << endl;
            if(mark[i][c[2]] == 0) transition[i][c[2]]=og[i][c[2]];
        }
        // cout << "miss; " << transition[2][2] << endl;
    }
    cout << cur[1] << '\n';
    return 0;
}
