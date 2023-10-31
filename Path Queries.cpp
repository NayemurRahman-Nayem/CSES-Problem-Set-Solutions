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
ll LOG = 18 ; 

// ---------------------------------------------------------------------------------------------------------------------


ll eular[2*mx] ;
vl adj[mx] ; 
ll vis[mx] , Start[mx] , End[mx] , val[mx] ;  
ll  n , m , q ;


void dfs(ll node , ll &count) {
    
    vis[node] = 1 ; 
    Start[node] = count ; 
    eular[count] = val[node] ; 
    count ++ ; 
    for(auto u:adj[node]) {
        if(!vis[u]) {
            dfs(u,count) ; 
        }
    }
    End[node] = count ; 
    eular[count] = -1*val[node] ; 
    count ++ ;  
}

struct {
    ll sum;
} segtree[mx * 8];

ll Operation(ll x , ll y) {        
    return x+y ; 
}

void build(int node , int start , int end) {
    if(start==end) {
        segtree[node].sum = eular[end] ; 
        return ;
    }
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    build(left,start,mid) ;
    build(right,mid+1,end) ;
    segtree[node].sum = Operation(segtree[left].sum , segtree[right].sum ) ;
}

void update(int node , int start , int end , int l , int r , ll x ) {
    if(l>end || r<start) return ;
    if(l<=start and end<=r){
        segtree[node].sum = x ;
        return ;
    }
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    update(left,start,mid,l,r,x) ;
    update(right,mid+1,end,l,r,x) ;
    segtree[node].sum = segtree[left].sum + segtree[right].sum ;
}

ll query(int node, int start, int end , int l,  int r) {
    if (l > end || r < start) {
        return 0 ;
    }
    if (start >= l and end <= r) {
        return segtree[node].sum ;
    } 
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    ll p1 = query(left, start , mid, l , r ) ; 
    ll p2 = query(right, mid + 1, end , l , r ) ;
    return Operation(p1,p2) ; 
}


void solution(int cs) {

    cin >> n >> q ; 
    for(ll i=1;i<=n;i++) {
        cin >> val[i] ; 
    }
    for(ll i=1;i<n;i++) {
        ll a , b ; 
        cin >> a >> b ; 
        adj[a].pb(b) ; 
        adj[b].pb(a) ; 
    }
    ll count = 1 ; 
    dfs(1,count) ; 
    build(1,1,2*n) ;  
    for(ll i=1;i<=q;i++) {
        ll t ; 
        cin >> t; 
        if(t==1) {
            ll s , x ; 
            cin >> s >> x ;
            val[s] = x ; 
            update(1,1,2*n,Start[s],Start[s],x) ; 
            update(1,1,2*n,End[s],End[s],-1*x) ;  
        }
        else {
            ll s ; 
            cin >> s; 
            cout << query(1,1,2*n,Start[1],Start[s]) el ; 
        }
    }
}


int main() { 

    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    int cs = 1 ;
    //cin >> cs ;
    for(int i=1;i<=cs;i++) solution(i) ;
    return 0 ;
}