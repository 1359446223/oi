#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int fa[50001],army[50001],edge[50001],link[50001],first[50001];
bool used[50001];
long long ans=0,to[50001],dist[50001],every[50001][1001];
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    int i,j,n,m,u,v,w,r,t=0,mina=0;
    memset(fa,0,sizeof(fa));
    memset(dist,0,sizeof(dist));
    memset(used,false,sizeof(used));
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      if(u==1||v==1)
      {
        if(u==1)
        {
          fa[v]=u;
          edge[v]=w;
          link[++t]=v;
        }
        else
        {
          fa[u]=v;
          edge[u]=w;
          link[++t]=u;
        }
        mina++;
      }
      else
        if(fa[v]!=0)
        {
          fa[u]=v;
          edge[u]=w;
        }
        else
        {
          fa[v]=u;
          edge[v]=w;
        }
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
      scanf("%d",&army[i]);
    if(m<mina)
      printf("-1\n");
    else
    {
      for(i=1;i<=t;i++)
        to[link[i]]=-1;
      for(i=1;i<=m;i++)
      {
        r=army[i];
        while(fa[r]!=0)
        {
          dist[i]=dist[i]+edge[r];
          r=fa[r];
        }
        r=army[i];
        while(fa[r]!=1)
          r=fa[r];
        first[i]=r;
      }
      for(i=1;i<=m;i++)
        for(j=1;j<=t;j++)
          if(link[j]==first[i])
            every[i][j]=dist[i]-edge[link[j]];
          else
            every[i][j]=dist[i]+edge[link[j]];
      for(j=1;j<=t;j++)
        for(i=1;i<=m;i++)
          if(to[link[j]]==-1&&!used[i])
          {
            to[link[j]]=every[i][j];
            used[i]=true;
          }
          else
            if(every[i][j]<to[link[j]]&&!used[i])
            {
              to[link[j]]=every[i][j];
              used[i]=true;
            }
      for(i=1;i<=t;i++)
        ans=ans+to[link[i]];
      printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
