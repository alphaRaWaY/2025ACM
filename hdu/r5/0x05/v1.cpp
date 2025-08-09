#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

// #define LOCAL
#ifdef LOCAL
#define debug0(x) cout<<"[DEBUG] "<<#x<<"="<<x<<endl
#define debug1(c,l,r) cout<<"[DEBUG] "<<#c<<" : ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl
#define debug2(c,l,r,ll,rr)cout<<"[DEBUG]"<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
ostream& operator<< (ostream& o,const pair<int,int>& a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#else
#define debug0(x)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif
// 总价值
int ans(0);
int a,b,c,d;
vector<int>v[5];
int cur[5];


int remainA(int a){return min(a,(int)v[1].size()-cur[1]);}
int remainB(int a){return min(a,(int)v[2].size()-cur[2]);}
int remainC(int a){return min(a,(int)v[3].size()-cur[3]);}
int remainD(int a){return min(a,(int)v[4].size()-cur[4]);}

// 1x1=>1x1
void op1()
{
    debug0("操作1");
    a--;
    int x(remainA(1));
    inc(i,1,x){ans+=v[1][cur[1]++];}
}

// 1x2=>1x2
int val2()
{
    int res(0);
    inc(i,1,remainB(1))res+=v[2][cur[2]+i-1];
    return res;
}
void op2()
{
    debug0("操作2");
    b--;
    int a=remainB(1);
    inc(i,1,a)ans+=v[2][cur[2]++];    
}

// 1x1+1x1=>1x2
int val3()
{
    int res(0);
    inc(i,1,remainA(2))res+=v[1][cur[1]+i-1];
    return res;
}
void op3()
{
    debug0("操作3");
    b--;
    int a=remainA(2);
    inc(i,1,a){
        ans+=v[1][cur[1]++];
    }
}

// 1x3=>1x3
int val4()
{
    int res(0);
    inc(i,1,remainC(1))res+=v[3][cur[3]+i-1];
    return res;
}
void op4()
{
    debug0("操作4");
    c--;
    int a=remainC(1);
    inc(i,1,a){
        ans+=v[3][cur[3]++];
    }
}

// 1x2+1x1=>1x3
int val5()
{
    int res(0);
    inc(i,1,remainA(1))res+=v[1][cur[1]+i-1];
    inc(i,1,remainB(1))res+=v[2][cur[2]+i-1];
    return res;
}
void op5()
{
    debug0("操作5");
    c--;
    int x=remainA(1);
    int y=remainB(1);
    inc(i,1,x){ans+=v[1][cur[1]++];}
    inc(i,1,y){ans+=v[2][cur[2]++];}
}


// 1x1+1x1+1x1=>1x3
int val6()
{
    debug0("操作6");
    int res(0);
    inc(i,1,remainA(3))res+=v[1][cur[1]+i-1];
    return res;
}
void op6()
{
    c--;
    int a=remainA(3);
    inc(i,1,a){ans+=v[1][cur[1]++];}
}

// 2x2=>2x2
int val7()
{
    int res(0);
    inc(i,1,remainD(1))res+=v[4][cur[4]+i-1];
    return res;
}
void op7()
{
    debug0("操作7");
    d--;
    int a=remainD(1);
    inc(i,1,a){ans+=v[4][cur[4]++];}
}

// 2x1+2x1=>2x2
int val8()
{
    int res(0);
    inc(i,1,remainB(2))res+=v[2][cur[2]+i-1];
    return res;
}
void op8()
{
    debug0("操作8");
    d--;
    int a=remainB(2);
    inc(i,1,a){ans+=v[2][cur[2]++];}
}

// 1x2+1x1+1x1=>2x2
int val9()
{
    int res(0);
    inc(i,1,remainB(1))res+=v[2][cur[2]+i-1];
    inc(i,1,remainA(2))res+=v[1][cur[1]+i-1];
    return res;
}
void op9()
{
    debug0("操作9");
    d--;
    int a=remainB(1),b=remainA(2);
    inc(i,1,a){ans+=v[2][cur[2]++];}
    inc(i,1,b){ans+=v[1][cur[1]++];}
}

// 1x1+1x1+1x1+1x1=>2x2
int val10()
{
    int res(0);
    inc(i,1,remainA(4))res+=v[1][cur[1]+i-1];
    return res;
}
void op10()
{
    debug0("操作10");
    d--;
    int a=remainA(4);
    inc(i,1,a){ans+=v[1][cur[1]++];}
}

void solve()
{
    ans=0;
    inc(i,0,4)cur[i]=0;
    // cin>>a>>b>>c>>d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    inc(i,1,4)
    {
        int n;
        // cin>>n;
        scanf("%d",&n);
        vector<int> nv(n);
        inc(j,0,n-1)scanf("%d",&nv[j]);
        // inc(j,0,n-1)cin>>nv[j];
        v[i]=nv;
        sort(v[i].begin(),v[i].end(),greater<>());
    }
    while(v[1].size()||v[2].size()||v[3].size()||v[4].size())
    {
        // cout<<"hello"<<endl;
        if(a){
            op1();
        }
        else if(b){
            debug0(val2());
            debug0(val3());
            if(val2()>val3())op2();
            else op3();
        }
        else if(c){
            if(val4()>val5()&&val4()>val6())op4();
            else if(val5()>val6()&&val5()>val4())op5();
            else op6();
        }
        else if(d){
            if(val7()>val8()&&val7()>val9()&&val7()>val10())op7();
            else if(val8()>val9()&&val8()>val10()&&val8()>val7())op8();
            else if(val9()>val10()&&val9()>val7()&&val9()>val8())op9();
            else op10();
        }
        else break;
    }
    // cout<<ans<<endl;
    printf("%d\n",ans);
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    _=1;
    scanf("%d",&_);
    // cin>>_;
    while(_--)solve();
}
/*
3
1 2 1 0
1 3
1 10
1 6
0
3 0 2 0
9 2 9 10 3 1 1 2 10 7
3 14 10 14
1 21
0
0 1 2 0
2 10 6
1 2
3 24 27 9
2 8 16
*/