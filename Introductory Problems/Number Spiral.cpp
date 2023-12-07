//      BISMILLAH-HIR-RAHMAN-NIR-RAHIM
//      All praise is due to ALLAH alone
 
 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef pair<int, int> pii ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
 
 
 
#define el << '\n'
#define pb push_back
#define file() freopen( "input.txt", "r", stdin); freopen("output.txt", "w", stdout )
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
 
 
 
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 10000000000000+1234 ;
const ll mod = 1000000007  ;
const int mx = 1e6 + 123 ;
 
 
 
void solution()
{
        ull row , col ; 
        cin >> row >> col ; 
        if(row>col)
        {
                ull up = row * row ; 
                ull down = (row-1) * (row-1) ;
                down ++ ;
                if(row%2)
                {
                        cout << down + col -1 el ;  
                }
                else 
                {
                        cout << up - col + 1  el ;
                }
        }
        else 
        {
                ull up = col* col ; 
                ull down = (col-1) * (col-1) ; 
                down ++ ;
                if(col%2) 
                {
                        cout << up - (row-1) el ;  
                } 
                else 
                {
                        cout << down +  (row-1) el; 
                }
        }
}
 
 
int main()
{
        fastIO ;
        //file() ;
        int _ = 1; cin >> _ ;
        while(_--) solution() ;
        return 0 ;
}
