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
using u64 = unsigned long long ; 
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

vl adj[mx] ; 
ll vis[1003][1004] , m , n ; 
char grid[1003][1004] ; 
ll xs , ys , xd , yd ; 
string dir = "RLDU" ; 
ll lev[1003][1003] ; 
char cval[1003][1003] ; 
ll parx[1003][1003] , pary[1003][1003] ; 
string ans = "" ; 
bool found = false ; 

void bfs(ll x , ll y ) {
    queue<pair<ll,ll>>q ; 
    q.push({x,y}) ; 
    vis[x][y] = 1 ; 
    while(!q.empty()) {
        ll tx = q.front().first ; 
        ll ty = q.front().second ; 
        q.pop() ; 
        for(int i=0;i<4;i++) {
            int x1 = tx + dx[i] ; 
            int y1 = ty + dy[i] ; 
            if(x1>=1 and x1<=n and y1>=1 and y1<=m and !vis[x1][y1] and grid[x1][y1]!='#') {
                lev[x1][y1] = lev[tx][ty] + 1 ; 
                cval[x1][y1] = dir[i] ; 
                parx[x1][y1] = tx ; 
                pary[x1][y1] = ty ; 
                vis[x1][y1] = 1 ; 
                q.push({x1,y1}) ; 
            }
        }
    }
} 

void rec(ll x , ll y) {
    if(x==xs and y==ys) {
        return ; 
    }
    char c = cval[x][y] ;
    ans += c ;  
    rec(parx[x][y],pary[x][y]) ; 
}

void solution(int cs) {
    cin >> n >> m ; 
    for(int i=1;i<=n;i++) {
        string s ; 
        cin >> s ; 
        for(int j=1;j<=m;j++) {
            lev[i][j] = -1 ; 
            grid[i][j] = s[j-1] ; 
            if(grid[i][j]=='A') {
                xs = i ; 
                ys = j ; 
            }
            if(grid[i][j]=='B') {
                xd = i ; 
                yd = j ; 
            }
        }
    }
    lev[xs][ys] = 0 ; 
    bfs(xs,ys) ;
    if(lev[xd][yd]==-1) {
        cout << "NO" el ; 
        return ; 
    }
    cout << "YES" el ; 
    cout << lev[xd][yd] el ; 
    rec(xd,yd) ;  
    reverse(all(ans)) ; 
    cout << ans el ; 
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
