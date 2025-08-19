// 半平面交集
// 半平面：表示一条直线一侧的点集

/*
首先对所有向量按照极角排序
因为向量是逆时针旋转
所以求的半平面一定在所有向量的左侧
排序的时候有限找最靠左极角最小的向量

之后维护一个向量的双端队列
保证队列的第一个交点和最后一个交点不能在新来的向量的右侧
因为需要求的向量的所有交点一定在所有向量的左侧
因此每次尝试添加新的向量时
都把双端队列的队首和队尾不满足的向量弹出
*/


#include<bits./stdc++.h>
using namespace std;
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define endl '\n'


// 极小值
const double eps = 1e-6;
// 反三角求圆周率
const double PI = acos(-1);

// 定义点结构体
struct Point{
    double x,y;
    bool operator < (const Point & p)const{
        if(x==p.x)return y<p.y;
        return x<p.x;
    }
    Point(){}
    Point(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
};

// 定义点的输出流
ostream& operator<< (ostream& o, const Point & p)
{
    return o<<"{"<<p.x<<","<<p.y<<"}";
}

// 定义向量结构体
struct V{
    double x,y;
    
    V(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    V(){}
};

// 定义向量的输出流
ostream& operator<< (ostream& o, const V & p)
{
    return o<<"{"<<p.x<<","<<p.y<<"}";
}

// 定义两点相减得到向量
V operator- (const Point& p1,const Point& p2)
{
    return V(p1.x-p2.x,p1.y-p2.y);
}

// 定义向量外积
double intersection(V a,V b)
{
    return a.x*b.y-a.y*b.x;
}

// 三点的外积
double intersection(
    Point a,
    Point b,
    Point c
){
    return intersection(b-a,c-a);
}

// 定义线结构体
struct Line{
    Point begin;
    V dir;   
    double angle;
    Line(){}
    Line(Point a,Point b)
    {
        this->begin.x=a.x;
        this->begin.y=a.y;
        this->dir.x=(b-a).x;
        this->dir.y=(b-a).y;
        angle=atan2(dir.y,dir.x);
        if(angle<0)angle+=PI*2;
    }    
    // 寻找极角最小并且最靠左的直线
    bool operator< (const Line& l)const{
        if(fabsl(angle-l.angle)<=eps)
        {
            Point target(begin.x+dir.x,begin.y+dir.y);
            return intersection(begin,l.begin,target)>0;
        }
        return angle<l.angle;
    }
};

// 定义线的输出流
ostream& operator<< (ostream& o, const Line & p)
{
    return o<<"["<<p.begin<<","<<p.dir<<":"<<p.angle<<"]";
}

// 获取两条直线之间的交点
Point getPoint(Line l1,Line l2)
{
    Point s1=l1.begin,
    s2=l2.begin,
    t1(s1.x+l1.dir.x,s1.y+l1.dir.y),
    t2(s2.x+l2.dir.x,s2.y+l2.dir.y);

    double S1 = fabsl(intersection(s1,t1,t2));
    double S2 = fabsl(intersection(s1,s2,t1));


    return Point(
        (S2*t2.x-S1*s2.x)/(S2-S1),
        (S2*t2.y-S1*s2.y)/(S2-S1)
    );
}

vector<Line> lines;

// 用于判断队列是否需要弹出
bool check(
    Line a,
    Line b,
    Line n
){
    Point p = getPoint(a,b);
    // 如果队列顶端的交点在新来的直线的右端,则队列需要弹出
    return intersection(n.dir,p-n.begin)>0;
}
void solve()
{
    int n;
    cin>>n;

    // 建立线的集合
    inc(i,1,n)
    {
        int m;
        cin>>m;
        vector<Point> ps(m+1);
        inc(i,1,m){int a,b;cin>>a>>b;ps[i]=Point(a,b);}
        inc(i,1,m)lines.push_back(Line(ps[i],ps[i%m+1]));
    }

    // 排序
    sort(lines.begin(),lines.end());

    // 去重
    int sz(1);
    inc(i,1,lines.size()-1)
    {
        if(fabsl(lines[i].angle-lines[i-1].angle)>eps)lines[sz++]=lines[i];        
    }
    while(lines.size()>sz)lines.pop_back();

    // 初始化队列
    int front(1),back(0);
    vector<Line> dq(sz);
    dq[front]=lines[1];
    dq[back]=lines[0];

    // 遍历边集
    inc(i,2,sz-1)
    {
        while(front>back&&check(dq[front],dq[front-1],lines[i]))front--;
        while(front>back&&check(dq[back],dq[back+1],lines[i]))back++;
        dq[++front]=lines[i];
    }

    // 插入完之后处理仍然不合理的边
    while(front>back&&check(dq[front],dq[front-1],dq[back]))front--;
    while(front>back&&check(dq[back],dq[back+1],dq[front]))back++;
    
    // 求面积
    
    // double ans(0);
    // inc(i,back,front)
    // {
    //     double S = fabsl(intersection(dq[i].begin-dq[back].begin,dq[i].dir)/2);
    //     ans+=S;
    // }
    // cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    int _;
    _=1;
    // cin>>_;
    while(_--)solve();  
}