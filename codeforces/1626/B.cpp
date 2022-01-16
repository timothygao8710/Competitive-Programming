//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

void print(vector<int>& a){
    reverse(a.begin(), a.end());
    for(int i : a) cout << i;
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--){
        vector<int> nums;
        string str; cin >> str;
        for(char i : str) nums.pb(i - '0');
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        
        int good = 0;
        
        for(int i = 0; i<n-1; i++){
                
            if(nums[i] + nums[i+1] >= 10){
                nums[i] = nums[i] + nums[i+1] - 10; nums[i+1] = 1;
                good = 1; 
                break;
            }
        }
        if(good){
            print(nums); continue;
        }
        int temp = nums.back();
        nums.pop_back();
        nums[n-2] += temp;
        print(nums);
    }    
    return 0;
}
