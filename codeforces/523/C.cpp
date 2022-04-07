//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int get(string a, string b){
    int p = 0;
    for(int i = 0; i<b.length(); i++){
        if(b[i] == a[p]){
            p++;
        }
        if(p == a.length()) return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    int front = get(a, b);
    if(front == -1) {
        cout << 0; return 0;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int back = b.length()-1-get(a, b);
    cout << max(0, back - front) << '\n';
    return 0;
}
