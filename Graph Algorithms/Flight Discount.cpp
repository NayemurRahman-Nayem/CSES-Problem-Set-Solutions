// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
using u64 = unsigned long long ; 
using uint64 = unsigned long long ; 
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


ll n , m ;
ll diss[mx] , disd[mx] ; 
bool viss[mx] , visd[mx] , vis[mx];   
vector<pair<ll,ll>>adjs[mx] , adjd[mx] ; 
ll ans = infLL ; 

void dijkstra1(ll source)
{
    for (int i = 1; i <= n ; i++)
            diss[i] = infLL  ; 
    diss[source] = 0;
    priority_queue<pair<ll,ll>> q ; 
    q.push({-0, source});
    while (!q.empty()) {
        ll cost = -1 * q.top().first;
        ll node = q.top().second;
        q.pop();
        if (diss[node] < cost)
            continue;
        for (auto i : adjs[node]) {
            ll adj_cost = i.first;
            ll adj_node = i.second;
            if (cost + adj_cost < diss[adj_node]) {
                diss[adj_node] = cost + adj_cost;
                q.push({-diss[adj_node], adj_node});
            }
        }
    }
}

void dijkstra2(ll source)
{
    for (int i = 1; i <= n ; i++)
            disd[i] = infLL  ; 
    disd[source] = 0;
    priority_queue<pair<ll,ll>> q ; 
    q.push({-0, source});
    while (!q.empty()) {
        ll cost = -1 * q.top().first;
        ll node = q.top().second;
        q.pop();
        if (disd[node] < cost)
            continue;
        for (auto i : adjd[node]) {
            ll adj_cost = i.first;
            ll adj_node = i.second;
            if (cost + adj_cost < disd[adj_node]) {
                disd[adj_node] = cost + adj_cost;
                q.push({-disd[adj_node], adj_node});
            }
        }
    }
}

void solution(int cs) {
    cin >> n >> m ; 
    map<pair<ll,ll>,ll>mp ; 
    for(int i=0;i<m;i++) {
        ll u , v , w ; 
        cin >> u >> v >> w ; 
        adjs[u].pb({w,v}) ;  
        adjd[v].pb({w,u}) ; 
        mp[{u,v}] = w ; 
    }
    dijkstra1(1) ; 
    dijkstra2(n) ; 
    for(auto it:mp) {
        ll u = it.first.first ; 
        ll v = it.first.second ; 
        ll w = it.second ; 
        ll sd = diss[u] ; 
        ll dd = disd[v] ; 
        if(sd!=infLL and dd!=infLL) {
            ans = min(ans,sd+dd+w/2) ; 
        }
    }
    cout << ans el ; 
}             
int main() { 
    fastIO ; 
    #ifndef ONLINE_JUDGE 
    file() ; 
    #endif 
    int cs = 1 ; 
    //cin >> cs ;  
    for(ll i=1;i<=cs;i++) solution(i) ; 
    return 0 ;
}
