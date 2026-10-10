#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

// -------- PBDS --------
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

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

ll fun(ll ind,ll k,ll lastidx,vll& points,vll& time,ll cnt,vector<vector<vector<int>>>&dp,ll l){
    if(k<0){
        return INF;
    }
    ll last=0;
    if(lastidx==points.size()){
        last=l;
    }else{
        last=points[lastidx];
    }
    if(ind==0){
        return time[0]*last;
    }
    if(dp[ind][k][lastidx]!=-1){
        return dp[ind][k][lastidx];
    }
    ll dis=last-points[ind];
    ll val1=INF;
    ll val2=INF;
    if(k>0){
       val1= fun(ind-1,k-1,lastidx,points,time,cnt,dp,l);
    }
    val2=time[ind]*dis+fun(ind-1,k,ind,points,time,cnt+dis*time[ind],dp,l);
    dp[ind][k][lastidx] =min(val1,val2);
    return dp[ind][k][lastidx];
}
// -------- Solve --------
void solve() {
    ll n,l,k;
    cin>>n>>l>>k;
    vll points(n+1);
    vin(points,n);
    points[n]=l;
    vll time(n);
    vin(time,n);
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
    // prt(fun(n-1,k,n,points,time,0,dp,l));
    vector<vll> dp(n,+1);
    vll(k+1,INF);
    dp[0][0]=0;
    rep(i,1,n+1){
      for(int p=0;p<i;p++){
        ll rem=i-p-1;
        ll dis=points[i]-points[p];
        ll cost=dis*time[p];
        for(ll j=rem;j<=k;j++){
            if (dp[p][j - removed] == INF) continue;
        }
      }
    }
    ll ans=INF;
    rep(i,0,k+1){
        chmin(ans,dp[n-1][i]);
    }
    prt(ans);
}

int main() {
    fast_io;
     solve();
    return 0;
}