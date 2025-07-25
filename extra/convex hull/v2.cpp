#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+6);
int n;
vector<pair<int,int> > ss,ans,point;
// 向量叉乘
int intersection(pair<int,int> a,pair<int,int> b)
{
    return a.first*b.second-a.second*b.first;
}
// 获取两点之间的向量
pair<int,int> getVector(pair<int,int> a,pair<int,int> b)
{
    return make_pair(b.first-a.first,b.second-a.second);
}
// 判断向量旋转方向
int cross(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    return intersection(
        getVector(a,b),
        getVector(b,c)
    );
}
// 获取凸包
void getHull(){
    ss.push_back(point.front());
    inc(i,1,point.size()-1)
    {
        while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],point[i])<0)ss.pop_back();
        ss.push_back(point[i]);
    }
}
void solve()
{
    ss.clear();
    ans.clear();
    point.clear();
    cin>>n;
    inc(i,1,n)
    {
        int x,y;
        char tmp;
        cin>>x>>y>>tmp;
        if(tmp!='Y')continue;
        point.push_back({x,y});
    }
    sort(point.begin(),point.end());
    getHull();
    inc(i,0,ss.size()-2)ans.push_back(ss[i]);
    // cout<<"=============="<<endl;
    // for(auto[x,y]:ss)cout<<x<<" "<<y<<endl;
    ss.clear();
    reverse(point.begin(),point.end());
    getHull();
    inc(i,0,ss.size()-2)ans.push_back(ss[i]);
    // cout<<"=============="<<endl;
    // for(auto[x,y]:ss)cout<<x<<" "<<y<<endl;
    ss.clear();
    cout<<ans.size()<<endl;
    for(auto[x,y]:ans)
    {
        cout<<x<<" "<<y<<endl;
    }
}   
signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    cin>>_;
    while(_--)solve();
}
/*
1
5
1 1 Y
1 -1 Y
0 0 N 
-1 -1 Y
-1 1 Y
*/

/*
1
8
2 1 Y
1 2 Y
-1 2 Y
-2 1 Y
-2 -1 Y
-1 -2 Y
1 -2 Y
2 -1 Y 
*/