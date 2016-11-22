struct query{int x,y,pre,lca;} b[2*maxq];
struct edge{int x,y,pre,d;} a[2*maxn];
int n,q,am,bm,ah[maxn],bh[maxn],fa[maxn],dep[maxn];
bool p[maxn];
int gfa(int x){return fa[x]==x?x:fa[x]=gfa(fa[x]);}
void tarjan(int x,int depth)
{
    int tmp,y;
    p[x]=1;
    dep[x]=depth;
    for(tmp=ah[x];tmp>-1;tmp=a[tmp].pre)
        if (!p[y=a[tmp].y])
        {
            tarjan(y,depth+a[tmp].d);
            fa[y]=x;
        }
    for(tmp=bh[x];tmp>-1;tmp=b[tmp].pre)
        if (p[y=b[tmp].y]) b[tmp].lca=b[tmp^1].lca=gfa(y);
}
void work()
{
    memset(dep,0,sizeof(dep));
    memset(p,0,sizeof(p));
    tarjan(1,0);
    int i; tr(i,0,q-1) writeln(dep[b[2*i].x]+dep[b[2*i].y]-2*dep[b[2*i].lca]);
}
