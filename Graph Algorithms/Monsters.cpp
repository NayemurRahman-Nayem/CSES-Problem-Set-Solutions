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
const ll mx = 1e3 + 10 ;
ll LOG = 21 ; 

// ------------------------------------------------------------------------------------------------------------------


char grid[mx][mx] ; 
ll n , m ; 
int levA[mx][mx] , levM[mx][mx] ;   
bool blocked[mx][mx] ;
bool visA[mx][mx] , visM[mx][mx] , vis[mx][mx] ; 
pair<ll,ll> init ; 
vector<pair<ll,ll>> monsters ; 
string ans = "" ; 
string s = "LRUD" ;  
bool reached = false ; 


void bfs(int x, int y , int k ) {
    if(k==1) {
        visA[x][y] = 1 ; 
    }
    else {
        visM[x][y] = 1 ; 
    }
    queue<pair<ll,ll>> q ; 
    q.push({x,y}) ; 
    while(!q.empty()) {
        int x1 = q.front().first ; 
        int y1 = q.front().second ;
        q.pop() ;  
        for(int i=0;i<4;i++) {
            int x2 = x1 + dx[i] ; 
            int y2 = y1 + dy[i] ;
            if(x2<1 || n<x2 || y2<1 || m<y2 ) continue;
            if(grid[x2][y2]=='.') {
                if(k==1) {
                    if(!visA[x2][y2]) {
                        levA[x2][y2] = levA[x1][y1] + 1 ; 
                        visA[x2][y2] = 1 ; 
                        q.push({x2,y2}) ; 
                    }
                }
                else {
                    if(!visM[x2][y2] and levA[x2][y2]>=levM[x1][y1]+1) {
                        blocked[x2][y2] = 1 ;  
                        levM[x2][y2] = levM[x1][y1] + 1 ; 
                        visM[x2][y2] = 1; 
                        q.push({x2,y2}) ; 
                    }
                }
            }
        }
    } 
}


void dfs(int x , int y ) {
    if(x==init.first and y==init.second) {
        reached = 1 ; 
        return ; 
    }
    vis[x][y] = 1 ; 
    for(int i=0;i<4;i++) {
        int x1 = x + dx[i] ; 
        int y1 = y + dy[i] ; 
        if(x1>=1 and x1<=n and y1>=1 and y1<=m and (grid[x1][y1]=='.' || grid[x1][y1]=='A' ) and blocked[x1][y1]==0 and vis[x1][y1]==0 and levA[x][y]>levA[x1][y1]) {
            ans += s[i] ; 
            dfs(x1,y1) ; 
        }
    }  
}

void solution(int cs) { 
    cin >> n >> m ; 
    for(int i=1;i<=n;i++) { 
        string s ; 
        cin >> s ; 
        for(int j=1;j<=m;j++) { 
            grid[i][j] = s[j-1] ;  
            if(grid[i][j]=='M') {
                monsters.pb({i,j}) ; 
            }
            if(grid[i][j]=='A') {
                init.first = i ; 
                init.second = j ; 
            }
        } 
    } 
    if((init.first==1 || init.first==n) && (init.second==1 || init.second==m)) {
        cout << "YES" el ; 
        cout << 0 el ; 
        return ; 
    } 
    bfs(init.first,init.second,1) ; 
    for(auto it:monsters) {
        bfs(it.first,it.second,0) ; 
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if((i==1 || i==n || j==1 || j==m) and grid[i][j]=='.') {
                if(blocked[i][j]==0) {
                    dfs(i,j) ; 
                    if(reached) {
                        reverse(all(ans)) ; 
                        cout << "YES" el ; 
                        cout << ans.size() el ; 
                        for(auto it:ans) {
                            cout << it ; 
                        }
                        cout el ;
                        return ; 
                    } 
                    ans.clear() ; 
                }
            }
        }
    }
    cout << "NO" el ; 
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
