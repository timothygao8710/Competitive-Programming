//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

const int maxa = 3e5 + 9;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    int pref[maxa]; pref[0] = 0;
    for(int i = 1; i<maxa; i++){
        pref[i] = pref[i-1] ^ i;
    }

    while(T--){
        int a, b; cin >> a >> b;;
        int last = pref[a-1];
        if((a^last) == b){
            cout << (a + 2) << '\n'; continue;
        }

        if(last == b){
            cout << a << '\n';
        }else{
            cout << max(2, a+1) << '\n';
        }
    }
    return 0;
}
