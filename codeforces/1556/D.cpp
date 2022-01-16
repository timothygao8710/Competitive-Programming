//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int sum(int a, int b){
    int sum = 0, t;
    cout << "or " << a << " " << b << endl;
    cin >> sum;
    cout << "and " << a << " " << b << endl;
    cin >> t; sum += t;
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, K; cin >> N >> K;    
    /*
    x, y, z
    x + z, y + z --> x - y
    x + y
    */
    int xz = sum(1, 3), yz = sum(2, 3), xy = sum(1, 2);
    int diff = xz - yz;
    assert((xy + diff)%2 == 0);
    int x = (xy + diff)/2, y = xy - x, z = xz - x;
    vector<int> all; all.pb(x), all.pb(y), all.pb(z);
    for(int i = 3; i<N; i++){
        int ssum = sum(i+1, 1);
        all.pb(ssum - x);
    }
    sort(all.begin(), all.end());
    cout << "finish " << all[K-1] << endl;

    return 0;
}
