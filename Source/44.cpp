//正常拓扑用queue，这里题目特殊要求下用堆
/*
	Time: 161012
	Prob: HDU1285
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#include<queue>
#define tr(i,l,r) for((i)=(l);(i)<=(r);i++)
#define maxn 505
using namespace std;
struct edge{int x,y,pre;} a[maxn*maxn];
int n,m,last[maxn],d[maxn];
priority_queue<int,vector<int>,greater<int> > b;
void init()
{
    int i;
    memset(last,0,sizeof(last));
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
    tr(i,1,m)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        d[a[i].y]++;
        a[i].pre=last[a[i].x];
        last[a[i].x]=i;
    }
}
void top()
{
    int i,x,y;
    tr(i,1,n) if (!d[i]) b.push(i);
    while (b.size())
    {
        x=b.top(); b.pop();
        d[x]=-1;
        for(;last[x];last[x]=a[last[x]].pre)
            if (!--d[y=a[last[x]].y]) b.push(y);
        printf("%d",x);
        if (b.size()) printf(" ");
    }
    printf("\n");
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        top();
    }
    return 0;
}
