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
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxn 1005
using namespace std;
struct node{int y,pre;} a[maxn];
int n,m,ah[maxn],leaf[maxn];
void newedge(int x,int y){a[++m].y=y;a[m].pre=ah[x];ah[x]=m;}
void init()
{
    int x,y;
    char t[5];
    scanf("%d",&n);
    tr(y,2,n)
    {
        scanf("%s%d",&t,&x);
        newedge(x,y);
        if (t[0]=='L')
        {
            scanf("%d",&leaf[y]);
            leaf[y]+=2;
        }
    }
}
void print(int x)
{
    if (x==1) {printf("-1\n"); return;}
    if (x==2) {printf("0\n"); return;}
    printf("+1\n");
}
int dfs(int x,int sta)
{
    int e,best=4;
    if (leaf[x])
    {
        if (leaf[x]==1) if (sta) return 3; else return 1;
        if (leaf[x]==3) if (sta) return 1; else return 3;
        return 2;
    }
    for(e=ah[x];e;e=a[e].pre)
        best=min(best,dfs(a[e].y,sta^1));
    if (best==1) return 3;
    if (best==2) return 2;
    return 1;
}
int main()
{
    init();
    print(dfs(1,0));
    return 0;
}
