struct edge{int pre,x,y,d;} a[maxm];
int n,m,ah[maxn],d[maxn];
bool p[maxn];
void update(int x)
{
	int e;
	p[x]=true;
	for(e=ah[x];e>-1;e=a[e].pre)
		if (!p[a[e].y]&&(!d[a[e].y]||a[e].d+d[x]<d[a[e].y]))
			d[a[e].y]=a[e].d+d[x];
}
void dijkstra()
{
	int i,j,t;
    memset(p,0,sizeof(p));
	update(1);
	d[0]=oo;
	tr(i,2,n)
	{
		t=0;
		tr(j,1,n) if (!p[j]&&d[j]&&d[j]<d[t]) t=j;
		update(t);
	}
	printf("%d\n",d[n]);
}
