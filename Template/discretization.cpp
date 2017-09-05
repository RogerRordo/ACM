//dc[1,2,...]=[x1,x2,..]; rdc(x1,x2,...)=1,2,...
int n,a[maxn],dc[maxn];
int rdc(int x){return lower_bound(dc+1,dc+num+1,x)-dc;}
void init()
{
    //...
    memcpy(dc,a,(n+1)*sizeof(int));
    sort(dc+1,dc+n+1);
    num=unique(dc+1,dc+n+1)-(dc+1);
}
