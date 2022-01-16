//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int S = 2; //minimum state size nessesary in DP to get next value
const int mod = 1e9+7;

ll transition[S][S] = {{3,1},{1,3}}; //How to extend by DP by 1 index
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
    ll N; cin >> N;
    Matrix init(transition);
    Matrix ret = binpow(init, N);
    cout << ret.a[0][0];
    return 0;
}
