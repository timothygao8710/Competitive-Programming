//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int sum = 0, c = 0; 
        for(int i = 0; i<N; i++){
            cin >> c; sum += c;
        } 
        if(sum == N){
            cout << 0 << "\n";
        }
        else if(sum < N){
            cout << 1 << "\n";
        }else{
            cout << sum - N << "\n";
        }
    }    
    return 0;
}
