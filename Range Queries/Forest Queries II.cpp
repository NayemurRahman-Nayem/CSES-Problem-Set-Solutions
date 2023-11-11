#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
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

// ---------------------------------------------------------------------------------------------------------------------

ll fen[mx][mx], n, t , m ;
char grid[mx][mx] ; 

void update(ll x, ll y, ll add)
{
    while (x <= 1001)
    {
        ll y1 = y;
        while (y1 <= 1001)
        {
            fen[x][y1] += add;
            y1 = y1 + (y1 & (-y1));
        }
        x = x + (x & (-x));
    }
}

ll sum(ll x, ll y)
{
    ll s = 0;
    while (x > 0)
    {
        ll y1 = y;
        while (y1 > 0)
        {
            s += fen[x][y1];
            y1 = y1 - (y1 & (-y1));
        }
        x = x - (x & (-x));
    }
    return s;
}

void solution(int cs) {
    
    memset(fen, 0, sizeof(fen));
    cin >> n >> m ; 
    for(int i=1;i<=n;i++) {
        string s ; 
        cin >> s ; 
        for(int j=1;j<=n;j++) {
            grid[i][j] = s[j-1] ;
            if(grid[i][j]=='*') {
                update(i,j,1) ; 
            }  
        }
    }
    for(int i=1;i<=m;i++) {
        int t ; 
        cin >> t; 
        if(t==1) {
            ll x , y ; 
            cin >> x >> y ; 
            if(grid[x][y]=='*') {
                update(x,y,-1) ; 
                grid[x][y] = '.' ; 
            }
            else {
                update(x,y,1) ; 
                grid[x][y] = '*' ; 
            }

        }
        else {
            int x1 , y1 , x2 , y2 ; 
            cin >> x1 >> y1 >> x2 >> y2 ; 
            ll ans = sum(x2,y2) ; 
            ll k1 = 0 ; 
            if(y1>1) {
                ans -= sum(x2,y1-1) ;  
            }
            ll k2 = 0 ; 
            if(x1>1) {
                ans -= sum(x1-1,y2) ; 
            }
            ans += sum(x1-1,y1-1)  ;
            cout << ans el ;  
        }
    }
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
