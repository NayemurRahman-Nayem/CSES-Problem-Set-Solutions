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
const ll mx = 2e5 + 10 ;
ll LOG = 21 ; 

// ---------------------------------------------------------------------------------------------------------------------

ll a[mx] , currans = 0 , ans[mx] , cnt[mx] ; 
ll block = 500 ; 
struct Query {
    int idx , l , r , lb , ub ; 
} Q[mx] ; 
void add_element(int index) {     // update add function 
    cnt[a[index]] ++ ; 
    if(cnt[a[index]]==1) {
        currans ++ ; 
    }
}
void remove_element(int index) {  // update remove function
    cnt[a[index]] -- ; 
    if(cnt[a[index]]==0) {
        currans -- ; 
    }
}
bool cmp(Query q1 , Query q2 ) {
    ll x = q1.l/block ; 
    ll y = q2.l/block ; 
    if(x!=y) {
        return x<y ; 
    }
    return q1.r < q2.r ;
}


void solution(int cs) {
    ll n , q ; 
    cin >> n >> q ; 
    map<ll,ll>mp ;
    ll itr = 0 ;  
    for(ll i=1;i<=n;i++) {
        cin >> a[i] ;
        if(mp[a[i]]==0) {
            mp[a[i]] = ++itr ;  
        } 
        a[i] = mp[a[i]] ; 
    }
    for(ll i=1;i<=q;i++) {
        ll l , r; 
        cin >> l >> r ; 
        Q[i].idx = i ; 
        Q[i].lb = l/block ; 
        Q[i].ub = r/block ;
        Q[i].l = l ; 
        Q[i].r = r ;  
    }
    sort(Q+1,Q+1+q,cmp) ; 
    for(ll i=1,R=0,L=1;i<=q;i++) {
        while(R<Q[i].r) add_element(++R) ; 
        while(L>Q[i].l) add_element(--L) ; 
        while(R>Q[i].r) remove_element(R--) ; 
        while(L<Q[i].l) remove_element(L++) ; 
        ans[Q[i].idx] = currans ; 
    }
    for(ll i=1;i<=q;i++) {
        cout << ans[i] el ; 
    }
}             

int main() { 
    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    int t = 0 ; 
    int cs = 1 ;
    //cin >> cs ;  
    for(ll i=1;i<=cs;i++) solution(i) ; 
    return 0 ;
}
