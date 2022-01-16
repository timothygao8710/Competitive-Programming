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
    int n, c;
    cin >> n; int temp = n;
    map<int, int> mp;
    while(n--){
        cin >> c;
        mp[c]++;
    }
    auto a = (*mp.begin()), b = (*(--mp.end()));
    if(a.f == b.f){
        cout << 0;
    }else{
        cout << temp - a.s - b.s;
    }
    return 0;
}
