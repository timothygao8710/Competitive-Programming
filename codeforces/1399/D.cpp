//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        string str; cin >> str;
        vector<int> ret(N);
        stack<int> one, zero;
        int idx = 1;
        for(int i = 0; i<N; i++){
            if(str[i] == '0'){
                if(one.empty()){
                    one.push(idx); idx++;
                }
                ret[i] = one.top();
                one.pop();
                zero.push(ret[i]);
            }else{
                if(zero.empty()){
                    zero.push(idx); idx++;
                }
                ret[i] = zero.top();
                zero.pop();
                one.push(ret[i]);
            }
        }
        cout << idx-1 << endl;
        for(int i : ret) cout << i << " ";
        cout << endl;
    }    
    return 0;
}
