//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

const int maxa = 2500009;

vector<int> occ[maxa];
vector<int> sums[2*maxa];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<int> nums(N);
    int prev = -1;
    for(int i = 0; i<N; i++){
        cin >> nums[i];
        occ[nums[i]].pb(i+1);
        if(occ[nums[i]].size() > 1){
            if(prev == -1 || prev == nums[i]){
                prev = nums[i];
            }else{
                cout << "YES" << endl;
                cout << occ[prev][0] << " " << i+1 << " " << occ[prev][1] << " " << occ[nums[i]][0] << endl;
                return 0;
            }
        }
    }    

    if(prev != -1){
        if(occ[prev].size() >= 4){
            cout << "YES" << endl;
            cout << occ[prev][0] << " " << occ[prev][1] << " " << occ[prev][2] << " " << occ[prev][3] << endl;
            return 0;
        }
        for(int i = 0; i<occ[prev].size(); i++) nums[occ[prev][i]-1] = -1;
        sums[2*prev].pb(occ[prev][0]);
        sums[2*prev].pb(occ[prev][1]);
        nums[occ[prev][0]-1] = prev;
    }

    for(int i = 0; i<N; i++){
        if(nums[i] == -1) continue;
        for(int j = i+1; j<N; j++){
            if(nums[j] == -1) continue;
            int sum = nums[i] + nums[j];
            sums[sum].pb(i+1);
            sums[sum].pb(j+1);
            if(sums[sum].size() >= 4){
                cout << "YES" << endl;
                cout << sums[sum][0] << " " << sums[sum][1] << " " << sums[sum][2] << " " << sums[sum][3] << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
