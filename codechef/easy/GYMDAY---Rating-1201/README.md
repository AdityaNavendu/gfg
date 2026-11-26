# GYMDAY - Rating 1201

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### International Gym Day

On the account of International Gym Day, Chefland gym has a special discount offer for a lifetime membership.

Chef is taking trial sessions at the gym where he pays $1$ coin per session. For every trial session Chef takes, he is eligible for an  **additional**  $D$ $\%$ discount while taking the lifetime membership.

Given that the membership costs $X$ coins and Chef has a  **total budget**  of $Y$ coins, find the minimum number of trial sessions he needs to take so that he can purchase the lifetime membership.
If it is impossible for him to get the lifetime membership, print $-1$ instead.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of three space-separated integers $D, X,$ and $Y$ — the additional discount Chef gets by attending one trial session, the cost of lifetime membership, and Chef's budget respectively.
### Output Format

For each test case, output on a new line, the minimum number of trial sessions Chef needs to take so that he can purchase the lifetime membership.

If it is impossible for him to get the lifetime membership, print $-1$ instead.

### Constraints
- $1 \leq T \leq 6400$
- $1 \leq D \leq 5$
- $1 \leq Y \leq X \leq 50$
### Sample 1:
Input
Output

```
3
2 2 2
5 40 38
3 26 15

```

```
0
2
-1

```

### Explanation:

 **Test case $1$:**  Lifetime membership costs $2$ coins and Chef already has $2$ coins. Thus he does not need to attend any trial sessions.

 **Test case $2$:**  Lifetime membership costs $40$ coins and Chef has $38$ coins.

- If he takes $1$ trial session, he is left with $38-1=37$ coins, and gets a $5$ $\%$ discount on membership. The membership price would become $40\cdot \frac{95}{100} = 38$. Chef still does not has enough coins.
- If he takes $2$ trial sessions, he is left with $38-2=36$ coins, and gets a $10$ $\%$ discount on membership. The membership price would become $40\cdot \frac{90}{100} = 36$. Chef can now purchase the membership.

Thus, Chef needs to take a minimum of two trial sessions.

 **Test case $3$:**  It can be shown that Chef cannot purchase the membership, no matter how many trial sessions he takes.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T09:28:20.051Z  

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

void solve(){
    int d,x,y;
    cin >> d >> x >> y;

    int c=0;
    int a=x;
    
    while(x>y && y>0){
        c++;
        y--;

        int p=a*(100-c*d)/100;
        x=p;
    }

    if(x<=y){
        cout << c << endl;
    }else{
        cout << -1 << endl;
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

[View on CodeChef](https://www.codechef.com/problems/GYMDAY)