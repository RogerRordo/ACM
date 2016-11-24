#define maxpn 10005
#define nonx 1E100
#define eps 1E-8
const double pi=acos(-1.0);
int cmp(double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
double sqr(double a){return a*a;}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
struct point
{
    double x,y;
    point(){}
    point(double a,double b){x=a;y=b;}
    
    friend point operator+(point a,point b){return point(a.x+b.x,a.y+b.y);}
    friend point operator-(point a,point b){return point(a.x-b.x,a.y-b.y);}
    friend point operator-(point a){return point(-a.x,-a.y);}
    friend double operator*(point a,point b){return a.x*b.x+a.y*b.y;}
    friend point operator*(double a,point b){return point(a*b.x,a*b.y);}
    friend point operator*(point a,double b){return point(a.x*b,a.y*b);}
    friend point operator/(point a,double b){return point(a.x/b,a.y/b);}
    friend double operator^(point a,point b){return a.x*b.y-a.y*b.x;}
    friend bool operator==(point a,point b){return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;}
    
    friend double sqr(point a){return a*a;}
    friend double len(point a){return sqrt(sqr(a));}    //模长
    friend point rotate(point a,double b){return point(a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b));}   //逆时针旋转
    friend double angle(point a,point b){return acos(a*b/len(a)/len(b));}   //夹角
    friend point reflect(point a,point b){return 2*a-b;}    //以a为中心对称
} ;
const point nonp=point(nonx,nonx);
point quad(double A,double B,double C)
{
    double delta=sqr(B)-4*A*C;
    if (delta<0) return nonp;
    return point((-B-sqrt(delta))/(2*A),(-B+sqrt(delta))/(2*A));
}
struct line
{
    point a,b;
    line(){}
    line(point pa,point pb){a=pa;b=pb;}
    point dir(){return b-a;}
    
    friend point proj(point a,line b){double t=(a-b.a)*b.dir()/sqr(b.dir());return point(b.a+t*b.dir());}   //垂足
    friend double dist(point a,line b){return ((a-b.a)^(b.b-b.a))/len(b.dir());}    //点到线距离
    friend bool onray(point a,line b){return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*b.dir())>=0;} //判断点在射线上
    friend bool onseg(point a,line b){return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*(a-b.b))<=0;} //判断点在线段上
    friend bool online(point a,line b){return cmp((a-b.a)^b.dir())==0;} //判断点在直线上
    friend bool parallel(line a,line b){return cmp(a.dir()^b.dir())==0;}    //判断两线平行
    friend point cross(line a,line b)   //线交
    {
        double t;
        if (cmp(t=a.dir()^b.dir())==0) return nonp;
        return a.a+((b.a-a.a)^b.dir())/t*a.dir();
    }
} ;
const line nonl=line(nonp,nonp);
struct circle
{
    point o; double r;
    circle(){}
    circle(point a,double b){o=a;r=b;}
    
    friend double S(circle a){return pi*sqr(a.r);}  //面积
    friend double C(circle a){return 2*pi*a.r;} //周长
    friend line cross(line a,circle b)  //线圆交
	{
		point t=quad(sqr(a.dir()),2*a.dir()*(a.a-b.o),sqr(a.a-b.o)-sqr(b.r));
		if (t==nonp) return nonl;
		return line(a.a+t.x*a.dir(),a.a+t.y*a.dir());
	}
    friend int in(point a,circle b){double t=len(a-b.o);return t==b.r?2:t<b.r;} //点与圆位置关系 0外 1内 2上
    //friend line cross(circle a,circle b){}
    //friend line tangent(point a,circle b){}
    //friend pair<line,line> tangent(circle a,circle b){}
    //friend double unionS(int n,circle*a) //圆面积并
    //{}
} ;
struct triangle//t 因triangle亦属polygon，故省去许多函数
{
    point a,b,c;
    triangle(){}
    triangle(point ta,point tb,point tc){a=ta;b=tb;c=tc;}
    
    friend double S(triangle a){return abs((a.b-a.a)^(a.c-a.a))/2;} //面积
    friend double C(triangle a){return len(a.a-a.b)+len(a.a-a.c)+len(a.a-a.c);} //周长
    friend circle outcircle(triangle a) //外接圆
    {
        circle res; point t1=a.b-a.a,t2=a.c-a.a;
        double t=2*t1^t2;
        res.o.x=a.a.x+(sqr(t1)*t2.y-sqr(t2)*t1.y)/t;
        res.o.y=a.a.y+(sqr(t2)*t1.x-sqr(t1)*t2.x)/t;
        res.r=len(res.o-a.a);
        return res;
    }
    friend circle incircle(triangle a)  //内切圆
    {
        circle res; double x=len(a.b-a.c),y=len(a.c-a.a),z=len(a.a-a.b);
        res.o=(a.a*x+a.b*y+a.c*z)/(x+y+z);
        res.r=dist(res.o,line(a.a,a.b));
        return res;
    }
    friend point gc(triangle a){return (a.a+a.b+a.c)/3;}    //重心
    friend point hc(triangle a){return 3*gc(a)-2*outcircle(a).o;}   //垂心
} ;
struct polygon
{
    int n; point a[maxpn];  //逆时针！
    polygon(){}
    polygon(triangle t){n=3;a[1]=t.a;a[2]=t.b;a[3]=t.c;}
    point& operator[](int _){return a[_];}
    
    friend double S(polygon a)  //面积 O(n)
    {
        int i; double res=0;
        a[a.n+1]=a[1];
        tr(i,1,a.n) res+=a[i]^a[i+1];
        return res/2;
    }
    friend double C(polygon a) //周长 O(n)
    {
        int i; double res=0;
        a[a.n+1]=a[1];
        tr(i,1,a.n) res+=len(a[i+1]-a[i]);
        return res;
    }
    friend int in(point a,polygon b)  //点与多边形位置关系 0外 1内 2上 O(n)
    {
        int s=0,i,d1,d2,k;
        b[b.n+1]=b[1];
        tr(i,1,b.n)
        {
            if (onseg(a,line(b[i],b[i+1]))) return 2;
            k=cmp((b[i+1]-b[i])^(b[i]-a));
            d1=cmp(b[i].y-a.y);
            d2=cmp(b[i+1].y-a.y);
            s=s+(k>0&&d2<=0&&d1>0)-(k<0&&d1<=0&&d2>0);
        }
        return s!=0;
    }
    friend point gc(polygon a)  //重心 O(n)
    {
        double s=S(a); point t(0,0); int i;
        if (cmp(s)==0) return nonp;
        a[a.n+1]=a[1];
        tr(i,1,a.n) t=t+(a[i]+a[i+1])*(a[i]^a[i+1]);
        return t/s/6;
    }
    friend int pick_on(polygon a)  //皮克求边上格点数 O(n)
    {
        int s=0,i;
        a[a.n+1]=a[1];
        tr(i,1,a.n) s+=gcd(abs(int(a[i+1].x-a[i].x)),abs(int(a[i+1].y-a[i].y)));
        return s;
    }
    friend int pick_in(polygon a){return int(S(a))+1-pick_on(a)/2;} //皮克求多边形内格点数 O(n)
    
    //friend line convex_maxdist(polygon a){}
    //friend line mindist(polygon a){} //a只是点集
    //friend polygon convex_hull(polygon a){} //a只是点集 O(nlogn)
    //friend int convex_in(point a,polygon b){} //0外 1内 2上 O(logn)
    //friend polygon cross(polygon a,polygon b){}
    //friend polygon cross(line a,polygon b){}
    //friend double unionS(circle a,polygon b){}
    friend circle mincovercircle(polygon a) //最小圆覆盖 O(n)
    {
        circle t; int i,j,k;
        srand(time(0));
        random_shuffle(a.a+1,a.a+a.n+1);
        for(i=2,t=circle(a[1],0);i<=a.n;i++) if (!in(a[i],t))
            for(j=1,t=circle(a[i],0);j<i;j++) if (!in(a[j],t))
                for(k=1,t=circle((a[i]+a[j])/2,len(a[i]-a[j])/2);k<j;k++) if (!in(a[k],t))
                    t=outcircle(triangle(a[i],a[j],a[k]));
        return t;
    }
} ;
