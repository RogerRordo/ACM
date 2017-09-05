//C是初始数列根（数组），c是修改根（树状数组）
int n,m,q,num,b[maxn],c[maxn],dc[maxn+maxq],sx,sy,lx[maxn],ly[maxn];
int C[maxn];
struct node{int l,r,size;} a[maxm];
struct oper{int type,x,y,z;} op[maxq];

int lowbit(int x){return x&(-x);}
int rdc(int x){return lower_bound(dc+1,dc+num+1,x)-dc;}
int update(int t,int l,int r,int x,int y)
{
	int tt=t,mid=(l+r)>>1;
	a[tt=++m]=a[t];
	a[tt].size+=y;
	if (l==r) return tt;
	if (x<=mid) a[tt].l=update(a[t].l,l,mid,x,y);
	else a[tt].r=update(a[t].r,mid+1,r,x,y);
	return tt;
}
void init()
{
	int i,x,y,z;
	scanf("%d%d",&n,&q);
	tr(i,1,n) {scanf("%d",&b[i]); dc[i]=b[i];}
	tr(i,1,q)
	{
		char ch;
		for(ch=getchar();ch!='C'&&ch!='Q';ch=getchar());
		if (ch=='C')
		{
			scanf("%d%d",&x,&y);
			op[i].type=1;
			op[i].x=x; op[i].y=y;
			dc[n+i]=y;
		} else
		{
			scanf("%d%d%d",&x,&y,&z);
			op[i].type=2;
			op[i].x=x; op[i].y=y; op[i].z=z;
			dc[n+i]=0;
		}
	}
	sort(dc+1,dc+n+q+1);
    num=unique(dc+1,dc+n+q+1)-(dc+1);
    tr(i,1,q) if (op[i].type==1) op[i].y=rdc(op[i].y);
    tr(i,1,n) b[i]=rdc(b[i]);
    //
    m=1;
	C[0]=1;
    tr(i,1,n) C[i]=update(C[i-1],1,num,b[i],1);
    //
    tr(i,1,n) c[i]=1;
}
int kth(int l,int r,int k)
{
	if (l==r) return l;
	int i,sz=0,mid=(l+r)>>1;
	tr(i,1,sx) sz-=a[a[lx[i]].l].size;
	tr(i,1,sy) sz+=a[a[ly[i]].l].size;
	if (k<=sz)
	{
		tr(i,1,sx) lx[i]=a[lx[i]].l;
		tr(i,1,sy) ly[i]=a[ly[i]].l;
		return kth(l,mid,k);
	} else
	{
		tr(i,1,sx) lx[i]=a[lx[i]].r;
		tr(i,1,sy) ly[i]=a[ly[i]].r;
		return kth(mid+1,r,k-sz);
	}
}
void work()
{
	int i,x,y,z,t;
	tr(i,1,q)
		if (op[i].type==1)
		{
			x=op[i].x; y=op[i].y;
			for(t=x;t<=n;t+=lowbit(t))
				c[t]=update(c[t],1,num,b[x],-1);
			b[x]=y;
			for(t=x;t<=n;t+=lowbit(t))
				c[t]=update(c[t],1,num,b[x],1);
		} else
		{
			x=op[i].x-1; y=op[i].y; z=op[i].z;
			for(sx=0,t=x;t;t-=lowbit(t)) lx[++sx]=c[t];
			lx[++sx]=C[x];
			for(sy=0,t=y;t;t-=lowbit(t)) ly[++sy]=c[t];
			ly[++sy]=C[y];
			printf("%d\n",dc[kth(1,num,z)]);
		}
}
