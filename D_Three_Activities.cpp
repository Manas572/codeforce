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

ll solve() {
    ll n;
    cin>>n;
    vector<vector<pair<ll,ll>>> vec(3);
    rep(i,0,3){
        rep(j,0,n){
            ll x;
            cin>>x;
            vec[i].push_back({x,j});
        }
    }
    rep(i,0,3) sortv(vec[i]);
    vector<pair<ll,ll>> ski;
    vector<pair<ll,ll>> mov;
    vector<pair<ll,ll>> boa;
    rev(i,n-1,n-3){
        ski.push_back({vec[0][i].first,vec[0][i].second});
    }
     rev(i,n-1,n-3){
        mov.push_back({vec[1][i].first,vec[1][i].second});
    }
     rev(i,n-1,n-3){
        boa.push_back({vec[2][i].first,vec[2][i].second});
    }
    ll maxval=-1;
    rep(i,0,3){
        rep(j,0,3){
            rep(k,0,3){
                ll val=0;
                unordered_set<ll> uset;
                uset.insert(ski[i].second);
                uset.insert(mov[j].second);
                uset.insert(boa[k].second);
                val=ski[i].first+mov[j].first+boa[k].first;
                if(uset.size()==3){
                     chmax(maxval,val);
                }
            }
        }
    }
    return maxval;
}

int main() {
    fast_io;
    ll t = 1;
     cin >> t;
    while (t--) {
        print(solve());
    }
    return 0;
}