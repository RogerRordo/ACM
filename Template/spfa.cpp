struct edge{int pre,x,y,d;} a[maxm];
int n,m,last[maxn],d[maxn],b[maxn];
bool p[maxn];
void spfa()
{
	int h,t,e;
	memset(d,0x7F,sizeof(d));
    memset(p,0,sizeof(p));
	b[0]=1; p[1]=1; d[1]=0;
	h=n-1; t=0;
	while (h!=t)
	{
		h=(h+1)%n;
		for (e=last[b[h]];e>-1;e=a[e].pre)
			if (d[a[e].x]+a[e].d<d[a[e].y])
			{
				d[a[e].y]=d[a[e].x]+a[e].d;
				if (!p[a[e].y])
				{
					t=(t+1)%n;
					b[t]=a[e].y;
					p[a[e].y]=1;
				}
			}
		p[b[h]]=0;
	}
	printf("%d\n",d[n]);
}
