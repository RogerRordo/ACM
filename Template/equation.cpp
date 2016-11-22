//求导至最高次为t时，a[t][i]表x^i的系数，ans[t]记录根；oo依题而定
double a[maxn][maxn],ans[maxn][maxn];
int n,anss[maxn];
double get(int x,double y)
{
    int i; double res=0;
    rtr(i,x,0) res=res*y+a[x][i];
    return res;
}
void dich(int x,double ll,double rr)
{
    if (cmp(get(x,ll))==0){ans[x][++anss[x]]=ll;return;}
    if (cmp(get(x,rr))==0){ans[x][++anss[x]]=rr;return;}
    if (cmp(get(x,ll)*get(x,rr))>0) return;
    double l=ll,r=rr,mid;
    while (l+eps<r) //亦可改为循环一定次数
    {
        int tl=cmp(get(x,l)),tm=cmp(get(x,mid=(l+r)/2));
        if (tl==0) break;
        if (tl*tm>=0) l=mid; else r=mid;
    }
    ans[x][++anss[x]]=l;
}
void work()
{
    int i,j; double l,r;
    rtr(i,n-1,1) tr(j,0,i) a[i][j]=a[i+1][j+1]*(j+1);
    tr(i,0,n-1)
    {
        l=-oo;
        tr(j,1,anss[i]){dich(i+1,l,r=ans[i][j]); l=r;}
        dich(i+1,l,oo);
    }
    tr(i,1,anss[n]) printf("%.10lf\n",ans[n][i]);
}
