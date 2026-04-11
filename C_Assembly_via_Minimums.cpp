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

void solve() {
    ll n;
    cin>>n;
    ll n1=(n*(n-1))/2;
    unordered_map<ll,ll> umap1;
    rep(i,0,n1){
        ll x;
        cin>>x;
        umap1[x]++;
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    for(auto x:umap1){
        pq.push({x.first,x.second});
    }
    vll vec(n,-1);
    vec[n-1]=1000000000;
    ll i=0;
    while(!pq.empty()){
        ll f=pq.top().second;
        ll v1=pq.top().first;
        pq.pop();
        while(f>0){
            vec[i]=v1;
            f-=n-i-1;
            i++;
        }
    }
    vout(vec); 
}

int main() {
    fast_io;
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}