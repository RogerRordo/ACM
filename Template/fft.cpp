#define pi acos(-1.0)
#define L 19
const int N=1<<L;
typedef complex<double> C;
int n,m,i;
int R[N],c[N];
C a[N],b[N];
void fft(C *a,int n,int f)
{
	int i,j,k;
	tr(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for(i=1;i<n;i<<=1)
	{
		C wn(cos(pi/i),f*sin(pi/i));
		for(j=0;j<n;j+=(i<<1))
		{
			C w(1,0);
			tr(k,0,i-1)
			{
				C x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y; a[j+k+i]=x-y;
				w*=wn;
			}
		}
	}
	if(f==-1) tr(i,0,n-1) a[i]/=n;
}
void mul(int na,C *a,int nb,C *b,int &nc,int *c)	//c=a=a*b
{
	int len=0,n;
	nc=na+nb;
	for(n=1;n<=nc+2;n<<=1) len++;
	tr(i,na+1,n-1) a[i]=0;
	tr(i,nb+1,n-1) b[i]=0;
	tr(i,0,n-1) R[i]=(R[i>>1]>>1)|((i&1)<<(len-1));
	fft(a,n,1); fft(b,n,1);
	tr(i,0,n) a[i]*=b[i];
	fft(a,n,-1);
	tr(i,0,nc) c[i]=int(a[i].real()+0.1);
}
void init1()	//大数乘法
{
	static char sa[N],sb[N];
	while (~scanf("%s%s",sa,sb))
	{
		memset(c,0,sizeof(c));
		n=strlen(sa)-1; m=strlen(sb)-1;
		tr(i,0,n) a[i]=sa[n-i]-'0';
		tr(i,0,m) b[i]=sb[m-i]-'0';
		mul(n,a,m,b,m,c);
		tr(i,0,m) if (c[i]>=10)
		{
			c[i+1]+=c[i]/10; c[i]%=10;
			if (i==m) m++;
		}
		while (!c[m]&&m) m--;
		rtr(i,m,0) printf("%d",c[i]); puts("");
	}
}
void init2()	//多项式乘法
{
	int x;
	while (~scanf("%d%d",&n,&m))
	{	
		tr(i,0,n) scanf("%d",&x),a[i]=x;
		tr(i,0,m) scanf("%d",&x),b[i]=x;
		mul(n,a,m,b,m,c);
		tr(i,0,m) printf("%d ",c[i]);
		puts("");
	}
}
