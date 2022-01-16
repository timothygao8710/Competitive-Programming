//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

int nums[600][600];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    int idx = -1;
    set<int> unique; 
    int tot = 0, x;
    for(int i = 0; i<N; i++){
        set<int> temp;
        for(int j = 0; j<M; j++){
            cin >> x;
            nums[i][j] = x;
            temp.insert(x);
        }
        tot ^= x;
        temp.erase(x);
        if(temp.size() >= 1){
            swap(temp, unique); idx = i;
        }
    }
    if(tot != 0){
        cout << "TAK" << endl;
        for(int i = 0; i<N; i++){
            cout << M << " ";
        }
    }else{
        if(idx == -1){
            cout << "NIE";
        }else{
            cout << "TAK" << endl;
            for(int i = 0; i<N; i++){
                if(i == idx){
                    for(int j = 0; j<M; j++){
                        if(nums[i][j] == *(unique.begin())){
                            cout << (1+j) << " "; break;
                        }
                    }
                }else{
                    cout << M << " ";
                }
            }
        }
    }
    return 0;
}
