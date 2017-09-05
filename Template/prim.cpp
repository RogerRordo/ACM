struct edge{int x,y,d,pre;} a[maxm];
int n,m,ah[maxn],d[maxn];
bool p[maxn];
void prim()
{
	int i,j,x,y,e,ans=0;
	memset(d,0x7f,sizeof(d)); d[1]=0;
	memset(p,0,sizeof(p));
	tr(i,1,n)
	{
		x=0;
		tr(j,1,n) if (!p[j]&&d[j]<d[x]) x=j;
		ans+=d[x];
		p[x]=1;
		for(e=ah[x];e>-1;e=a[e].pre)
			if (!p[y=a[e].y]) d[y]=min(d[y],a[e].d);
	}
	printf("%d\n",ans);
}
