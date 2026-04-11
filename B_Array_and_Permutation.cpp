#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define prt(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(uni, n) for (ll i = 0; i < n; ++i) cin >> uni[i]
#define vout(uni) for (auto &x : uni) cout << x << ' '; cout << '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define stv(uni) sort(uni.begin(), uni.end())
#define rep(i, arr, l) for (ll i = arr; i < l; ++i)
#define rev(i, arr, l) for (ll i = arr; i >= l; --i)
#define chmin(arr, l) (arr = std::min(arr, l))
#define chmax(arr, l) (arr = std::max(arr, l))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vmin(uni) (*min_element(uni.begin(), uni.end()))
#define vmax(uni) (*max_element(uni.begin(), uni.end()))
#define INF 1e18
#define MOD 1000000007
#define MAXN 1000000

using namespace std;

typedef vector<ll> vll;


typedef pair<ll,ll> pll;


typedef vector<pll> vpll;


// -------- Custom gcd + lcm --------
ll gcdll(ll arr, ll b) {
    arr = llabs(arr);
    b = llabs(b);
    while (b != 0) {
        ll r = arr % b;
        arr = b;
        b = r;
    }
    return arr;
}

ll lcm(ll arr, ll b) {
    return arr / gcdll(arr, b) * b;
}

// -------- Binary Exponentiation --------
ll modpow(ll arr, ll e, ll m = MOD) {
    arr %= m;
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * arr) % m;
        arr = (arr * arr) % m;
        e >>= 1;
    }
    return res;
}

// -------- Fermat Little Theorem (mod inverse) --------
ll modinv(ll arr, ll m = MOD) {
    return modpow(arr, m - 2, m);
}

// -------- Number of Divisors --------
ll countDivisors(ll n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ll cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
    }
    if (n > 1) ans *= 2;
    return ans;
}

// -------- Combinatorics --------
vll fact, invfact;

void init_combinatorics(int n = MAXN) {
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;

    invfact.assign(n + 1, 1);
    invfact[n] = modinv(fact[n]);
    for (int i = n; i >= 1; --i)
        invfact[i - 1] = invfact[i] * i % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// -------- Prime Factor Sieve --------
vector<vector<int>> pf;

void init_prime_factors(int N = 200000) {
    pf.assign(N + 1, {});
    for (int i = 2; i <= N; i++) {
        if (pf[i].empty()) {
            for (int j = i; j <= N; j += i)
                pf[j].push_back(i);
        }
    }
}

// -------- Solve --------
void solve() {
    ll n;
    cin >> n;
    vll per(n);
    vll arr(n);
    vin(per, n);
    vin(arr, n);
   vll newarr;
   map<ll,ll>mp2;
   rep(i,0,n){
    mp2[per[i]]=i;
   }
   ll p=-9;
   rep(i,0,n){
    if(arr[i]!=p){
        newarr.pb(arr[i]);
    }
    p=arr[i];
   }
   map<ll,ll>mp;
   rep(i,0,newarr.size()){
    mp[newarr[i]]++;
   }
   for(auto x:mp){
    if(x.second>1){
        NO;
        return;
    }
   }
   p=-9;
   rep(i,0,newarr.size()){
    if(mp2[newarr[i]]<p){
        NO;
        return;
    }
    p=mp2[newarr[i]];
   }
   YES;
}

int main() {
    fast_io;
    tc solve();
    return 0;
}