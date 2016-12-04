//待测
int n,m;   
frac a[maxn][maxm],ans[maxn];
void gauss()
{
    int i=1,j,k,x,y,arb=m;
    frac t;
    tr(j,1,m)
    {
        tr(k,i,n) if (a[k][j]!=zerofrac) break;
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
        tr(j,1,m) if (a[i][j]!=zerofrac) break;
        if (j>m&&a[i][j]!=zerofrac) {printf("No Solution.\n"); return;}
    }
    if (arb) {printf("Arbitrary constants: %d\n",arb); return;}
    //------------
    rtr(i,m,1)
    {
        ans[i]=a[i][m+1];
        rtr(j,m,i+1) ans[i]=ans[i]-ans[j]*a[i][j];
        ans[i]=ans[i]/a[i][i];
    }
    tr(i,1,m) printf("x[%d] = %s\n",i,ans[i].c_str());
}
