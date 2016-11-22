int n;
bool out(point a,circle b){return cmp(len(a-b.o)-b.r)==1;}
circle get(point a){return circle(a,0);}
circle get(point a,point b){return circle((a+b)/2,len(a-b)/2);}
circle get(point a,point b,point c){return outcircle(triangle(a,b,c));}
void work()
{
    int i,j,k;
    srand(time(0));
    circle t;
    random_shuffle(a+1,a+n+1);
    for(i=2,t=get(a[1]);i<=n;i++) if (out(a[i],t))
        for(j=1,t=get(a[i]);j<i;j++) if (out(a[j],t))
            for(k=1,t=get(a[i],a[j]);k<j;k++) if (out(a[k],t))
                t=get(a[i],a[j],a[k]);
    printf("%.2lf %.2lf %.2lf\n",t.o.x,t.o.y,t.r);
}
