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

// -------- Solve --------
void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<int, char>> freq(26);
    for(int j=0; j<26; j++) freq[j] = {0, j+'a'};
    for(char c : s) freq[c-'a'].first++;
    unordered_map<char,ll> umap;
    stv(freq);
    rep(i,0,26){
        umap[freq[i].second]=i;
    }
    ll m1=n+5;
    ll ans=-1;
    rep(i,1,n+1){
        if((n%i)!=0){
            continue;
        }
        if(n/i>26){
            continue;
        }
       ll cnt1=0,cnt2=0;
       rep(j,0,26){
        if(freq[j].first==0 || freq[j].first==i){
            continue;
        }
        if(freq[j].first<i){
            cnt1+=i-freq[j].first;
        }else{
            cnt2+=freq[j].first-i;
        }
       }
       ll m3=min(cnt1,cnt2);
       ll tans=m3;
       cnt1-=m3;
       cnt2-=m3;
       if(cnt1>0){
        ll v=0;
        rep(j,0,26){
            if(freq[j].first==0){
                continue;
            }
            if(freq[j].first>=i){
                break;
            }
            if(cnt1>0){
                cnt1-=i;
                v+=freq[j].first;
            }
        }
        tans+=v;
       }
       tans+=cnt2;
       //cout<<i<<" "<<tans<<endl;
       if(tans<m1){
        ans=i;
        m1=tans;
       }
    }
    // vll ind1,ind2;
    // rep(i,0,n){
    //     if(freq[umap[s[i]]].first==ans){
    //         continue;
    //     }
    //     if(freq[umap[s[i]]].first>ans){
    //         ind1.pb(i);
    //         freq[umap[s[i]]].first--;
    //     }
    //     if(freq[umap[s[i]]].first<ans){
    //         ind2.pb(i);
    //         freq[umap[s[i]]].first++;
    //     }
    // }
    // if(ind1.size()==ind2.size()){
    //     rep(i,0,ind1.size()){
    //         s[ind1[i]]=s[ind2[i]];
    //     }
    // }else if(ind1.size()<ind2.size()){
    //     rep(i,0,ind1.size()){
    //         s[ind1[i]]=s[ind2[i]];
    //     }
    //     // will pair up ind2
    // }else{
    //     rep(i,0,ind2.size()){
    //         s[ind1[i]]=s[ind2[i]];
    //     }
    //     // will pair ind1 with 0 freq
    // }
    ll k=n/ans;
    vector<bool> good(26,0);
    rep(i,0,k){
        good[freq[25-i].second-'a']=true;
    }
    vll tar(26,0);
    rep(i,0,26){
        if(good[i]){
            tar[i]=ans;
        }
    }
    vll ind1,ind2;
    rep(i,0,n){
        if(freq[umap[s[i]]].first>tar[s[i]-'a']){
            ind1.pb(i);
            freq[umap[s[i]]].first--;
        }
    }
    rep(i,0,26){
        while(freq[umap[i+'a']].first<tar[i]){
            ind2.pb(i);
            freq[umap[i+'a']].first++;
        }
    }
    rep(i,0,ind1.size()){
        s[ind1[i]]='a'+ind2[i];
    }
    prt(m1);
    prt(s);
}

int main() {
    fast_io;
    tc solve();
    return 0;
}