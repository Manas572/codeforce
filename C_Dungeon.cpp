#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define prt(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define stv(v) sort(v.begin(), v.end())
#define rep(i, a, l) for (ll i = a; i < l; ++i)
#define rev(i, a, l) for (ll i = a; i >= l; --i)
#define chmin(a, l) (a = std::min(a, l))
#define chmax(a, l) (a = std::max(a, l))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vmin(v) (*min_element(v.begin(), v.end()))
#define vmax(v) (*max_element(v.begin(), v.end()))
#define INF 1e18
#define MOD 1000000007
#define MAXN 1000000

using namespace std;

typedef vector<ll> vll;

// -------- read() helper --------
template<typename... Args>
void read(Args&... args) {
    (cin >> ... >> args);
}

// -------- Custom gcd + lcm --------
ll gcdll(ll a, ll b) {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcdll(a, b) * b;
}

// -------- Binary Exponentiation --------
ll modpow(ll a, ll e, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % m;
        a = (a * a) % m;
        e >>= 1;
    }
    return res;
}

// -------- Fermat Little Theorem (mod inverse) --------
ll modinv(ll a, ll m = MOD) {
    return modpow(a, m - 2, m);
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
    ll n,m;
    read(n,m);
    vll a(n);
    vin(a,n);
    vll b(m);
    vin(b,m);
    vll c(m);
    vin(c,m);
    vll c0;
    vector<pair<ll,ll>>cg0;
    rep(i,0,m){
        if(c[i]==0){
            c0.pb(b[i]);
        }else{
            cg0.pb({b[i],c[i]});
        }
    }
    map<ll,ll>mpp;
    rep(i,0,n){
        mpp[a[i]]++;
    }
    ll cnt=0;
    stv(c0);
    stv(cg0);
    rep(i,0,cg0.size()){
     auto it=mpp.lower_bound(cg0[i].first);
     if(it==mpp.end()){
        break;
     }
     cnt++;
     ll val=it->first;
     mpp[val]--;
     if (mpp[val] == 0) mpp.erase(val);
     mpp[max(val,cg0[i].second)]++;
    }
    vll newa;
    for (auto &p : mpp) {
    ll val = p.first;
    ll freq = p.second;
    while (freq--) {
        newa.push_back(val);
    }
}
    ll sp=0,mp=0;
    while(sp<n && mp<c0.size()){
        if(c0[mp]>newa[sp]){
            sp++;
        }else{
            mp++;
            sp++;
            cnt++;
        }
    }
    prt(cnt);
}

int main() {
    fast_io;
    tc solve();
    return 0;
}