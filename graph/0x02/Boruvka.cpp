//����һ��ͼG��û����ͬȨ�صı�
//�����С������ɭ��
//����
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

    //α��
    //��ɭ��F��ʼ��һ�����ɵ㹹�ɵļ��ϡ�
    //ѭ��
    //
        //��ɭ�ֵĸ��������ϸ��Եı�ǩ
        //�Ѹ��������̱�״̬����Ϊ��
        //����Gͼ��ÿ����(u,v)
        //
            //����ߵ������ǲ�ͬ�Ŀ�
            //
                //����ñ߱ȿ�u����С�߸�С���Ѹñ�����Ϊ��u����С��
                //����ñ߱ȿ�v����С�߸�С���Ѹñ�����Ϊ��v����С��
            //  
        //
        //������п鶼�Ҳ�����̱ߣ�����ɭ��F
        //����������̱߷��޵Ŀ飬��ɭ��F����Ӹ���̱�
    //
    while(true)
    {

    }
}