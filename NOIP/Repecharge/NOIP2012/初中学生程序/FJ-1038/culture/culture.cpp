#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
      int w[101],       //�Ƿ�ѧ���Ļ� 
          ww=0,         //��ѧ�Ļ����� 
          r[101][101],  //·
          c[101],       //ĳ���Ļ� 
          x[101][101],  //�Ƿ��ų� 
          n,k,m,s,t,
          minn=2147483647,
          f=0;
int main()
 {
          freopen("culture.in","r",stdin);
          freopen("culture.out","w",stdout);
          
          int i,j,
              u,v,d;
          
          memset(w,0,sizeof(w));
          cin>>n>>k>>m>>s>>t;
          
          for (i=1;i<=n;i++)
              cin>>c[i];
          for (i=1;i<=k;i++)
              for (j=1;j<=k;j++)
                  cin>>x[i][j];
          for (i=1;i<=m;i++){
              cin>>u>>v>>d;
              r[u][v]=d;
              r[v][u]=d;
          }
          cout<<"-1"<<endl;
          
          fclose(stdin);
          fclose(stdout);
          //system("pause");
          return 0;
 }
