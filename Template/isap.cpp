struct edge{int x,y,c,f,pre;} a[2*maxm];
int n,mm,m,last[maxn],d[maxn],gap[maxn],cur[maxn],ans;
void newedge(int x,int y,int c,int f)
{
	m++;
	a[m].x=x; a[m].y=y; a[m].c=c; a[m].f=f;
	a[m].pre=last[x]; last[x]=m;
}
void init()
{
	int i,x,y,c;
	m=-1;
	memset(last,-1,sizeof(last));
	tr(i,1,mm)
	{
		x=read(); y=read(); c=read();
		newedge(x,y,c,0);
		newedge(y,x,c,c);
	}
	tr(i,1,n) cur[i]=last[i];
    memset(d,0,sizeof(d));
	memset(gap,0,sizeof(gap));
	gap[0]=n;
	ans=0;
}
int sap(int x,int flow)
{
	int e,t;
	if (x==n) return flow;
	for (e=cur[x];e!=-1;e=a[e].pre)
		if (a[e].f<a[e].c && d[a[e].y]+1==d[x])
		{
			cur[x]=e;
			if (t=sap(a[e].y,min(flow,a[e].c-a[e].f)))
			{
				a[e].f+=t; a[e^1].f-=t; return t;
			}
		}
	if (--gap[d[x]]==0) d[n]=n;
	d[x]=n;
	for (e=last[x];e!=-1;e=a[e].pre)
		if (a[e].f<a[e].c) d[x]=min(d[x],d[a[e].y]+1);
	cur[x]=last[x];	
	++gap[d[x]];
	return 0;
}
int work()
{
    while (d[n]<n) ans+=sap(1,oo);
}
