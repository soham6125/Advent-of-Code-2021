#include<bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define endl             "\n"
#define sz(x)            (ll)((x).size())
#define lb               lower_bound
#define ub               upper_bound
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define print(a,n)       for(ll i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const ll mod = 1e9 + 7;
// const ll MAX  = 8000000000000000064LL;
const ll MIN  = -8000000000000000064LL;
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std;
 
const int dx[] = {-1,1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,-1,1,-1,1};

vll input = {68,30,65,69,5,78,41,73,55,0,76,98,79,42,37,21,9,34,56,33,64,54,24,43,15,58,61,38,12,20,4,26,87,95,94,89,83,74,97,77,67,40,63,88,19,31,81,80,60,14,18,47,93,57,17,90,84,85,48,6,91,7,86,13,51,53,8,16,23,66,36,39,32,82,72,11,52,28,62,70,59,50,1,46,96,71,35,10,25,22,27,99,29,45,44,3,75,92,49,2};

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    
    int tc = 1;
    // cin >> tc; 
    loop(0,tc,Q)
    {   
        // cout<<"Case #"<<q+1<<": ";
        vll v;
        vll ans;
        ll x;
        while(cin >> x) {
            v.pb(x);
        }
        ll tot = sz(v) / 25;
        ll matrix[tot][5][5];
        bool vis[tot][5][5];
        bool matrix_won[tot] = {false};
        ll ind = 0;

        loop(0, tot, i) {
            loop(0, 5, j) {
                loop(0, 5, k) {
                    matrix[i][j][k] = v[ind];
                    ind++;
                }
            }
        }

        loop(0, tot, i) {
            loop(0, 5, j) {
                loop(0, 5, k) {
                    vis[i][j][k] = false;
                }
            }
        }

        for(auto it: input) 
        {
            bool done = false;

            loop(0, tot, i) 
            {
                if(matrix_won[i]) continue;
                
                bool matrix_check = false;

                // mark the value
                loop(0, 5, j) {
                    loop(0, 5, k) {
                        if(matrix[i][j][k] == it) vis[i][j][k] = true;
                    }
                }

                // check if this matrix wins
                vll row_marked(5), col_marked(5);
                loop(0, 5, j)
                {
                    loop(0, 5, k)
                    {
                        row_marked[j] += (vis[i][j][k] == true);
                        col_marked[k] += (vis[i][j][k] == true);
                    }
                }
                loop(0, 5, j)
                {
                    if (row_marked[j] == 5 or col_marked[j] == 5 ) matrix_check = true;
                }

                // if matrix wins find the total score 
                if(matrix_check) {
                    matrix_won[i] = true;
                    ll sum = 0;
                    loop(0, 5, j) {
                        loop(0, 5, k) {
                            if(!vis[i][j][k]) sum += matrix[i][j][k];
                        }
                    }
                    sum *= it;
                    ans.pb(sum);
                    done = true;
                }
            }
        }

        cout << ans[sz(ans) - 1];
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}

// Your puzzle answer was 16830.