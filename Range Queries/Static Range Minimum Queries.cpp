// Bismillahir Rahmanir Rahim
 
 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<ll, ll> pll ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#define pb push_back
#define el << '\n' ;
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).begin(),(a).end()
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m) {
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll ncr(ll n , ll r) {ll mul = 1 ; for(ll i=1;i<=r;i++) {mul = mul * (n-i+1) ; mul = mul/i ; }return mul ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 2e5 + 1 ;
const ll LOG = 17 ;
 
// ---------------------------------------------------------------------------------------------------------------------
 
 
ll sps[mx][LOG]  ;
ll lg[mx] , a[mx] ;
 
ll query(ll l, ll r) {
    ll length = r - l + 1 ;
    ll k = lg[length] ;
    return min(sps[l][k],sps[r-(1<<k)+1][k]) ;
}
 
 
 
void solution(ll cs) {
 
    ll n , q ;
    cin >> n >> q ;
    lg[1] = 0 ;
    for(ll i=2;i<=n;i++) {
        lg[i] = lg[i/2] + 1 ;
    }
    for(ll i=1;i<=n;i++) {
        cin >> a[i] ;
        sps[i][0] = a[i] ;
    }
    for(ll k=1;k<=lg[n];k++) {
        for(ll i=1;i+(1<<k)-1<=n;i++) {
            sps[i][k] = min(sps[i][k-1],sps[i+(1<<(k-1))][k-1]) ;
        }
    }
    for(ll i=0;i<q;i++) {
        ll l , r ;
        cin >> l >> r ;
        cout << query(l,r) << endl ;
    }
}
 
 
int main() {
 
    fastIO  ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    ll cs = 1 ;
    //cin >> cs ;
    for(ll i=1;i<=cs;i++) solution(i) ;
    return   0 ;
}
