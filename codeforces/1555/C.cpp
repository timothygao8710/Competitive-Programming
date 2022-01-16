//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second
//LMAO BRUH I JOINED WITH 40 MINUTES LEFT LMFAOFMAFLFLAKNFA
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N; cin >> T;
    while(T--){
        cin >> N;
        vector<ll> pref(N+ 1);
        vector<ll> suf(N+1);
        for(int i = 0; i<N; i++){
            cin >> suf[i];
        }
        for(int i = 0; i<N; i++){
            cin >> pref[i];
        }
        for(int i = N-1; i>=0; i--){
            if(i+1 < N){
                suf[i] += suf[i+1];
            }
        }
        for(int i = 0; i<N; i++){
            if(i-1 >=0){
                pref[i] += pref[i-1];
            }
        }
        ll ret = LLONG_MAX;
        for(int i = 0; i+2<=N; i++){
            ret = min(ret, max(pref[i], suf[i+2]));
        }
        if(1 < N) ret = min(ret, suf[1]);
        cout << (ret == LLONG_MAX ? 0 : ret) << '\n';
    }
    return 0;
}
/*
1 
2 
1 1
2 1
*/