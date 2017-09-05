struct edge{int x,y,d,pre;} a[maxm];
typedef pair<int,int> pa;
priority_queue<pa,vector<pa>,greater<pa> >d;
int n,m,ah[maxn];
bool p[maxn];
void prim()
{
	int i,x,y,e,ans=0;
	pa t;
	while (!d.empty()) d.pop();
	d.push(make_pair(0,1));
	memset(p,0,sizeof(p));
	tr(i,1,n)
	{
        while (!d.empty()&&p[d.top().second]) d.pop();
		t=d.top();
		ans+=t.first;
		p[x=t.second]=1;
		for(e=ah[x];e>-1;e=a[e].pre)
			if (!p[y=a[e].y]) d.push(make_pair(a[e].d,y));
	}
	printf("%d\n",ans);
}
