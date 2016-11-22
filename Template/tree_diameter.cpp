struct edge{int x,y,d,pre;} a[2*maxn];
int n,m,ah[maxn],d0[maxn],d1[maxn],b[maxn];
bool p[maxn];
void bfs(int root,int *d)
{
	int h,t,e,y;
	memset(p,0,sizeof(p));
	h=0; t=1;
	b[1]=root;
	p[root]=1;
	while (h<t)
	{
		h++;
		for (e=ah[b[h]];e>-1;e=a[e].pre)
			if (!p[y=a[e].y])
			{
				b[++t]=y;
				p[y]=1;
				d[y]=d[a[e].x]+a[x].d;
			}
	}
}
void work()
{
	int i,s1,s2;
    memset(d0,0,sizeof(d0));
	memset(d1,0,sizeof(d1));
	bfs(1,d0); s1=1; tr(i,1,n) if (d0[i]>d0[s1]) s1=i;
	bfs(s1,d1); s2=1; tr(i,1,n) if (d1[i]>d1[s2]) s2=i;
    printf("%d %d %d\n",s1,s2,d1[s2]);
}
