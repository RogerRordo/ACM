//！！注意！！__builtin_clz只有g++能用
//x为int时，31-__builtin_clz(x) 等价于 int(log(x)/log(2))
//x为ll时，63-__builtin_clzll(x) 等价于 (ll)(log(x)/log(2))
int n,q,mn[maxn][maxln];
void init()
{
    int i;
    n=read(); q=read();
    tr(i,1,n) mn[i][0]=read();
}
void st()
{
    int i,j,ln;
    ln=31-__builtin_clz(n);
    tr(i,1,ln) tr(j,1,n-(1<<i)+1)
        mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
}
void work()
{
    int i,x,y,t;
    st();
    tr(i,1,q)
    {
        x=read(); y=read();
        t=31-__builtin_clz(y-x+1);
        writeln(min(mn[x][t],mn[y-(1<<t)+1][t]));
    }
}
