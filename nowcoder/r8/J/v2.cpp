#include<bits/stdc++.h>
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)
#define swap(x,y) x ^= y, y ^= x, x ^= y
#define LL long long 
#define inc(i,a,b)for(int i(a);i<=b;i++)
using namespace std;
const int MAXN = 3 * 1e6 + 10, P = 998244353, G = 3, Gi = 332748118; 
char buf[1<<21], *p1 = buf, *p2 = buf;
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, M, limit = 1, L, r[MAXN];
LL a[MAXN*3], b[MAXN];
inline LL fastpow(LL a, LL k) {
    LL base = 1;
    while(k) {
        if(k & 1) base = (base * a ) % P;
        a = (a * a) % P;
        k >>= 1;
    }
    return base % P;
}
inline void NTT(LL *A, int type) {
    for(int i = 0; i < limit; i++) 
        if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < limit; mid <<= 1) {    
        LL Wn = fastpow( type == 1 ? G : Gi , (P - 1) / (mid << 1));
        for(int j = 0; j < limit; j += (mid << 1)) {
            LL w = 1;
            for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                 int x = A[j + k], y = w * A[j + k + mid] % P;
                 A[j + k] = (x + y) % P,
                 A[j + k + mid] = (x - y + P) % P;
            }
        }
    }
}
int main() {
    int _;
    cin>>_;
    while(_--){
        limit = 1, L=0;
        string aa,bb;
        cin>>aa>>bb;
        N=aa.size()-1;
        M=bb.size()-1;
        // N = read(); M = read();
        for(int i = 0; i <= 2 *(N + M); i++) r[i] = a[i] = b[i] = 0;
        inc(i,0,N)a[i]=aa[aa.size()-i-1]-'0';
        inc(i,0,M)b[i]=bb[bb.size()-i-1]-'0';
        while(limit <= N + M) limit <<= 1, L++;
        for(int i = 0; i < limit; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));    
        NTT(a, 1);NTT(b, 1);    
        for(int i = 0; i < limit; i++) a[i] = (a[i] * b[i]) % P;
        NTT(a, -1);    
        LL inv = fastpow(limit, P - 2);
        for(int i = 0; i <= N + M; i++) a[i] = a[i] * inv % P;
        int High(N+M);
        
        int index(0);
        while(index<=High)
        {
            if(a[index]<0)
            {
                int tmp(-a[index]/2+1);
                a[index]+=2*tmp;
                a[index+2]+=tmp;
                High=(High>index+2)?High:(index+2);
            }
            if(a[index]>=2)
            {
                int tmp(a[index]/2);
                a[index]-=2*tmp;
                a[index+2]-=tmp;
                High=(High>index+2)?High:(index+2);
            }
            index++;
        }
        bool flag(false),jud(false);
        
        for(int i(High);i>=0;i--)jud|=a[i];
        if(!jud)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i(High);i>=0;i--)
        {
            if(a[i]==0&&!flag)continue;
            flag=true;
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}