//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second
int N, K;
string str;

int ok(int len){ //--> take at most len away
    int ret = 1;
    for(int i = 0; i<N-1;){
        ++ret;
        int nxt = -1;
        for(int j = i+len;j>i;j--){
            if(j >= N) continue;
            if(str[j] == '0'){
                nxt = j; break;
            }
        }
        if(nxt == -1) return 1e9;
        i = nxt;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K >> str;

    int l = 1, r = N-1;
    while(l < r){
        int mid = (l+r)/2;
        if(ok(mid) <= K){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << (r-1) << '\n';
    return 0;
}
