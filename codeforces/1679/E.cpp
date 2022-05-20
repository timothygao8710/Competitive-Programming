//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int mod = 998244353;

int binpow(ll base, ll pow)
{
    ll ret = 1;
    while(pow > 0){
        if(pow & 1) ret = (ret * base)%mod;
        base = (base * base)%mod;
        pow >>= 1;
    }
    return ret;
}

int get(char c){
    return (1<<(c - 'a'));
}

string str;
ll tot = 0;
ll frees[18][1<<18];
//for each subset, the number of free
int N;

void solve(int l, int r){
    int sub = 0, free = tot;
    while(l >= 0 && r < N){
        if(str[l] == '?' && str[r] == '?'){
            if(l != r) free--;
        }else if(str[l] != '?' && str[r] != '?'){
            if(str[l] != str[r]) break;
        }else{
            if(str[l] == '?') sub |= get(str[r]);
            if(str[r] == '?') sub |= get(str[l]);
            free--;
        }
        for(int i = 0; i<=17; i++) {
            frees[i][sub] += binpow(i, free);
            frees[i][sub] %= mod;
        }
        l--, r++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> str;

    for(int i = 0; i<N; i++) tot += str[i] == '?';
    // assert(tot);

    for(int i = 0; i<N; i++){
        solve(i, i);
    }
    for(int i = 0; i<N-1; i++){
        solve(i, i+1);
    }

    for (int dif = 0; dif < 18; dif++){
        for(int i = 0; i<18; i++){ //SOS DP
            for(int j = 0; j<(1<<18); j++){
                if((j>>i)&1){
                    frees[dif][j] += frees[dif][j ^ (1<<i)];
                    frees[dif][j] %= mod;
                }
            }
        }
    }

    int Q; cin >> Q;
    while(Q--){
        string a; cin >> a;
        int bset = 0;
        for(int i = 0; i<(int)a.length(); i++){
            bset += (1<<(a[i] - 'a'));
        }
        cout << frees[a.length()][bset] << '\n';
    }

    return 0;
}
