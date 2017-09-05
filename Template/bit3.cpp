int n,m,i,b[maxn],x,y,z;
ll a[maxn],A[maxn];
char ch;

void add(ll *f,int x,ll y)
{
    while (x<=n) {f[x]+=y; x+=x&-x;}
}
ll sum(ll *f,int x)
{
    ll res=0;
    while (x) {res+=f[x]; x-=x&-x;}
    return res;
}
ll ask(int x)
{
	return 1LL*(x+1)*sum(a,x)-sum(A,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	tr(i,1,n) scanf("%d",&b[i]);
	rtr(i,n,1) b[i]=b[i]-b[i-1];
	tr(i,1,n)
	{
		add(a,i,b[i]); add(A,i,1LL*b[i]*i);
	}
	tr(i,1,m)
	{
		for(ch=getchar();ch!='C'&&ch!='Q';ch=getchar());
		if (ch=='Q') 
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",ask(y)-ask(x-1));
		} else
		{
			scanf("%d%d%d",&x,&y,&z);
			add(a,x,z); add(A,x,1LL*z*x);
			if (y<n)
			{
				add(a,y+1,-z); add(A,y+1,-1LL*z*(y+1));
			}
		}
	}
	return 0;
}
