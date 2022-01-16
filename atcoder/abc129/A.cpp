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
    int best= 0, bruh = 0;
    for(int i = 0; i<3; i++){
        int a; cin >> a; best = max(best, a);
        bruh += a;
    }
    cout << bruh-best;
    return 0;
}
