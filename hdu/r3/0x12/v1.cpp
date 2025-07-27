#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(2e5+5),INF(0x3f3f3f3f3f),MOD(1e9+7);
int n;
struct node
{
    int x,y,a,pos;
}p[MaxN];

int fast_pow(int a,int b)
{
    int base(a),res(1);
    while(b)
    {
        if(b&1)res=(base*res)%MOD;
        b>>=1;
        base=(base*base)%MOD;
    }
    return res;
}
int before[MaxN],after[MaxN],weight[MaxN];
void solve()
{
    cin>>n;
    inc(i,1,n)weight[i]=0;
    inc(i,1,n)p[i].pos=i;
    inc(i,1,n)cin>>p[i].x>>p[i].y>>p[i].a;
    sort(p+1,p+1+n,[](node a,node b)->bool{
        if(a.x+a.y==b.x+b.y)return a.x-a.y>b.x-b.y;
        return a.x+a.y<b.x+b.y;
    });
    inc(i,1,n)
    {
        before[i]=(before[i-1]+p[i].x+p[i].y)%MOD;
    }
    after[n+1]=0;
    dec(i,n,1)
    {
        after[i]=(after[i+1]+p[i].x+p[i].y)%MOD;
    }
    inc(i,1,n)
    {
        int pos = p[i].pos;
        weight[pos]=(weight[pos]+((i-1)*(p[i].x+p[i].y)%MOD-before[i-1]+MOD)%MOD*p[i].a%MOD)%MOD;
        weight[pos]=(weight[pos]+(after[i+1]-(n-i)*(p[i].x+p[i].y)%MOD+MOD)%MOD*p[i].a%MOD)%MOD;
    }


    // cout<<"==================="<<endl;
    // inc(i,1,n)cout<<p[i].x<<" "<<p[i].y<<endl;


    sort(p+1,p+1+n,[](node a,node b)->bool{
        if(a.x-a.y==b.x-b.y)return a.x+a.y>b.x+b.y;
        return a.x-a.y<b.x-b.y;
    });
    
    // cout<<"==================="<<endl;
    // inc(i,1,n)cout<<p[i].x<<" "<<p[i].y<<endl;

    
    inc(i,1,n)
    {
        before[i]=(before[i-1]+p[i].x-p[i].y+MOD)%MOD;
    }

    after[n+1]=0;
    dec(i,n,1)
    {
        after[i]=(after[i+1]+p[i].x-p[i].y+MOD)%MOD;
    }
    inc(i,1,n)
    {
        int pos = p[i].pos;
        weight[pos]=(weight[pos]+((i-1)*(p[i].x-p[i].y)%MOD-before[i-1]+MOD)%MOD*p[i].a%MOD)%MOD;
        weight[pos]=(weight[pos]+(after[i+1]-(n-i)*(p[i].x-p[i].y)%MOD+MOD)%MOD*p[i].a%MOD)%MOD;
    }

    int ans(0);
    inc(i,1,n)
    {
        // ans+=weight[i]*p[i].a;
        ans=(ans+weight[i])%MOD;
    }
    cout<<(ans*fast_pow(2,MOD-2))%MOD<<endl;
    // cout<<"#"<<(ans*fast_pow(2,MOD-2))%MOD<<endl;
}   
void test(){
    // cout<<998244853ll*14<<endl;
}
signed main()
{
    // test();
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
6
2 
1 1 500
1 2 2000
6
1 1 1
1 2 2
1 3 3
2 1 4
2 2 5
2 3 6
2 
-1 0 50
-1 0 60
4
0 0 49
1 3 1
3 1 946
4 4 1522
3
-998244353 -998244353 1
998244353 998244353 2
998244353 998244853 3
1
0 0 7355608


3
-998244353 -998244353 1
998244353 998244353 2
998244353 998244853 3
1
0 0 7355608
*/