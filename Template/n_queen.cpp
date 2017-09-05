int n,m;
void print(int x){writeb(++m); writeln(x);}
void solve()
{
    int i;
    if (n%6!=2&&n%6!=3)
    {
        for(i=2;i<=n;i+=2) print(i);
        for(i=1;i<=n;i+=2) print(i);
    } else
    {
        int k=n/2;
        if(k%2==0)
        {
            for(i=k;i<=n;i+=2) print(i);
            for(i=2;i<=k-2;i+=2) print(i);
            for(i=k+3;i<=n-1;i+=2) print(i);
            for(i=1;i<=k+1;i+=2) print(i);
            if (n%2==1) print(n);
        } else
        {
            for(i=k;i<=n-1;i+=2) print(i);
            for(i=1;i<=k-2;i+=2) print(i);
            for(i=k+3;i<=n;i+=2) print(i);
            for(i=2;i<=k+1;i+=2) print(i);
            if (n%2==1) print(n);
        }
    }
}
