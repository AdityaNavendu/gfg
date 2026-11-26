# CHFPARTY - Rating 1223

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Chef and Party

Tonight, Chef would like to hold a party for his $N$ friends.

All friends are invited and they arrive at the party one by one in an arbitrary order. However, they have certain conditions — for each valid $i$, when the $i$-th friend arrives at the party and sees that at that point, strictly less than $A_i$ other people (excluding Chef) have joined the party, this friend leaves the party; otherwise, this friend joins the party.

Help Chef estimate how successful the party can be — find the maximum number of his friends who could join the party (for an optimal choice of the order of arrivals).

### Input
- The first line of the input contains a single integer $T$ denoting the number of test cases. The description of $T$ test cases follows.
- The first line of each test case contains a single integer $N$.
- The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output

For each test case, print a single line containing one integer — the maximum number of Chef's friends who could join the party.

### Constraints
- $1 \le T \le 1,000$
- $1 \le N \le 10^5$
- the sum of $N$ over all test cases does not exceed $10^6$
### Sample 1:
Input
Output

```
3
2
0 0
6
3 1 0 0 5 5
3
1 2 3
```

```
2
4
0
```

### Explanation:

 **Example case 1:**  Chef has two friends. Both of them do not require anyone else to be at the party before they join, so they will both definitely join the party.

 **Example case 2:**  At the beginning, friends $3$ and $4$ can arrive and join the party, since they do not require anyone else to be at the party before they join. After that, friend $2$ can arrive; this friend would see that there are two people at the party and therefore also join. Then, friend $1$ will also join, so in the end, there would be $4$ people attending the party.

 **Example case 3:**  No one will attend the party because each of Chef's friends will find zero people at the party and leave, regardless of the order in which they arrive.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T09:59:07.702Z  

```c_cpp
/*===============================================================*
 |                       Aditya Navendu                          |
 |                                                               |  
 *===============================================================*/

#include <bits/stdc++.h>
using namespace std;

//---------------------- Typedefs ----------------------//

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int,int>;
using pll = pair<ll,ll>;

using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

//----------------------- Macros -----------------------//

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define pb push_back
#define eb emplace_back

#define F first
#define S second

#define sz(x) (int)(x).size()


#define input(a,n) for(auto &x:a) cin>>x

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#else
#define debug(x)
#endif

//--------------------- Constants ----------------------//

const ll INF = 4e18;
const int MOD = 1e9+7;
const int MAXN = 2000005;

//------------------- Math Functions -------------------//

ll gcdll(ll a,ll b){
    return b?gcdll(b,a%b):a;
}

ll lcmll(ll a,ll b){
    return a/gcdll(a,b)*b;
}

ll modpow(ll a,ll b,ll mod=MOD){
    ll ans=1;
    a%=mod;

    while(b){
        if(b&1)
            ans=ans*a%mod;

        a=a*a%mod;
        b>>=1;
    }

    return ans;
}

ll modinv(ll a){
    return modpow(a,MOD-2);
}

ll mod_add(ll a,ll b){
    return (a+b)%MOD;
}

ll mod_sub(ll a,ll b){
    return (a-b+MOD)%MOD;
}

ll mod_mul(ll a,ll b){
    return (a*b)%MOD;
}

//---------------------- Sieve -------------------------//

vector<bool> prime;

void sieve(int n){

    prime.assign(n+1,true);

    prime[0]=prime[1]=false;

    for(int i=2;i*i<=n;i++){

        if(prime[i]){

            for(int j=i*i;j<=n;j+=i)
                prime[j]=false;
        }
    }
}

bool isPrime(ll n){

    if(n<(int)prime.size())
        return prime[n];

    if(n<2)
        return false;

    for(ll i=2;i*i<=n;i++)
        if(n%i==0)
            return false;

    return true;
}

//------------------- Combinatorics --------------------//
/*
vector<ll> fact(MAXN),invfact(MAXN);

void init(){

    fact[0]=1;

    for(int i=1;i<MAXN;i++)
        fact[i]=fact[i-1]*i%MOD;

    invfact[MAXN-1]=modinv(fact[MAXN-1]);

    for(int i=MAXN-2;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%MOD;
}

ll nCr(ll n,ll r){

    if(r<0||r>n)
        return 0;

    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

ll nPr(ll n,ll r){

    if(r<0||r>n)
        return 0;

    return fact[n]*invfact[n-r]%MOD;
}
*/

//---------------- Extended Euclid ---------------------//

ll extended_gcd(ll a,ll b,ll &x,ll &y){

    if(b==0){

        x=1;
        y=0;

        return a;
    }

    ll x1,y1;

    ll g=extended_gcd(b,a%b,x1,y1);

    x=y1;
    y=x1-(a/b)*y1;

    return g;
}

//---------------- Utility Functions -------------------//

bool isPowerOfTwo(ll x){
    return x>0 && (x&(x-1))==0;
}

bool isPerfectSquare(ll x){

    if(x<0)
        return false;

    ll r=sqrtl(x);

    return r*r==x;
}
/*
vector<long long> divisors(long long n){
    vector<long long> v;

    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);

            if(i != n/i)
                v.push_back(n/i);
        }
    }

    return v;
}
*/
/*
vector<pair<long long,int>> factorize(long long n){
    vector<pair<long long,int>> v;

    for(long long p=2;p*p<=n;p++){
        if(n%p==0){
            int cnt=0;

            while(n%p==0){
                n/=p;
                cnt++;
            }

            v.push_back({p,cnt});
        }
    }

    if(n>1)
        v.push_back({n,1});

    return v;
}
int mex(vector<int>& a) {
    int n = a.size();
    vector<bool> present(n + 1, false);

    for (int x : a) {
        if (x <= n)
            present[x] = true;
    }

    for (int i = 0; i <= n; i++) {
        if (!present[i])
            return i;
    }

    return n + 1;
}
*/
/*
class DSU {
public:
    vector<int> parent, rank, sz;

    DSU(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
            sz[v] += sz[u];
        }
        else if (rank[u] > rank[v]) {
            parent[v] = u;
            sz[u] += sz[v];
        }
        else {
            parent[v] = u;
            rank[u]++;
            sz[u] += sz[v];
        }
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int size(int x) {
        return sz[find(x)];
    }
};
*/
/*
void dfs(int node, vector<int>&adj, vector<int>& vis){
    vis[node] = 1;

    

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}
*/
void solve(){
int n;
std::cin >> n;
vll a(n);
input(a,n);
int c=0;
sort(all(a));
for(int x:a){
  if(x<=c){
    c++;
  }
}
std::cout << c << std::endl;
}

//----------------------- Main -------------------------//

int main(){

    fastio;

    // init();
    // sieve(1000000);

    int T;
    cin>>T;

    while(T--)
        solve();

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CHFPARTY)