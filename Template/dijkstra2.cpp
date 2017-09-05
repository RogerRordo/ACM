typedef pair<int,int> pa;
struct edge{int pre,x,y,d;} a[maxm];
int n,m,ah[maxn],ans[maxn];
priority_queue<pa,vector<pa>,greater<pa> >d;
bool p[maxn];
void dijkstra()
{
	int v,s,e;
    memset(p,0,sizeof(p));
	d.push(make_pair(0,1));
	while(!d.empty())
	{
		v=d.top().second;
		s=d.top().first;
		d.pop();
		if (p[v]) continue;
		p[v]=1;
		ans[v]=s;
		for(e=ah[v];e>-1;e=a[e].pre)
			if (!p[a[e].y]) d.push(make_pair(s+a[e].d,a[e].y));
	}
	printf("%d\n",ans[n]);
}
