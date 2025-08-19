// 半平面交集
// 半平面：表示一条直线一侧的点集
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

const double eps = 1e-8, PI = acos(-1);
int n;

// 向量排序
/*
极角放前面，否则选择靠左的平面
*/

ostream& operator<< (ostream& o, const pair<int,int>& p)
{
    return o<<"{"<<p.first<<","<<p.second<<"}";
}


// 向量结构体
struct V{
    pair<double,double> begin,end;
    double angle;
    V(
        pair<double,double> a,
        pair<double,double> b
    ){
        begin=a;
        end=b;
        angle=PI/2-atan2(b.first-a.first,b.second-a.second);
        if(angle<0)angle+=2*PI;
    }
};
double cross(
    pair<double,double> a,
    pair<double,double> b,
    pair<double,double> c
){
    return (b.first-a.first)*(c.second-b.second)-(b.second-a.second)*(c.first-b.first);
}
pair<double,double> intersection(V a,V b)
{
    // 没有交点
    if(fabs(a.angle-b.angle)<=eps)return make_pair(NAN,NAN);
    double S1 = cross(b.end,a.end,a.begin);
    double S2 = cross(a.begin,a.end,b.begin);
    return make_pair(
        (S1*b.begin.first-S2*b.end.first)/(S1-S2),
        (S1*b.begin.second-S2*b.end.second)/(S1-S2)
    );
}

// 向量集合
vector<V> vectors;
// 点集合
vector<pair<double,double> >points[15];
void solve()
{
    cin>>n;

    vectors.clear();
    inc(i,1,n)points[i].clear();
    
    inc(i,1,n)
    {
        int m;
        cin >> m;
        auto nxt = [m](int a)->int{
            return (a + 1) % m;
        };
        inc(j, 1, m)
        {
            int a, b;
            cin >> a >> b;
            points[i].push_back(make_pair(a, b));   
        }
        inc(j,0,m-1)
        {
            V tmp(points[i][j],points[i][nxt(j)]);
            vectors.push_back(tmp);
        }
    }
    // 按极角和左右排序
    sort(vectors.begin(),vectors.end(),[](V a,V b)->bool{
        if(fabsl(a.angle-b.angle)<=eps)return cross(a.begin,a.end,b.begin)<0;
        else return a.angle<b.angle;
    });

    // 去重
    int sz(1);
    inc(i,1,vectors.size()-1)
    {
        if(fabsl(vectors[i].angle-vectors[i-1].angle)>eps)vectors[sz++]=vectors[i];
    }
    while(vectors.size()>sz)vectors.pop_back();


}
void test()
{
    cout<<intersection(
        V(
            make_pair(1,2),      
            make_pair(3,4)      
        ),
        V(
            make_pair(5,5),      
            make_pair(6,6)      
        )
    )<<endl;
}
signed main()
{
    test();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();
}