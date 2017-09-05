#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxn 20005
using namespace std;
struct node
{
    int x,y,pre,suc;
    friend bool operator<(node a,node b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
} a[maxn];
int dats,dat,n,ans,i,t,root,l,r;
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
int del(int x)
{
    int res=a[x].pre;
    if (a[x].pre) a[a[x].pre].suc=a[x].suc;
    if (a[x].suc) a[a[x].suc].pre=a[x].pre;
    if (x==root) root=a[x].suc;
    return res;
}
int main()
{
    dats=read();
    tr(dat,1,dats)
    {
        n=read();
        tr(i,1,n) {a[i].x=read(); a[i].y=read();}
        sort(a+1,a+n+1); ans=0; root=1;
        tr(i,1,n) {a[i].pre=i-1;a[i].suc=i+1;} a[n].suc=0;
        while(root)
        {
            l=0; r=oo;
            for(t=root;t;t=(t?a[t].suc:root))
            {
                if (a[t].x>=r) break;
                if (a[t].x>l&&a[t].y<r)
                {
                    l=a[t].x; r=a[t].y;
                    t=del(t);
                }
            }
            ans++;
        }
        printf("Case %d: %d\n",dat,ans);
    }
    return 0;
}