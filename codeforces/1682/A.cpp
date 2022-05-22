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
        int l = (N-1)/2, r = (N)/2;
        
        int ret = 0;
        string str; cin >> str;
        char og = str[N/2];
        while(l >= 0 && r < N && str[l] == str[r] && str[l] == og){
            ret ++;
            if(l != r) ret ++;
            l--, r++;
        }
        cout << ret << '\n';
    }    
    return 0;
}
