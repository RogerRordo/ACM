struct node{int s,tag;} a[4*maxn];
int n;
void update(int t,int l,int r)
{
    if (l!=r)
    {
        a[t<<1].tag+=a[t].tag;
        a[t<<1|1].tag+=a[t].tag;
    }
    a[t].s+=(int)(r-l+1)*a[t].tag;
    a[t].tag=0;
}
void add(int t,int l,int r,int x,int y,int z)
{
    if (x<=l&&r<=y) {a[t].tag+=z; return ;}
    a[t].s+=(int)(min(r,y)-max(l,x)+1)*z;
    update(t,l,r);
    int mid=(l+r)>>1;
    if (x<=mid) add(t<<1,l,mid,x,y,z);
    if (y>mid) add(t<<1|1,mid+1,r,x,y,z);
}
int sum(int t,int l,int r,int x,int y)
{
    int res=0;
    update(t,l,r);
    if (x<=l&&r<=y) return a[t].s;
    int mid=(l+r)>>1;
    if (x<=mid) res+=sum(t<<1,l,mid,x,y);
    if (y>mid) res+=sum(t<<1|1,mid+1,r,x,y);
    return res;
}
void work()
{
    int q,i,tx,ty; char tc;
    n=read(); q=read();
    tr(i,1,n) add(1,1,n,i,i,read());
    tr(i,1,q)
    {
        tc=getchar(); tx=read(); ty=read();
        if (tc=='A') add(1,1,n,tx,ty,read());
        else writeln(sum(1,1,n,tx,ty));
    }
}
