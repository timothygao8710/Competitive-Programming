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
        int N;
        cin >> N;
        string a, b; cin >> a >> b;
        vector<int> type(N);
        for(int i = 0; i<N; i++){
            if(a[i] == '0' && b[i] == '0'){
                type[i] = 1;
            }else if(a[i] == '1' && b[i] == '1'){
                type[i] = 0;
            }else{  
                type[i] = 2;
            }
        }
        int ret = 0;
        for(int i = 0; i<N; i++){
            if(type[i] < 2){
                if(i + 1 < N && (type[i+1] == (type[i]^1))){
                    ret += 2; i++;
                }else{
                    ret += type[i];
                }
            }else{
                ret += 2;
            }
        }
        cout << ret << '\n';
    }    
    return 0;
}
