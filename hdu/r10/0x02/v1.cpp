#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN = 3 * 1e6 + 10, P = 998244353, G = 3, Gi = 332748118; 
int n, m, limit = 1, L, r[MAXN];
int a[MAXN], b[MAXN];

inline int fastpow(int a, int k) {
    int base = 1;
    while(k) {
        if(k & 1) base = (base * a ) % P;
        a = (a * a) % P;
        k >>= 1;
    }
    return base % P;
}

inline void NTT(int *A, int type) {
    for(int i = 0; i < limit; i++) 
        if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < limit; mid <<= 1) {    
        int Wn = fastpow( type == 1 ? G : Gi , (P - 1) / (mid << 1));
        for(int j = 0; j < limit; j += (mid << 1)) {
            int w = 1;
            for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                 int x = A[j + k], y = w * A[j + k + mid] % P;
                 A[j + k] = (x + y) % P,
                 A[j + k + mid] = (x - y + P) % P;
            }
        }
    }
}

void mul(int N,int M)
{
    inc(i,N+1,MAXN-5)a[i]=0;
    inc(i,M+1,MAXN-5)b[i]=0;

    limit = 1;
    L = 0;
    memset(r,0,sizeof(r));

    while(limit <= N + M) limit <<= 1, L++;
    
    for(int i = 0; i < limit; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));    
    NTT(a, 1);NTT(b, 1);  
    for(int i = 0; i < limit; i++) a[i] = (a[i] * b[i]) % P;
    NTT(a, -1);    
    int inv = fastpow(limit, P - 2);
    // cout<<"ciallo~"<<endl;
    for(int i = 0; i <= N + M; i++)
    // printf("%d ", (a[i] * inv) % P);
    a[i] = (a[i] * inv) % P;
}

void solve()
{
    cin>>n>>m;
    inc(i,0,m*2)cin>>a[i];
    int ans(0);
    inc(i,m,2*m)ans=(ans+a[i])%P;
    cout<<ans<<" ";
    inc(i,1,n-1)
    {
        int len(i*m+1);
        inc(j,0,len-1)a[j]=a[j+m];

        inc(j,0,2*m)cin>>b[j];
        mul(len-1,2*m);
        
        ans = 0;
        inc(j,m,len+2*m-1)ans=(ans+a[j])%P;
        cout<<ans<<" ";
    }
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int _;
    cin>>_;
    while(_--)solve();
    return 0;
}