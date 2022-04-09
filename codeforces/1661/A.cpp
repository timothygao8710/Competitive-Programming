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
        vector<int> a(N), b(N);
        ll ret = 0;
        for(int i =0; i<N; i++) cin >> a[i];
        for(int i = 0; i<N; i++) cin >> b[i];
        for(int i = 0; i<N; i++){
            if(a[i] < b[i]) swap(a[i], b[i]);
            if(i != 0) ret += abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]);
        }
        cout << ret << '\n';
    }   
    return 0;
}
