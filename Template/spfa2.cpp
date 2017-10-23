//a从1开始！
struct edge{int pre,x,y,d;} a[maxm];
int n,m,ah[maxn],d[maxn],b[maxn];
bool p[maxn];
void spfa()
{
	int e,h,t,sum,num;
	memset(d,0x7F,sizeof(d));
    memset(p,0,sizeof(p));
	b[0]=1; p[1]=1; d[1]=0;
	sum=0; num=1;
	h=0; t=0;
	while (num)
	{
		while (d[h]*num>sum)    //?
		{
			t=(t+1)%n;
			b[t]=b[h];
			h=(h+1)%n;
		}
		e=ah[b[h]];
		p[b[h]]=0;
		num--;
		sum-=d[a[e].x];
		h=(h+1)%n;
		for (;a[e].x;e=a[e].pre)
			if (d[a[e].x]+a[e].d<d[a[e].y])
			{
				if (p[a[e].y]) sum-=d[a[e].y];
				d[a[e].y]=d[a[e].x]+a[e].d;
				sum+=d[a[e].y];
				if (!p[a[e].y])
				{
					if (num && d[a[e].y]<d[b[h]])
					{
						h=(h+n-1)%n;
						b[h]=a[e].y;
					} else
					{
						t=(t+1)%n;
						b[t]=a[e].y;
					}
					p[a[e].y]=1;
					num++;
				}
			}
	}
	printf("%d\n",d[n]);
}
