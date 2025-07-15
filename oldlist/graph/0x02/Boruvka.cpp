//输入一个图G，没有相同权重的边
//输出最小的生成森林
//方法
#include<bits/stdc++.h>
using namespace std;
using S = priority_queue<int>;
const int MaxN(5000+5);
const int MaxM(2e5+5);
int fa[MaxN];
struct Edge
{
    int endP1,endP2,weight;
    bool operator < (const Edge& e)const {return weight>e.weight;}
};
int fd(int a)
{
    return fa[a]==a?a:fa[a]=fd(fa[a]);
}
int main()
{   
    int m,n;
    cin>>m>>n;

    //伪码
    //把森林F初始成一个仅由点构成的集合。
    //循环
    //
        //把森林的各个块贴上各自的标签
        //把各个块的最短边状态设置为无
        //遍历G图的每条边(u,v)
        //
            //如果边的两端是不同的块
            //
                //如果该边比块u的最小边更小：把该边设置为块u的最小边
                //如果该边比块v的最小边更小：把该边设置为块v的最小边
            //  
        //
        //如果所有块都找不到最短边：返回森林F
        //遍历所有最短边非无的块，往森林F中添加该最短边
    //
    while(true)
    {

    }
}