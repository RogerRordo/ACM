int nn,n,m,i,j,b[maxn];
double a[maxn][maxn],ans[maxn];
bool gauss()
{
    int i=1,j,k,x,y,arb=m;
    double t;
    tr(j,1,m)
    {
        tr(k,i,n) if (cmp(a[k][j])!=0) break;
        if (k>n) continue;
        arb--;
        if (k!=i) tr(y,j,m+1) swap(a[i][y],a[k][y]);
        tr(x,1,n) if(x!=i)
        {
            t=a[x][j]/a[i][j];
            tr(y,j,m+1) a[x][y]=a[x][y]-a[i][y]*t;
        }
        if (++i>n) break;
    }
    //------------
    tr(i,1,n)
    {
        tr(j,1,m) if (cmp(a[i][j])!=0) break;
        if (j>m&&cmp(a[i][j])!=0) return 0;
    }
    if (arb) return 0;
    //------------
    rtr(i,m,1)
    {
        ans[i]=a[i][m+1];
        rtr(j,m,i+1) ans[i]=ans[i]-ans[j]*a[i][j];
        ans[i]=ans[i]/a[i][i];
    }
    return 1;
}
int main()
{
	scanf("%d",&nn);
	tr(i,1,nn) scanf("%d",&b[i]);
	tr(m,1,(nn+1)/2)
	{
		n=0;
		tr(i,m,nn)
		{
			n++;
			tr(j,1,m-1) a[n][j]=b[i-j];
			a[n][m]=1; a[n][m+1]=b[i];
		}
		if (gauss()) break;
	}
	printf("a[n] = ");
	tr(i,1,m-1) printf("%+lf a[n-%d] ",ans[i],i);
	printf("%+lf\n",ans[m]);
	return 0;
}
