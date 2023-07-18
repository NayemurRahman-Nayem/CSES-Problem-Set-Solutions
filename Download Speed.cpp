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




ll bfs(ll source, ll sink, vector<ll>& parent, vector<vector<ll>>& residualGraph) {
        fill(parent.begin(), parent.end(), -1);
        ll V = residualGraph.size();
        parent[source] = -2;
        queue<pair<ll, ll>> q;
        q.push({source, infLL});
        while (!q.empty()) {
                ll u = q.front().first ;
                ll capacity = q.front().second ;
                q.pop();
                for (ll av=1; av <= V; av++) {
                        if (u != av && parent[av] == -1 && residualGraph[u][av] != 0) {
                                parent[av] = u;
                                ll min_cap = min(capacity, residualGraph[u][av]);
                                if (av == sink)
                                return min_cap;
                                q.push({av, min_cap});
                        }
                }
        }
        return 0;
}


ll ford_fulkerson(vector<vector<ll>>& graph, ll source, ll sink) {
        vector<ll> parent(graph.size(), -1);
        vector<vector<ll>> residualGraph = graph;
        ll min_cap = 0, max_flow = 0;
        while (min_cap = bfs(source, sink, parent, residualGraph)) {
                max_flow += min_cap;
                ll u = sink;
                while (u != source) {
                        ll v = parent[u];
                        residualGraph[u][v] += min_cap;
                        residualGraph[v][u] -= min_cap;
                        u = v;
                }
        }
        return max_flow;
}


void solution() {

        ll n , m ; 
        cin >> n >> m ; 
        vector<vector<ll>> graph(n+1, vector<ll> (n+1, 0));
        for(ll i=0;i<m;i++) {
                ll u , v , w ; 
                cin >> u >> v >> w ; 
                graph[u][v] += w ; 
        }
        cout << ford_fulkerson(graph, 1, n) << endl; 
}




int main() {

        fastIO;
        //file() ;
        ll _ = 1; //cin >> _;
        while (_--) solution();
        return 0 ;
}
