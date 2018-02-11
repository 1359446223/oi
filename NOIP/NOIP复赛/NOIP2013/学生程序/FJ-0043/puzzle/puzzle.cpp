#include<cstdio>
int n,m,q,a[31][31],aa[31][31],ex,ey,sx,sy,tx,ty,ans,flag;
void swap(int &x,int &y)
{
     int c=x;
     x=y;
     y=c;
}
void dfs(int x,int y,int xx,int yy,int step,int lastx,int lasty)
{
     int i,kk[4][2];
     kk[0][0]=-1;kk[1][0]=1;kk[2][0]=0;kk[3][0]=0;
     kk[0][1]=0;kk[1][1]=0;kk[2][1]=-1;kk[3][1]=1;
     if(xx==tx&&yy==ty)
     {
         if(ans>step)
         {
             ans=step;
             flag=step;
         }
         return;
     }
     if(step>flag)
         return;
     for(i=0;i<=3;i++)
     {
         if(aa[x+kk[i][0]][y+kk[i][1]]==1&&!(x+kk[i][0]==lastx&&y+kk[i][1]==lasty))
         {
             swap(aa[x][y],aa[x+kk[i][0]][y+kk[i][1]]);
             dfs(x+kk[i][0],y+kk[i][1],xx,yy,step+1,x,y);
             swap(aa[x][y],aa[x+kk[i][0]][y+kk[i][1]]);
         }
         if(aa[x+kk[i][0]][y+kk[i][1]]==2&&!(x+kk[i][0]==lastx&&y+kk[i][1]==lasty))
         {
             swap(aa[x][y],aa[x+kk[i][0]][y+kk[i][1]]);
             dfs(x+kk[i][0],y+kk[i][1],x,y,step+1,x,y);
             swap(aa[x][y],aa[x+kk[i][0]][y+kk[i][1]]);
         }
     }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    int i,j,k,kk[4][2],s;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    kk[0][0]=-1;kk[1][0]=1;kk[2][0]=0;kk[3][0]=0;
    kk[0][1]=0;kk[1][1]=0;kk[2][1]=-1;kk[3][1]=1;
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        s=0;
        for(j=0;j<=3;j++)
        {
            if(a[sx+kk[j][0]][sy+kk[j][1]]==1)
                s++;
        }
        if(s<2&&(!((tx-sx==1&&ty-sy==0)||(tx-sx==-1&&ty-sy==0)||(tx-sx==0&&ty-sy==1)||(tx-sx==0&&ty-sy==-1))))
        {
            printf("-1\n");
            continue;
        }
        s=0;
        for(j=0;j<=3;j++)
        {
            if(a[tx+kk[j][0]][ty+kk[j][1]]==1)
                s++;
        }
        if(s<2&&(!((tx-sx==1&&ty-sy==0)||(tx-sx==-1&&ty-sy==0)||(tx-sx==0&&ty-sy==1)||(tx-sx==0&&ty-sy==-1))))
        {
            printf("-1\n");
            continue;
        }
        for(j=1;j<=n;j++)
        for(k=1;k<=m;k++)
            aa[j][k]=a[j][k];
        aa[sx][sy]=2;
        ans=10000000;
        flag=17;
        dfs(ex,ey,sx,sy,0,0,0);
        if(ans!=10000000)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
