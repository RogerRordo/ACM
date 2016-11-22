int n,i,f[maxn];
void modify(int x,int y)
{
    while (x) {f[x]+=y; x-=x&-x;}
}
int sum(int x)
{
    int res=0;
    while (x<=n) {res+=f[x]; x+=x&-x;}
    return res;
}
void work()
{
    int q,i;
    n=read(); q=read();
    memset(f,0,sizeof(f));
    tr(i,1,q)
    {
        tc=getchar();
        if (tc=='M') {modify(read()-1,-1); modify(read(),1);}
        else writeln(sum(read()));
    }
}
