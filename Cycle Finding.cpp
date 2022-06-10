                                      //"IN THE NAME OF ALLAH"//
 
 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
// --------------------------------------------------------------------------------------------------------------->
 
#define el << '\n'
#define pb push_back
#define PI 3.141592653589793238
#define _test_ int _ ; cin >> _ ; while( _-- )
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
 
// --------------------------------------------------------------------------------------------------------------->
 
int dx[]={0,0,+1,-1,+1,-1,-1,+1};
int dy[]={+1,-1,0,0,+1,-1,+1,-1};
const ll infLL = 1e17+123;
const ll inf = 1e16+7;
const int mod = 1e9+7;
const ll mx = 5e3+123;
 
// --------------------------------------------------------------------------------------------------------------->
int n,m,x;
ll dis[mx],par[mx];
struct e
{
    int u,v,w;
};
vector<e>edge;
 
bool Bellman_Ford(int source)
{
    for(int i=1;i<=n;i++) dis[i]=infLL;
    dis[source]=0;
    x=-1;
    for(int i=1;i<=n;i++)
    {
        x=-1;
        for(int j=0;j<edge.size();j++)
        {
            int u=edge[j].u;
            int v=edge[j].v;
            int w=edge[j].w;
            if( dis[u]+w < dis[v] )
            {
                dis[v]=max( dis[u]+w,-infLL );
                par[v]=u;
                x=v;
            }
        }
    }
    return x!=-1;
}
 
void _case_()
{
    edge.clear();
    cin >> n >> m ;
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        edge.pb({u,v,w});
    }
    if(!Bellman_Ford(1)) cout << "NO\n";
    else
    {
        vi path;
        for(int i=1;i<=n;i++)
        {
            x=par[x];
        }
        int y=x;
        while(y!=x || path.size()==0)
        {
            path.pb(y);
            y=par[y];
        }
        path.pb(x);
        reverse(path.begin(),path.end());
        cout << "YES\n";
        for(auto i:path) cout << i << " ";
        cout el;
    }
}
 
int main()
{
    optimize();
    //_test_
      _case_();
    return 0;
}
//  
