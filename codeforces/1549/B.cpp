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
    int T, N; cin >> T;
    while(T--){
        cin >> N;
        string a, b;
        cin >> a >> b; swap(a, b);
        int ret = 0;
        
        for(int i = 0; i<a.length(); i++){
            if(a[i] == '0') {
                continue;
            }
            if(b[i] == '0'){
                ret++; continue;
            }
            if(i-1 >= 0 && b[i-1] == '1'){
                    ret++; continue;
            }else if(i+1 < N){
                if(b[i+1] == '1'){
                    b[i+1] = '2';
                    ret++; continue;
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
