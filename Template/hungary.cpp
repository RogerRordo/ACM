struct edge{int x,y,pre;} a[maxm];
int nx,ny,m,last[maxn],my[maxn];
bool p[maxn];
int dfs(int x)
{
	for (int e=last[x];e>-1;e=a[e].pre)
		if (!p[a[e].y])
		{
			int y=a[e].y;
			p[y]=1;
			if (!my[y]||dfs(my[y])) return my[y]=x;
		}
	return 0;
}
void hungary()
{
	int i,ans=0;
	memset(my,0,sizeof(my));
	tr(i,1,nx)
	{
		memset(p,0,sizeof(p));
		if (dfs(i)) ans++;
	}
	printf("%d\n",ans);
}
