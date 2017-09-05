int n,i,f[maxn];
void add(int x,int y)
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
        if (tc=='M') {add(read()-1,-1); add(read(),1);}
        else writeln(sum(read()));
    }
}
