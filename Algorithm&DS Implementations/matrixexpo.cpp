//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//https://www.youtube.com/watch?v=eMXNWcbw75E

//in fib: we need 2 states -> dp[i-1], dp[i-2]
//in other cases, we could have dp[i-1][0], dp[i-1][1],(2), 
//or dp[i-1][0], dp[i-1][1], dp[i-2][2],(3), for example
const int S = 2; //state_size
//In DP, how many states we to transition?

ll transition[S][S] = {{0,1},{1,1}}; //How to extend by 1 index
//transition in O(1) space DP

//NOTE: Later, dont use all this fancy shit as template, just use n=2
//Draw out nodes as diagram, transitions are edges between nodes. The matrix is just compressing transitions

const int mod = 1e9+7;
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

//for fib: Key idea is that we store the multipliers in the matrix: 
//supposed a sequence a,b....,c,d
//matrix[i][j] means j += matrix[i][j]*i
//i is 0 or 1, corresponding to a or b
//j is 0 or 1, corresponding to c or d

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll N; cin >> N;
    if(N == 0) {
        cout << 0; return 0;
    }
    Matrix init(transition);
    Matrix ret = binpow(init, N);
    cout << ((ret.a[0][0] + ret.a[1][0])%mod);
    return 0;
}
