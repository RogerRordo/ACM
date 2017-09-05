#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
char s1[5],s2[5],s3[5],ans[50];
int dats,i,x,y;
bool px,py,imp,ppp;
char b[4][3]={"A","B","AB","O"};
bool a[4][4][4]=
{
    {{1,0,0,1},{1,1,1,1},{1,1,1,0},{1,0,0,1}},
    {{1,1,1,1},{0,1,0,1},{1,1,1,0},{0,1,0,1}},
    {{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,0,0}},
    {{1,0,0,1},{0,1,0,1},{1,1,0,0},{0,0,0,1}}
};
void get(int &x,bool &p,char *s)
{
    if (strlen(s)==3){x=2;p=(s[2]=='+');return ;}
    if (s[0]=='A') x=0;
    else if (s[0]=='B') x=1;
    else x=3;
    p=(s[1]=='+');
}
int main()
{
    while (1)
    {
        dats++;
        scanf("%s%s%s",&s1,&s2,&s3);
        if (s1[0]=='E') break;
        printf("Case %d: ",dats);
        
        if (strcmp(s1,"O-")==0&&strcmp(s2,"O-")==0&&strcmp(s3,"?")==0)
        {puts("O- O- O-"); continue;}
        
        if (s1[0]=='?')
        {
            get(x,px,s2); get(y,py,s3);
            ppp=(!px&&py);
            memset(ans,0,sizeof(ans));
            strcat(ans,"{");
            imp=1;
            tr(i,0,3)
            if (a[i][x][y])
            {
                strcat(ans,b[i]); strcat(ans,"+, ");
                if (!ppp) {strcat(ans,b[i]); strcat(ans,"-, ");}
                imp=0;
            }
            if (imp)
            {
                ans[strlen(ans)-1]='\0';
                strcat(ans,"IMPOSSIBLE ");
            }
            else
            {
                ans[strlen(ans)-2]='\0';
                strcat(ans,"} ");
            }
            strcat(ans,b[x]);
            if (px) strcat(ans,"+ "); else strcat(ans,"- ");
            strcat(ans,b[y]);
            if (py) strcat(ans,"+"); else strcat(ans,"-");
        }
        if (s2[0]=='?')
        {
            get(x,px,s1); get(y,py,s3);
            ppp=(!px&&py);
            memset(ans,0,sizeof(ans));
            strcat(ans,b[x]);
            if (px) strcat(ans,"+ "); else strcat(ans,"- ");
            strcat(ans,"{");
            imp=1;
            tr(i,0,3)
            if (a[x][i][y])
            {
                strcat(ans,b[i]); strcat(ans,"+, ");
                if (!ppp) {strcat(ans,b[i]); strcat(ans,"-, ");}
                imp=0;
            }
            if (imp)
            {
                ans[strlen(ans)-1]='\0';
                strcat(ans,"IMPOSSIBLE ");
            }
            else
            {
                ans[strlen(ans)-2]='\0';
                strcat(ans,"} ");
            }
            strcat(ans,b[y]);
            if (py) strcat(ans,"+"); else strcat(ans,"-");
        }
        if (s3[0]=='?')
        {
            get(x,px,s1); get(y,py,s2);
            ppp=(!px&&!py);
            memset(ans,0,sizeof(ans));
            strcat(ans,b[x]);
            if (px) strcat(ans,"+ "); else strcat(ans,"- ");
            strcat(ans,b[y]);
            if (py) strcat(ans,"+ "); else strcat(ans,"- ");
            strcat(ans,"{");
            imp=1;
            tr(i,0,3)
            if (a[x][y][i])
            {
                if (!ppp) {strcat(ans,b[i]); strcat(ans,"+, ");}
                strcat(ans,b[i]); strcat(ans,"-, ");
                imp=0;
            }
            if (imp)
            {
                ans[strlen(ans)-1]='\0';
                strcat(ans,"IMPOSSIBLE ");
            }
            else
            {
                ans[strlen(ans)-2]='\0';
                strcat(ans,"}");
            }
        }
        puts(ans);
    }
    return 0;
}
