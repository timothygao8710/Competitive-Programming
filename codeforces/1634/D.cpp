//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

int ask(int a, int b, int c){
    cout << "? " << a+1 << " " << b+1 << " " << c+1 << endl;
    int ret; cin >> ret;
    return ret;
}

void solve(){
    int N; cin >> N;

    vector<array<int,4>> temp;
    for(int i = 0; i<4; i++){
        vector<int> mess;
        for(int j = 0; j<4; j++){
            if(i != j) mess.pb(j);
        }
        int g = ask(mess[0], mess[1], mess[2]);
        temp.pb({g, mess[0], mess[1], mess[2]});
    }
    sort(temp.begin(), temp.end());
    // assert(temp[2][0] == temp[3][0]);
    vector<int> a(4);
    for(int i = 1; i<4; i++){
        a[temp[2][i]]++;
        a[temp[3][i]]++;
    }

    int waste = 0, best = temp[3][0];
    pii edge(-1,-1);
    for(int i = 0; i<4; i++){
        if(a[i] == 1){
            waste = i;
        }else{
            assert(a[i] == 2);
            if(edge.f == -1){
                edge.f = i;
            }else{
                edge.s = i;
            }
        }
    }

    for(int i = 4; i<N; i++){
        int left = ask(edge.s, waste, i);
        int right = ask(edge.f, waste, i);
        if(left > best && left > right){
            best = left;
            edge.f = i;
        }else if(right > best){
            // assert(right > left);
            best = right;
            edge.s = i;
        }
    }

    cout << "! " << edge.f +1 << " " << edge.s +1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
