#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define prt(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
#define llmax LLONG_MAX
#define llmin LLONG_MIN
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
#define vinit(type, name, size) vector<type> name(size)
#define MOD 1000000007
#define MAXN 1000000
#define ld long double

using namespace std;

typedef vector<ll> vll;


template<typename... Args>
void read(Args&... args) {
    (cin >> ... >> args);
}

void solve() {
    ll n,m;
    read(n,m);
    map<ll,vector<pair<ll,ll>>>mp;
    rep(i,0,m){
        ll u,v;
        char c;
        read(u,v,c);
        ll v2=0;
        if(c=='R'){
            v2=1;
        }else{
            v2=-1;
        }
        mp[u].pb({v,v2});
        mp[v].pb({u,v2});
    }
    ll o=n;
    vector<vector<ll>> dist;
   dist.resize(n + 1); 
   rep(i,0,n+1) {
    dist[i] = vll(2 * n + 1, -1);
}
    queue<pair<ll,ll>> q;
    q.push({1, 0});
    rep(i,0,n){

    }
    dist[1][0 + o] = 0;
    ll ans=-1;
    while (!q.empty()) {
        ll u = q.front().first;
        ll bal = q.front().second;
        q.pop();
        ll d = dist[u][bal + o];
        if (u == n && bal == 0) {
            ans=d;
          break;
        }
        for (auto& edge : mp[u]) {
            int v = edge.first;
            int change = edge.second;
            int nb = bal + change;
            if (abs(nb) <= n) {
                if (dist[v][nb + o] == -1) {
                    dist[v][nb + o] = d + 1;
                    q.push({v, nb});
                }
            }
        }
    }

    prt(ans);
}



int main() {
    fast_io;
        solve();
    return 0;
}
