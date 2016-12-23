#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 20010
#define maxm 10005
using namespace std;
priority_queue<int> a,d;
int dats,n,m,q[maxm][2],dcs,dc[maxn];
vector<int> b[maxn];
bool p[maxm],vis[maxm];
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
int rdc(int x){return lower_bound(dc+1,dc+n+1,x)-dc;}
void init()
{
    int i,x,y;
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    while (!a.empty()) a.pop();
    while (!d.empty()) d.pop();
    m=read(); dcs=0;
    tr(i,1,m)
    {
        dc[++dcs]=q[i][0]=read();
        dc[++dcs]=q[i][1]=read();
    }
    sort(dc+1,dc+dcs+1);
    n=unique(dc+1,dc+dcs+1)-(dc+1);
    tr(i,1,n+1) b[i].clear();
    tr(i,1,m)
    {
        x=rdc(q[i][0]); y=rdc(q[i][1]);
        b[x].push_back(i);
        b[y+1].push_back(i);
    }
}
void work()
{
    int i,ans=0;
    tr(i,1,n)
    {
        for(vector<int>::iterator it=b[i].begin();it!=b[i].end();it++)
            if (!p[*it])
            {
                p[*it]=1; a.push(*it);
            } else d.push(*it);
        while (!a.empty()&&!d.empty()&&a.top()==d.top()) {a.pop(); d.pop();}
        if (a.empty()) continue;
        if (!vis[a.top()])
        {
            vis[a.top()]=1;
            ans++;
        }
    }
    writeln(ans);
}
int main()
{
    dats=read();
    while (dats--)
    {
        init();
        work();
    }
    return 0;
}
