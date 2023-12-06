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
const ll mx = 1e5 + 10 ;
ll LOG = 21 ; 

// ---------------------------------------------------------------------------------------------------------------------


ll n , m ;
vl topological ; 
ll vis[mx] , dis[mx] ;
vector<int>adj[mx] ; 

bool isCycle() {
    queue<int> q; 
	vector<int> indegree(n+1,0); 
	for(int i=1;i<=n;i++) {
	    for(auto it: adj[i]) {
	        indegree[it]++; 
	    }
	}
	for(int i=1;i<=n;i++) {
	    if(indegree[i] == 0) {
	        q.push(i); 
	    }
	}
	int cnt = 0;
	while(!q.empty())  {
	    int node = q.front(); 
	    q.pop(); 
	    cnt++; 
	    for(auto it : adj[node]) {
	        indegree[it]--;
	        if(indegree[it] == 0)  {
	            q.push(it); 
	        }
	    }
	}
	if(cnt == n) return false; 
    return true ; 
}


void dfs(int u) {
    vis[u] = 1 ; 
    for(auto i:adj[u]) { 
        if(!vis[i]){
            dfs(i) ; 
        }
    }
    topological.pb(u) ; 
}

void topological_sort() { 
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            dfs(i) ; 
        }
    }
    reverse(topological.begin(),topological.end()) ; 
}

void solution(int cs) {
    cin >> n >> m ; 
    for(int i=0;i<m;i++) {
        int u , v  ; 
        cin >> u >> v  ; 
        adj[u].pb(v) ; 
    }
    if(isCycle()) {
        cout << "IMPOSSIBLE" el ;  
        return ; 
    }
    topological_sort() ; 
    for(auto i:topological) cout << i << " " ; 
    cout el ;
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
