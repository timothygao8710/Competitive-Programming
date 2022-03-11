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
    int N; cin >> N;
    stack<pii> a, b;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if((i+j)%2){
                a.push(pii(i, j));
            }else{
                b.push(pii(i, j));
            }
        }
    }

    while(a.size() > 0 && b.size() > 0){
        int c; cin >> c;
        //b, i, j
        if(c != 1){
            cout << 1 << " " << a.top().f << " " << a.top().s << endl;
            a.pop();
        }else{
            cout << 2 << " " << b.top().f << " " << b.top().s << endl;
            b.pop();
        }
    }
    int no = 2;
    if(a.empty()){
        no = 1; swap(a, b);
    }
    while(a.size() > 0){
        int c; cin >> c;
        for(int i = 1; i<=3; i++){
            if(i == no || i == c) continue;
            cout << i << " " << a.top().f << " " << a.top().s << endl;
            a.pop(); break;
        }
    }
    return 0;
}
