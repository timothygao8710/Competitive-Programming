//Author: timg8710

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> pii;
 
#define pb push_back
 
#define f first
#define s second

//Many game theory problems use the Copy Opponent Move Strategy
//Mainly, because often this generates an easily followed recursive pattern(ne state after 2 moves(by copying) can result in identical scenario)
//e.g, here, if N is odd. By subtracting odd, the other player can always also subtract an odd, which results in a total loss of an even number, thus the resulting number is once again odd
//The Solution Is based around the first player avoiding becoming odd

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, N; cin >> T;
    while(T--){
        cin >> N;
        if(N%2){
            cout << "Bob\n";
        }else{
            int times = 0;
            while(N%2 == 0){
                N /= 2; times++;
            }
            if(N != 1){
                cout << "Alice\n";
            }else{
                cout << (times%2 ? "Bob" : "Alice") << "\n";
            }
        }
    }
    return 0;
}
