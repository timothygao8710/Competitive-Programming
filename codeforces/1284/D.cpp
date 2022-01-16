//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.resize(n+1);
    }

    BIT(int nums[], int n){
        this -> n = n+1;
        bit.resize(n+1);
        for (int i = 1; i <= n; i++) {
            bit[i] += nums[i - 1]; //update node
            if (i + (i & -i) <= n) {
                bit[i + (i & -i)] += bit[i]; //update parent
            }
        }
    }
    
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    T sum(int r) {
        r++;
        T ret = 0;
        while (r > 0) {
            ret += bit[r];
            r -= r & -r;
        }
        return ret;
    }

    //updates # at pos nums[idx]
    //does not reset nums[idx], but updates it (+/-)
    void update(int idx, T v) {
        idx++;
        while (idx < n) {
            bit[idx] += v;
            idx += idx & -idx;
        }
    }
};


vector<array<int, 3>> comp(vector<array<int, 3>> nums, int N){
    map<int, int> mp;
    vector<int> sorted(N); 
    for(int i = 0; i<N; i++) sorted[i] = nums[i][0];
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i<N; i++) mp[sorted[i]] = i;
    for(int i = 0; i<N; i++) nums[i][0] = mp[nums[i][0]];
    return nums;
}

bool solve(vector<array<int, 4>> nums, int N){
    vector<array<int, 3>> As(2*N), Bs(2*N);

    for(int i = 0; i<N; i++){
        int a, b, c, d;
        As[2*i] = {nums[i][0], 0, i}; As[2*i+1] = {nums[i][1], 1, i};
        Bs[2*i] = {nums[i][2], 0, 0}; Bs[2*i+1] = {nums[i][3], 0, 0};
    }
    
    As = comp(As, 2*N);
    Bs = comp(Bs, 2*N);
    
    BIT<int> starts(2*N+90), ends(2*N+90);
    int open = 0, good = 1;
    sort(As.begin(), As.end());
    for(auto i : As){
        pii cur = pii(Bs[2*i[2]][0], Bs[2*i[2]+1][0]);
        if(i[1] == 1){
            starts.update(cur.f, -1); ends.update(cur.s+1, -1);
            open--; continue;
        }
        
        int tot = starts.sum(cur.s) - ends.sum(cur.f);
        good = good && tot == open;

        open++; 
        starts.update(cur.f, 1);
        ends.update(cur.s+1, 1);
    }
    return good;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<array<int, 4>> nums(N), b(N);
    for(int i = 0; i<N; i++){
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2] >> nums[i][3];
        b[i][0] = nums[i][2], b[i][1] = nums[i][3];
        b[i][2] = nums[i][0], b[i][3] = nums[i][1];
    }
    cout << (solve(nums, N) && solve(b, N) ? "YES" : "NO") << '\n';
    
    return 0;
}
/* went to grab dinner lol
3
1 3 1 3
2 4 2 5
5 6 4 6
*/