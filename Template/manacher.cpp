//st，s都从1开始！
//      1 2 3 4 5 6 7 8
// st:  a b a
//  s:  0 0 a 0 b 0 a 0
//  a:  0 0 1 2 3 2 1 0
int a[2*maxl];
char st[maxl],s[2*maxl];
int manacher()
{
    int l=strlen(st+1),i,Mm,Mr=0,ans=0;
    memset(a,0,sizeof(a)); s[1]=0xFF;
    tr(i,2,2*l+2) s[i]=(i&1)*st[i/2];
    tr(i,1,2*l+2)
    {
        if (i<Mr) a[i]=min(a[2*Mm-i],Mr-i);
        while (s[i-a[i]-1]==s[i+a[i]+1]) a[i]++;
        if (i+a[i]>Mr) {Mr=i+a[i]; Mm=i;}
        ans=max(ans,a[i]);
    }
    return ans;
}
int main()
{
    gets(st+1); printf("%d\n",manacher());
    return 0;
}
