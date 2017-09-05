//a从1开始！
struct edge{int x,y,d;} a[maxm];
bool cmp(edge a,edge b){return a.d<b.d;}
int n,i,j,m,fa[maxn];
int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}
void kruskal()
{
	int ans,fx,fy;
	sort(a+1,a+m+1,cmp);
	tr(i,1,n) fa[i]=i;
	ans=0;
	tr(i,1,m)
		if ((fx=gfa(a[i].x))!=(fy=gfa(a[i].y)))
		{
			fa[fx]=fy;
			ans+=a[i].d;
		}
	printf("%d\n",ans);
}
