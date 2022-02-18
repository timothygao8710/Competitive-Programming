//@timothyg

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back

#define f first
#define s second

struct modnum {
    // change these if you need another size of integers
    static inline uint32_t MOD;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;

    u32 n;

    modnum() : n(0) {}
    modnum(u64 v) : n(v >= MOD ? v % MOD : v) {}
    modnum(u32 v) : n(v >= MOD ? v % MOD : v) {}
    modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(MOD + v % int(MOD))) {}
    modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(MOD + v % int(MOD))) {}
    explicit operator i32() const { return n; }
    explicit operator u32() const { return n; }
    explicit operator bool() const { return n != 0; }

    static u32 fit(u32 x) { return x >= MOD ? x - MOD : x; }
    static int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = MOD;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? MOD + ny : ny;
    }
    friend modnum modpow(modnum b, int64_t e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    modnum inv() const { return modinv(n); }
    modnum operator-() const { return n == 0 ? n : MOD - n; }
    modnum operator+() const { return *this; }
    modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    modnum operator--(int) { return n = fit(MOD + n - 1), *this + 1; }
    modnum &operator++() { return n = fit(n + 1), *this; }
    modnum &operator--() { return n = fit(MOD + n - 1), *this; }
    modnum &operator+=(modnum v) { return n = fit(n + v.n), *this; }
    modnum &operator-=(modnum v) { return n = fit(MOD + n - v.n), *this; }
    modnum &operator*=(modnum v) { return n = (u64(n) * v.n) % MOD, *this; }
    modnum &operator/=(modnum v) { return *this *= v.inv(); }

    friend modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream &operator<<(ostream &out, modnum v) { return out << v.n; }
    friend istream &operator>>(istream &in, modnum &v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

//f(0) f(1) f(2) -f(3) -f(2)
const int maxn = 3e5 + 100;
vector<modnum> fib(maxn+10);
vector<modnum> gA(maxn+10), gB(maxn+10), A(maxn+10), B(maxn+10); 
set<int> diff;
int N, Q, MOD;
void change(int idx, modnum delta, int type){
    if(idx >= N+2) return;
    if(type){
        if(gB[idx] == gA[idx]) diff.insert(idx);
        gB[idx] += delta; 
        // gB[idx] %= MOD;
        if(gB[idx] == gA[idx]) assert(diff.count(idx)), diff.erase(idx);
    }else{
        if(gB[idx] == gA[idx]) diff.insert(idx);
        gA[idx] += delta; 
        // gA[idx] %= MOD;
        if(gB[idx] == gA[idx]) assert(diff.count(idx)), diff.erase(idx);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> Q >> MOD;
    modnum::MOD = MOD;
    fib[0] = fib[1] = 1;
    for(int i = 2; i<N+10; i++){
        fib[i] = fib[i-1] + fib[i-2];
        // fib[i] %= MOD;
    }
    
    for(int i = 2; i<N+2; i++) cin >> A[i], gA[i] = A[i];
    for(int i = 2; i<2+N; i++) cin >> B[i], gB[i] = B[i];
    for(int i = 2; i<2+N; i++){
        gA[i] -= (A[i-1] + A[i-2]);
        //  gA[i] %= MOD;
        gB[i] -= (B[i-1] + B[i-2]); 
        // gB[i] %= MOD;
        // cout << gB[i] << " " << endl;
        if(gA[i] != gB[i]) diff.insert(i);
    }
    while(Q--){
        char c; int l, r; cin >> c >> l >> r; l++, r++;
        change(l, 1, c == 'B');
        change(r+1, -fib[r-l+1], c == 'B');
        change(r+2, -fib[r-l], c == 'B');
        cout << (diff.empty() ? "YES" : "NO") << '\n';
        // for(int i = 2; i<N+2; i++) cout << gA[i] << " "; 
        // cout << endl;
        // for(int i = 2; i<N+2; i++) cout << gB[i] << " "; 
        // cout << endl;
    }
    return 0;
}
