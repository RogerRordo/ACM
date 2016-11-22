int n,a[maxn],f[maxn];
char tc;
void modify(int x,int y)
{
    while (x<=n) {f[x]+=y; x+=x&-x;}
}
int sum(int x)
{
    int res=0;
    while (x) {res+=f[x]; x-=x&-x;}
    return res;
}
void work()
{
    int q,i,tx,ty;
    n=read(); q=read();
    memset(f,0,sizeof(f));
    tr(i,1,n) modify(i,a[i]=read());
    tr(i,1,q)
    {
        tc=getchar(); tx=read(); ty=read();
        if (tc=='M') {modify(tx,ty-a[tx]); a[tx]=ty;}
        else writeln(sum(ty)-sum(tx-1));
    }
}
