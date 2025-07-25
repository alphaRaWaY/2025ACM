#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MaxN(1e5+6);
int n;
vector<pair<int,int> > bot,top,point;
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
void getBot()
{
    bot.push_back(point.front());
    inc(i,1,point.size()-1)
    {
        while(bot.size()>1)
        {
            int res = intersection(
                getVector(
                    bot[bot.size()-2],
                    bot[bot.size()-1]
                ),
                getVector(
                    bot[bot.size()-1],
                    point[i]
                )
            );
            if(res<0)bot.pop_back();
            else{
                bot.push_back(point[i]);
                break;
            }            
        }
        if(bot.size()==1)
            bot.push_back(point[i]);
    }
}
void getTop()
{
    top.push_back(point.front());
    inc(i,1,point.size()-1)
    {
        while(top.size()>1)
        {
            int res = intersection(
                getVector(
                    top[top.size()-2],
                    top[top.size()-1]
                ),
                getVector(
                    top[top.size()-1],
                    point[i]
                )
            );
            if(res<0)top.pop_back();
            else{
                top.push_back(point[i]);
                break;
            }            
        }
        if(top.size()==1)
            top.push_back(point[i]);
    }
}
void solve()
{
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
    getBot();
    reverse(point.begin(),point.end());
    getTop();
    cout<<bot.size()-2+top.size()<<endl;
    // cout<<"==========="<<endl;
    // for(auto[x,y]:bot)cout<<x<<" "<<y<<endl;
    // cout<<"==========="<<endl;
    // for(auto[x,y]:top)cout<<x<<" "<<y<<endl;
    inc(i,0,bot.size()-2)
    {
        cout<<bot[i].first<<" "<<bot[i].second<<endl;
    }
    inc(i,0,top.size()-2)
    {
        cout<<top[i].first<<" "<<top[i].second<<endl;
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