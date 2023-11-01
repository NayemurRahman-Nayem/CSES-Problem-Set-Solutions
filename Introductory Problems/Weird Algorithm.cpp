//      BISMILLAH-HIR-RAHMAN-NIR-RAHIM              
//      All praise is due to ALLAH alone    
 
 
 
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;         
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
 
#define sa(v) sort(v.begin(), v.end())
#define sd(v) sort(v.begin(), v.end(), greater<>())
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 998244353 ;
const int mx = 5e5 + 123 ;
const double eps = 1e-7 ;
 
 
 
 
 
 
 
 
void solution()
{
        ll n ;
        cin >> n ;
        vl ans ;
        cout << n << " " ; 
        while(n!=1)
        {
                if(n%2==0) 
                {
                        n/=2;
                }
                else 
                { 
                        n = (n*3) +1 ;
                }
                cout << n << " "  ; 
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
