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
#define el << '\n' ;
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
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 1e9 + 9 ;
const ll mx = 2e5 + 123 ;
ll tcc = 0 ;
ll fact[mx] , inv[mx] ;
ll ncr_modmPrime(ll n , ll r , ll m) {
        fact[0] = inv[0] = 1 ; for(ll i=1;i<mx;i++) {fact[i] = mod_mul(fact[i-1],i,m)  ; }
        inv[mx-1] = bin_expo(fact[mx-1],m-2,m) ;for(ll i=mx-2;i>=1;i--) {inv[i] = mod_mul(inv[i+1],(i+1),m) ; }
        ll up = fact[n] ; ll down = mod_mul(inv[r],inv[n-r],m) ; ll ans1 = mod_mul(up,down,m) ;return ans1 ;
}


// ---------------------------------------------------------------------------------------------------------------------


ll n , m ; 
ll adj[501][1001] , copyadj[501][1001]; 
bool vis[501] ; 
ll par[501] ; 


bool haspath() {

        for(ll i=0;i<=n;i++) {
                vis[i] = 0 ; 
        }
        vis[1] = 1 ; 
        queue<ll>q ; 
        q.push(1) ; 
        while(!q.empty()) {
                ll u = q.front() ; 
                q.pop() ;
                for(ll v=1;v<=n;v++) {
                        if(!vis[v] and adj[u][v]) {
                                q.push(v) ; 
                                par[v] = u ; 
                                vis[v] = 1 ; 
                        }
                }
        }
        return vis[n] ; 
}



void solution() {

        memset(par,-1,sizeof(par)) ; 
        cin >> n >> m ; 
        for(ll i=0;i<m;i++) {
                ll a , b ; 
                cin >> a >> b ; 
                adj[a][b] ++ ; 
                adj[b][a] ++ ; 
                copyadj[a][b] ++ ; 
                copyadj[b][a] ++ ; 
        }

        while(haspath()) {
                ll maxflow = infLL ; 
                ll currnode = n ; 
                while(par[currnode]!=-1) {
                        ll pre = par[currnode] ; 
                        adj[pre][currnode] -- ; 
                        currnode = pre ; 
                }
        }
        haspath() ; 
        vector<pll> ans ;  
        for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++) {
                        if(vis[i] and !vis[j] and copyadj[i][j]) {
                                ans.push_back({i,j}) ; 
                        }
                }
        }
        cout << ans.size() el ; 
        for(auto it:ans) {
                cout << it.first << " " << it.second el ;
        }
}




int main() {

        fastIO;
        //file() ;
        ll _ = 1; //cin >> _;
        while (_--) solution();
        return 0 ;
}
 