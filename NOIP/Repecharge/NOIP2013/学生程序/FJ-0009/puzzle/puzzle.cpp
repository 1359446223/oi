#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#define MXN 32
#define MXQ 510
#define MXS 250010
#define INF 0xfffffff//INF<memset(0x7f)
using namespace std;//n��m 
int n,m,qury;
int map[MXN][MXN];
int ex[MXQ],ey[MXQ],sx[MXQ],sy[MXQ],tx[MXQ],ty[MXQ];
void init()
{
     scanf("%d%d%d",&n,&m,&qury);
     for (int i=1;i<=n;i++)
     {
       for (int j=1;j<=m;j++)
         scanf("%d",&map[i][j]);
     }//0�̶���1����
     for (int i=1;i<=qury;i++)
       scanf("%d%d%d%d%d%d",&ex[i],&ey[i],&sx[i],&sy[i],&tx[i],&ty[i]); 
}
//ex ey��empty����
//tx ty��Ŀ�꣡�� 
//�Ķ� quryΪ������� 
//����get��sol���鸨�� 
//m n������� n���������ã� 
struct node
{
       int x,y,p,q;//x,y��Ŀ�����ӣ�p,q�ǿո񣡣�
}q[MXS]; //���״̬�� 
int head,tail;
bool vis[MXN][MXN][MXN][MXN];//vis[x][y][p][q] ΪĿ��������x��y���ո���p��q 
int f[MXN][MXN][MXN][MXN];//f[x][y][p][q] ΪĿ��������x��y���ո���p��q 
int dx[5]={0,-1,0,1,0},dy[5]={0,0,1,0,-1};
void bfs(int ex,int ey,int sx,int sy)//bfs��tx ty�޹� 
{
     int newx,newy,newp,newq;
     memset(f,0x7f,sizeof(f));
     memset(vis,0,sizeof(vis));
     head=0;tail=1;
     q[0].x=sx;q[0].y=sy;q[0].p=ex;q[0].q=ey;
     vis[sx][sy][ex][ey]=1;
     f[sx][sy][ex][ey]=0;  
     while (head<tail)//head++!
     {
         for (int i=1;i<=4;i++)
         {
           int vx=q[head].p+dx[i],vy=q[head].q+dy[i];
           if (vx>=1&&vx<=n&&vy>=1&&vy<=m&&map[vx][vy]!=0) //�кϷ���״̬ 
           {
             if (vx==q[head].x&&vy==q[head].y)//�հ׺�Ŀ�����ӽ��� 
             {
               newx=q[head].p;newy=q[head].q;//�µ�Ŀ��������ԭ���Ŀո� 
               newp=vx;newq=vy;//�µĿո��ڽ�����λ�� 
             }
             else  
             {  
               newx=q[head].x;newy=q[head].y;
               newp=vx;newq=vy;//�µĿո��ڽ�����λ�� ,Ŀ�����Ӳ�Ӱ�� 
             }
             if (vis[newx][newy][newp][newq]==0)
             {
               vis[newx][newy][newp][newq]=1;
               f[newx][newy][newp][newq]=f[q[head].x][q[head].y][q[head].p][q[head].q]+1;
               q[tail].x=newx;
               q[tail].y=newy;
               q[tail].p=newp;
               q[tail].q=newq;
               tail++;
             }
           }
         }
         head++;
     }
}
void solve()
{
     int get[MXQ],sol[MXQ];
     int ans;
     memset(get,0,sizeof(get));
     for (int k=1;k<=qury;k++)
     {
       /*ans=INF;
       if (f[sx[k]][sy[k]][ex[k]][ey[k]]<INF)  
       {
         for (int i=1;i<=n;i++)
           for (int j=1;j<=m;j++)
             ans=min(f[tx[i]][ty[i]][i][j],ans);
         if (ans>=INF)  printf("-1\n");
         else  printf("%d\n",ans);
       }
       else
       {*/
       if (get[k]==0)
       {
         bfs(ex[k],ey[k],sx[k],sy[k]);
         for (int id=k;id<=qury;id++)
         {
           if (f[sx[id]][sy[id]][ex[id]][ey[id]]<INF)
           {
               ans=INF;
               for (int i=1;i<=n;i++)
                 for (int j=1;j<=m;j++)
                   ans=min(abs(f[tx[id]][ty[id]][i][j]-f[sx[id]][sy[id]][ex[id]][ey[id]]),ans);
               if (ans>=INF)  sol[id]=-1;
               else  sol[id]=ans;
               get[id]=1;
           }
         }
       }
     }
     
     for (int i=1;i<=qury;i++)
       printf("%d\n",sol[i]);
}      
int main ()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    init();
    solve();
    fclose(stdin);fclose(stdout);
    return 0;
}
