//maxt=文本串长，maxp=模式串长，maxn=模式串数
struct ac{int s,to[26],fail;} a[maxn*maxp];
int m,n;
char ts[maxp],s[maxt];
queue<int> b;
void clear(int x)
{
    a[x].s=a[x].fail=0;
    memset(a[x].to,0,sizeof(a[x].to));
}
void ins(char *st)
{
    int i,x=0,c,l=strlen(st);
    tr(i,0,l-1)
    {
        if (!a[x].to[c=st[i]-'a']) {a[x].to[c]=++m; clear(m);}
        x=a[x].to[c];
    }
    a[x].s++;
}
void build()
{
    int i,h,t;
    tr(i,0,25) if (t=a[0].to[i]) b.push(t);
    while (b.size())
    {
        h=b.front(); b.pop();
        tr(i,0,25)
        if (t=a[h].to[i])
        {
            a[t].fail=a[a[h].fail].to[i];
            b.push(t);
        } else a[h].to[i]=a[a[h].fail].to[i];
    }
}
int cnt(char *st)
{
    int i,x=0,c,t,cnt=0,l=strlen(st);
    tr(i,0,l-1)
    {
        c=st[i]-'a';
        while (!a[x].to[c]&&x) x=a[x].fail;
        x=a[x].to[c];
        for(t=x;t&&a[t].s>-1;t=a[t].fail) {cnt+=a[t].s; a[t].s=-1;}
    }
    return cnt;
}
void work()
{
    int i;
    m=0; clear(0);
    scanf("%d",&n);
    tr(i,1,n)
    {
        scanf("%s",ts); ins(ts);
    }
    build();
    scanf("%s",s); printf("%d\n",cnt(s));
}
