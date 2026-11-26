# NODDSM - Rating 1041

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### No Odd Sum

There are $N$ numbers written on a blackboard. The $i$-th number is denoted as $A_i$.
The blackboard is said to be  *good*  if, for each pair of indices $(i, j)$ with $1 \leq i \lt j \leq N$, the sum $(A_i + A_j)$ is an even number.

The blackboard might not be  *good*  initially, so you want to make it  *good*.
To do this, you can perform the following two types of operations:

- Erase a $2$ from the blackboard, and in its place write two occurrences of $1$. Of course, this can only be done when there's at least one occurrence of $2$ on the blackboard.
- Erase two occurrences of $1$ from the blackboard, and in their place write a single occurrence of $2$. Of course, this can only be done when there are at least two occurrences of $1$ on the blackboard.

The above operations can be performed in any order, and each operation can be used however many times you like.
Find the minimum number of operations needed to make the blackboard  *good*.
It can be proved that it's always possible to make the blackboard  *good*.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$ — the number of values written on the blackboard initially. The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, output on a new line the minimum number of operations needed to make the blackboard  *good*.

### Constraints
- $1 \leq T \leq 100$
- $1 \leq N \leq 100$
- $1 \leq A_i \leq 2$
### Sample 1:
Input
Output

```
3
4
1 1 2 2
4
1 1 1 1
5
1 2 1 2 1

```

```
1
0
2

```

### Explanation:

 **Test case $1$:**  The blackboard is initially not good: it has both a $1$ and a $2$, and we have $1+2 = 3$ being odd.
Perform a single operation: remove the two occurrences of $1$ from the blackboard, and write a $2$. Now, there are three $2$'s on the blackboard.
Each pair of them has a sum of $4$, which is even. So, one operation is enough.

 **Test case $2$:**  The blackboard is already good.

 **Test case $3$:**  Perform two operations: in each operation, replace a $2$ with two $1$'s.
In the end, there will be $7$ ones on the blackboard, but it'll be good.
It can be proved that this is optimal.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T09:00:51.045Z  

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
int o=std::count(a.begin(), a.end(), 1);
int tw=std::count(a.begin(), a.end(), 2);
if(o==0 or tw==0){
  std::cout << 0 << std::endl;
}else if(o<=tw){
  std::cout << o/2 << std::endl;
}else{
  std::cout << tw << std::endl;
}
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

[View on CodeChef](https://www.codechef.com/problems/NODDSM)