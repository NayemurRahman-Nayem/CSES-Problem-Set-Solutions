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


vector<vector<int>>anc ;
int depth[mx] , vis[mx] , par[mx] ;
vector<int>adj[mx] ;
int n , q ; 
void dfs( int node , int d , int parent ) {

    depth[node] = d ;
    par[node] = parent ;
    vis[node] = 1 ;
    for( auto u:adj[node] ) {
        if( vis[u]==0 ) {
            dfs( u,d+1,node ) ;
        }
    }
}
// SparseTable formation
void preProcess( int root ) {                  // Binary Lifting 
    dfs(root,0,root) ; 
    LOG = 0 ;
    while( ( 1<<LOG)<= n ) {  
        LOG ++ ;
    }
    anc = vector<vector<int>>(n+1,vector<int>(LOG)) ;
    for(int j=0;j<LOG;j++) {
        for(int v=1;v<=n;v++) {
            if(j==0) {
                anc[v][j] = par[v] ;
            }
            else {
                anc[v][j] = anc[ anc[v][j-1] ][j-1] ;
            }
        }
    }
}
int LCA(int a , int b) {              

    if(depth[a] < depth[b]) {
        swap(a,b) ;
    }
    int k = depth[a] - depth[b] ;
    for(int j=LOG-1;j>=0;j--) {
        if(k>=(1<<j)) {
            a = anc[a][j] ;
            k -= (1<<j) ;
        }
    }
    if(a==b) {
        return a ;
    }
    for(int j=LOG-1;j>=0;j--) {
        if(anc[a][j]!=anc[b][j]) {
            a = anc[a][j] ;
            b = anc[b][j] ;
        }
    }
    return anc[a][0] ;
}


void solution(int cs) {

    cin >> n >> q ; 
    for(ll i=2;i<=n;i++) {
        ll boss ; 
        cin >> boss ; 
        adj[boss].pb(i) ; 
        adj[i].pb(boss) ; 
    }
    preProcess(1) ; 
    for(ll i=1;i<=q;i++) {
        ll x , k ; 
        cin >> x >> k ; 
        if(depth[x]<k) {
            cout << -1 el ; 
            continue; 
        }
        for(ll j=0;j<LOG;j++) {
            ll bitval = 1<<j; 
            if(bitval&k) {
                k-=bitval ; 
                x = anc[x][j] ; 
            }
            if(x==1) {
                break ; 
            }
        }
        cout << x el ; 
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
