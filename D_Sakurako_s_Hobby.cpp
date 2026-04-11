#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define print(x) cout << x << '\n'
#define ll long long
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
#define all(x) x.begin(), x.end()
#define sortv(v) sort(v.begin(), v.end())
#define rep(i, a, l) for (ll i = a; i < l; ++i)
#define rev(i, a, l) for (ll i = a; i >= l; --i)
#define chmin(a, l) (a = std::min(a, l))
#define chmax(a, l) (a = std::max(a, l))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define vmin(v) (*min_element(v.begin(), v.end()))
#define vmax(v) (*max_element(v.begin(), v.end()))
#define INF 1e18
#define vinit(type, name, size) vector<type> name(size)
#define MOD 1000000007
#define MAXN 100005
#define ld long double

using namespace std;

typedef vector<ll> vll;

 
ll findp(vector<ll>& parent, ll x) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent, parent[x]);
}
 
void unite(ll x, ll y, vector<ll>& parent, vector<ll>& rank) {
    ll px = findp(parent, x);
    ll py = findp(parent, y);
    if (px == py) return;
    if (rank[px] > rank[py]) {
        parent[py] = px;
    } else if (rank[py] > rank[px]) {
        parent[px] = py;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

void solve() {
    ll n;
    cin>>n;
    vll vec(n);
    vin(vec,n);
    vector<ll> parent(n), rank(n, 0);
    rep(i, 0, n) parent[i] = i;
    rep(i,0,n){
        vec[i]=vec[i]-1;
    }
    string s;
    cin>>s;
    rep(i,0,n){
        if((i)==vec[i]){
            continue;
        }
        unite(vec[i],i,parent,rank);
    }
    vll ans(n);
   rep(i,0,n){
    findp(parent,vec[i]);
   }
   unordered_map<ll,ll> umap;
   rep(i,0,n){
    if(s[i]=='0'){
        umap[parent[i]]++;
    }
   }
  
   rep(i,0,n){
    ans[i]= umap[parent[i]];
   }
   vout(ans);
}

int main() {
    fast_io;
    ll t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}