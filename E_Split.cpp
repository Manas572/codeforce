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
    ll n,k;
    cin>>n>>k;
    vll vec(n);
    vin(vec,n);
    map<ll,ll> f;
    rep(i,0,n){
        f[vec[i]]++;
    }
    map<ll,ll> limit;
    ll ans=0;
    for(auto x:f){
        if((x.second%k)!=0){
            print(0);
            return;
        }else{
            limit[x.first]=x.second/k;
        }
        ans+=x.second;
    }
    ll l=0,r=0;
    map<ll,ll>tf;
    while(r<n){
        tf[vec[r]]++;
        while(tf[vec[r]]>limit[vec[r]]){
            tf[vec[l]]--;
            l++;
        }
        ll v=r-l+1;
        ans+=v-1;
        r++;
    }
    print(ans);
}

int main() {
    fast_io;
    tc
     solve();
    return 0;
}