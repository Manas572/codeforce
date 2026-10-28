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

// -------- Binary Lifting / LCA --------
const int LOG = 20;
vector<vector<int>> adj, up;
vector<int> depth;

void dfs_lca(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs_lca(v, u);
    }
}

void build_lca(int n, int root = 1) {
    up.assign(n + 1, vector<int>(LOG, 0));
    depth.assign(n + 1, 0);
    dfs_lca(root, 0);
}

int kthAncestor(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = kthAncestor(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

// -------- Solve --------
void solve() {
    ll n,q;
    cin>>n>>q;
    vll vec(n);
    vin(vec,n);
    vll pref(n+1,0);
    rep(i,0,n){
        pref[i+1]=pref[i]+vec[i];
    }
    vll pref2(n+1,0);
    rep(i,1,n+1){
        pref2[i]+=pref[i]+pref2[i-1];
    }
    vll vec2;
    rep(i,1,n+1){
        vec2.pb((1ll*i*(i+1))/2);
    }
    while (q--)
    {
        ll l,r;
        cin>>l>>r;
        auto ind=lower_bound(all(vec2),l)-vec2.begin();
        ll prevl=ind;
        ll nval=(prevl*(prevl+1)/2);
        ll nl=l-nval;
        auto ind2=lower_bound(all(vec2),r)-vec2.begin();
        ll prevr=ind2;
        ll nval2=(prevr*(prevr+1))/2;
        ll nr=r-nval2;
        ll ans=0;
        if(ind==ind2){
            ans=pref[nr]-pref[nl-1];
        }else{
            ll ls=pref[ind+1]-pref[nl-1];
            ll rs=pref[nr];
            ll mb=pref2[ind2]-pref2[ind+1];
            ans=ls+rs+mb;
        }
        prt(ans);
    }
    
}

int main() {
    fast_io;
     solve();
    return 0;
}