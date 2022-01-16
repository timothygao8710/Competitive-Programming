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

    string s; cin >> s;
     cout << (s[0] == s[1] && s[1] == s[2] ? "Won" : "Lost");

    return 0;
}
