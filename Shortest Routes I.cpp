//      BISMILLAH-HIR-RAHMAN-NIR-RAHIM              
//      All praise is due to ALLAH alone    
 
 
 
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;       
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
 
#define el << '\n'
#define pb push_back
#define file() freopen( "input.txt", "r", stdin); freopen("output.txt", "w", stdout )
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 10000000000000+1234 ;
const ll mod = 1000000007  ;
const int mx = 1e5 + 123 ;
 
 
ll dis[mx] ; 
vector<pair<ll,ll>> adj[mx] ; 
ll n , m; 
 
 
void dijkstra(ll source)
{
        for (int i = 1; i <= n ; i++)
                dis[i] = infLL  ; 
        dis[source] = 0;
 
        priority_queue<pair<ll,ll>> q ; 
        q.push({-0, source});
 
        while (!q.empty())
        {
                ll cost = -1 * q.top().first;
                ll node = q.top().second;
                q.pop();
                if (dis[node] < cost)
                        continue;
 
                for (auto i : adj[node])
                {
                        ll adj_cost = i.first;
                        ll adj_node = i.second;
                        if (cost + adj_cost < dis[adj_node])
                        {
                                dis[adj_node] = cost + adj_cost;
                                q.push({-dis[adj_node], adj_node});
                        }
                }
        }
}
 
 
 
void solution()
{
        cin >> n >> m ; 
        for(int i=0;i<m;i++)
        {
                ll u , v , w ; 
                cin >> u >> v >> w ;
                adj[u].pb({w,v}) ; 
        }
        dijkstra(1) ; 
        for(int i=1;i<=n;i++)
        {
                cout << dis[i] << " " ;
        }
}
 
 
int main()
{
        fastIO ;
        //file() ;
        int _ = 1; //cin >> _ ;
        while(_--) solution() ;
        return 0 ;
}
