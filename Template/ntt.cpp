const int P=998244353;
const int N=1<<19;
const int G=3;	//原根
int R[N],w[2][N];
void ntt(int *a,int n,int f)
{
	int i,j,k,t,l,x,y;
	tr(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for(i=1;i<n;i<<=1)
		for(j=0,t=n/(i<<1);j<n;j+=(i<<1))
			for(k=0,l=0;k<i;k++,l+=t)
			{
				x=1LL*a[i+j+k]*w[f][l]%P;
				y=a[j+k];
				a[j+k]=(x+y)%P;
				a[i+j+k]=(y+P-x)%P;
			}
	if(f)
	{
		t=pow(n,P-2);
		tr(i,0,n-1) a[i]=1LL*a[i]*t%P;
	}
}
void mul(int na,int *a,int nb,int *b,int &nc)	//a=a*b
{
	int len=0,i,n;
	nc=na+nb;
	for(n=1;n<=nc+2;n<<=1) len++;
	tr(i,na+1,n-1) a[i]=0;
	tr(i,nb+1,n-1) b[i]=0;
	tr(i,0,n-1) R[i]=(R[i>>1]>>1)|((i&1)<<(len-1));
	int v=pow(G,(P-1)/n);
	int dv=pow(v,P-2);
	w[0][0]=w[1][0]=1;
	tr(i,1,n-1)
	{
		w[0][i]=1LL*w[0][i-1]*v%P;
		w[1][i]=1LL*w[1][i-1]*dv%P;
	}
	ntt(a,n,0); ntt(b,n,0);
	tr(i,0,n) a[i]=(1LL*a[i]*b[i])%P;
	ntt(a,n,1);
}
