struct node{int l,r,size;} a[maxm];
int n,q,m,num,b[maxn],dc[maxn],root[maxn];
int rdc(int x){return lower_bound(dc+1,dc+num+1,x)-dc;}
void init()
{
    int i;
    n=read(); q=read();
    tr(i,1,n) b[i]=read();
    memcpy(dc,b,(n+1)*sizeof(int));
    sort(dc+1,dc+n+1);
    num=unique(dc+1,dc+n+1)-(dc+1);
}
int insert(int tx,int l,int r,int x)
{
    int t,mid=(l+r)>>1;
    a[t=++m]=a[tx]; a[t].size++;
    if (l==r) return t;
    if (x<=mid) a[t].l=insert(a[tx].l,l,mid,x);
    else a[t].r=insert(a[tx].r,mid+1,r,x);
    return t;
}
int kth(int tx,int ty,int l,int r,int k)
{
    int ds,mid=(l+r)>>1;
    if (l==r) return l;
    if (k<=(ds=a[a[ty].l].size-a[a[tx].l].size))
        return kth(a[tx].l,a[ty].l,l,mid,k);
    else return kth(a[tx].r,a[ty].r,mid+1,r,k-ds);
}
void work()
{
    int i,x,y,z;
    tr(i,1,n) root[i]=insert(root[i-1],1,num,rdc(b[i]));
    tr(i,1,q)
    {
        x=read(); y=read(); z=read();
        writeln(dc[kth(root[x-1],root[y],1,num,z)]);
    }
}
