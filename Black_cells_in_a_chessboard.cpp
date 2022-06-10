//     بسم الله الرحمن الرحيم     //
 
 
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
 
 
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18;
const ll inf = 1e16 + 7;
const ll mod = 1e9 + 7;
const int mx = 1e6 + 123;
 
 
int main()
{
        
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int tc = 1;
        //cin >> tc;
        while (tc--)
        {
                       
                int n,ans=0,k=2;
                cin >> n;
                for(int i=1;i<=n;i++)
                {
                        k == 1 ? k = 2  : k = 1 ;
                        for(int j=1;j<=n;j++)
                        {
                                if(k&1 and j%2==0) ans++;
                                else if(k%2==0 and j&1) ans++; 
                        }
                }
                cout << ans el;
        }
        return 0;
}