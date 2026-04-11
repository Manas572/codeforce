#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define print(x) cout << x << '\n'
#define ll long long
#define tc ll t; cin >> t; while(t--)
#define vin(v, n) for (ll i = 0; i < n; ++i) cin >> v[i]
#define vout(v) for (auto &x : v) cout << x << ' '; cout << '\n'
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define pb push_back
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
    ll n,m;
    cin>>n>>m;
    vll vec(m);
    vin(vec,m);
    if(m==n){
        print(n);
        return;
    }
    vll inf;
    sortv(vec);
    ll v=vec[0]-1;
    v+=n-vec.back();
    inf.pb(v);  
    rep(i,1,m){
        v=vec[i]-vec[i-1]-1;
        inf.pb(v);   
    }
    sort(all(inf),greater<ll>());
    ll d=0;
    ll sa=0;
    rep(i,0,inf.size()){
        ll v1=inf[i];
        if(i==0){
           if(v1>1) v1-=1;
        }else{
            v1=v1-(2*d);
           if(v1>1) v1=v1-1;
        }
        if(v1>0){
            sa+=v1;
        }else{
            break;
        }
        d+=2;
    }
    print(n-sa);

}

int main() {
    fast_io;
    tc
     solve();
    return 0;
}