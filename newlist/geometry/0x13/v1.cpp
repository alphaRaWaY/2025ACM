#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)

// #define LOCAL
#ifdef LOCAL
ostream &operator<< (ostream & o,const pair<int,int> a)
{
    o<<"{"<<a.first<<","<<a.second<<"}";
    return o;
}
#define split cout<<"-------------------------------"<<endl
#define debug0(c) cout<<"[DEBUG] "<<#c<<"="<<c<<endl
#define debug1(c,l,r)\
cout<<"[DEBUG] "<<#c<<": ";\
inc(i,l,r)cout<<c[i]<<" ";cout<<endl 
#define debug2(c,l,r,ll,rr)\
cout<<"[DEBUG] "<<#c<<endl;\
inc(i,l,ll){inc(j,r,rr)cout<<c[i][j]<<" ";cout<<endl;}
#define T test()
#define case_ans cout<<"[ANSWER] "
#else
#define T
#define case_ans
#define split
#define debug0(c)
#define debug1(c,l,r)
#define debug2(c,l,r,ll,rr)
#endif

namespace HullUtil
{
    const double HULL_UTIL_EPS(1e-8);
    // 定义向量
    struct Vector{
        double x,y;
        // 向量内积
        double operator* (Vector v){
            return x*v.x+y*v.y;
        }
        Vector getVertical()
        {
            return {y,-x};
        }
    };
    // 定义点
    struct Point{
        double x,y;
        // 点获取向量
        Vector operator- (Point p2){
            Vector res;
            res.x=x-p2.x;
            res.y=y-p2.y;
            return res;
        }
    };
    // 定义点的输出流
    ostream &operator<<(ostream& o,const Point& p){
        o<<"["<<p.x<<","<<p.y<<"]";
        return o;
    }   

    // 向量外积
    double intersection(Vector v1,Vector v2){return v1.x*v2.y-v1.y*v2.x;}
    
    // 三点外积
    double cross(Point p1,Point p2,Point p3){return intersection(p2-p1,p3-p2);}
    // 向量的模
    double abs(Vector v){return sqrtl(v.x*v.x+v.y*v.y);}
    // 两点之间的距离
    double getDist(Point p1,Point p2){return abs(p2-p1);}
    
    // 定义线
    struct Line{
        Point p;
        Vector v;
        // 获取线和点之间的距离
        double getDist(Point a){return fabsl(intersection(p-a,v))/abs(v);}
    };
    
    Point getIntersection(Line line1,Line line2)
    {
        double cross_product = intersection(line1.v, line2.v);
        // 直线平行
        if (fabsl(cross_product) < HULL_UTIL_EPS) {
            return {NAN, NAN};
        }

        Vector v_diff = line2.p-line1.p;
        double t_numerator = intersection(v_diff, line2.v);
        double t = t_numerator / cross_product;
        Point intersection_point;
        intersection_point.x = line1.p.x + t * line1.v.x;
        intersection_point.y = line1.p.y + t * line1.v.y;
        return intersection_point;
    }
    // 两点之间求直线
    Line getLine(Point p1,Point p2){return {p1,p2-p1};}

    // 凸包结构体
    struct Hull{
        // 所有点
        vector<Point> p;
        // 凸包、上凸包、下凸包
        vector<Point> hull,upper,lower;
        double diameter;
        Hull(vector<pair<double,double>> in){
            diameter=0;
            if(in.empty())return;
            sort(in.begin(),in.end());
            for(auto[x,y]:in)p.push_back({x,y});
            // 求下凸包
            vector<Point> ss;
            ss.push_back(p[0]);
            inc(i,1,p.size()-1)
            {
                while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],p[i])<=0)ss.pop_back();
                ss.push_back(p[i]);
            }
            lower.swap(ss);
            // 求上凸包
            reverse(p.begin(),p.end());
            ss.push_back(p[0]);
            inc(i,1,p.size()-1)
            {
                while(ss.size()>1&&cross(ss[ss.size()-2],ss[ss.size()-1],p[i])<=0)ss.pop_back();
                ss.push_back(p[i]);
            }
            upper.swap(ss);
            // 求凸包
            inc(i,0,lower.size()-2)hull.push_back(lower[i]);
            inc(i,0,upper.size()-2)hull.push_back(upper[i]);
            reverse(p.begin(),p.end());
        }
        // 求凸包直径
        double getDiameter()
        {
            if(diameter>HULL_UTIL_EPS)return diameter;
            int sz=hull.size();
            auto nxt=[sz](int a)->int{return (a+1)%sz;};
            int cur(1);
            inc(i,0,hull.size()-1)
            {
                Line bottom(getLine(hull[i],hull[nxt(i)]));
                while(bottom.getDist(hull[cur])<bottom.getDist(hull[nxt(cur)])){cur=nxt(cur);}
                diameter=max({diameter,getDist(hull[cur],hull[i]),getDist(hull[nxt(cur)],hull[i])});                
            }
            return diameter;
        }
        // 判断点是否在凸包内
        bool contain(Point p){
            inc(i,0,hull.size()-1)
            {
                Point p1,p2;
                if(!i)p1=hull.back(),p2=hull.front();
                else p1=hull[i-1],p2=hull[i];
                if(cross(p,p1,p2)<0)return false;
            }
            return true;
        }
    };
}
const int MaxN(5e4+5);
int n;
vector<pair<double,double> >P;
void solve()
{
    cin>>n;
    inc(i,1,n)
    {
        double x,y;
        cin>>x>>y;
        P.push_back(make_pair(x,y));
    }
    array<HullUtil::Point,5> ans_p;
    double ans(0x3f3f3f3f3f3f3f3f);
    HullUtil::Hull hull(P);
    int sz=hull.hull.size();
    auto nxt=[sz](int a)->int{return (a+1)%sz;};
    int cur(1),lcur(0),rcur(1);
    inc(i,0,hull.hull.size()-1)
    {
        HullUtil::Line bottom(HullUtil::getLine(hull.hull[i],hull.hull[nxt(i)]));
        // 获取相对底边最远的点
        while(bottom.getDist(hull.hull[cur])<bottom.getDist(hull.hull[nxt(cur)])){cur=nxt(cur);}
        // 获取相对底边最靠右的点
        lcur=cur;
        while(
            (hull.hull[nxt(i)]-hull.hull[i])*(hull.hull[rcur]-hull.hull[i])<
            (hull.hull[nxt(i)]-hull.hull[i])*(hull.hull[nxt(rcur)]-hull.hull[i])
        ){
            rcur=nxt(rcur);
        }
        // 获取相对底边最靠左的点
        while(
            (hull.hull[i]-hull.hull[nxt(i)])*(hull.hull[lcur]-hull.hull[nxt(i)])<
            (hull.hull[i]-hull.hull[nxt(i)])*(hull.hull[nxt(lcur)]-hull.hull[nxt(i)])
        ){
            lcur=nxt(lcur);
        }
        // debug0(hull.hull[cur]);
        // debug0(hull.hull[lcur]);
        // debug0(hull.hull[rcur]);
        // debug0(hull.hull[i]);
        HullUtil::Line side,top,another_side;
        side.p=hull.hull[rcur];
        side.v=bottom.v.getVertical();
        top.p=hull.hull[cur];
        top.v=bottom.v;
        another_side.p=hull.hull[lcur];
        another_side.v=bottom.v.getVertical();
        double S(side.getDist(hull.hull[lcur])*bottom.getDist(hull.hull[cur]));
        // debug0(S);
        if(S<ans)
        {
            ans=min(S,ans);
            // ans_p={
            //     hull.hull[i],
            //     hull.hull[nxt(i)],
            //     hull.hull[rcur],
            //     hull.hull[cur],
            //     hull.hull[lcur]
            // };
            ans_p={
                HullUtil::getIntersection(bottom,side),
                HullUtil::getIntersection(side,top),
                HullUtil::getIntersection(top,another_side),
                HullUtil::getIntersection(another_side,bottom)
            };
        }
    }
    printf("%.5Lf\n",ans);
    // cout<<ans<<endl;
    inc(i,0,3)printf("%.5Lf %.5Lf\n",ans_p[i].x,ans_p[i].y);
    // inc(i,0,3)cout<<ans_p[i].x<<" "<<ans_p[i].y<<endl;
}
void test()
{
    HullUtil::Point p1({1,5});
    HullUtil::Point p2({3,6});
    HullUtil::Point p3({4,8});
    HullUtil::Vector v1=p2-p1,v2=p3-p1;
    HullUtil::Line l1({p1,v1}),l2({p2,v2});
    cout<<HullUtil::getIntersection(l1,l2)<<endl;
}
signed main()
{
    // T;
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)
    {
        split;
        solve();
    }
}

/*
6
1.0 3.00000
1 4.00000
2.0000 1
3 0.0000
3.00000 6
6.0 3.0
*/