//ds，ss，gs分别是dfn，sta，group计数器；group记所属分量号码，size记分量大小；insta记是否在栈中
struct edge{int x,y,pre;} a[maxm];
int n,m,ah[maxn],ds,dfn[maxn],low[maxn],ss,sta[maxn],gs,group[maxn],size[maxn];
bool insta[maxn];
void tarjan(int x)
{
    int e,y,t;
    dfn[x]=low[x]=++ds;
    sta[++ss]=x; insta[x]=1;
    for(e=ah[x];e>-1;e=a[e].pre)
    {
        if (!dfn[y=a[e].y]) tarjan(y);
        if (insta[y]) low[x]=min(low[x],low[y]);
    }
    if (low[x]==dfn[x])
        for(gs++,t=0;t!=x;t=sta[ss--]) {group[sta[ss]]=gs; size[gs]++;}
}
void work()
{
    ds=ss=gs=0;
    int i; tr(i,1,n) if (!dfn[i]) tarjan(i);
}
