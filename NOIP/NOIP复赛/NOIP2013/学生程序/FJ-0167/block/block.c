#include<stdio.h>
int main()
{
      unsigned long a[100001],h[100001],i,t,n,max,m1,m2,l,r;
      freopen("block.in","r",stdin);
      freopen("block.out","w",stdout);
      scanf("%d",&n);
      for(i=1;i<=n;i++)
        scanf("%d",&h[i]); 
      for(i=1,max=0;i<=n;i++)
        {
         if(h[i]>max)
           max=h[i];
        }
      for(i=1,m1=0;i<=n;i++)
        {
         if(h[i]==max)
           m1=m1+1;
        }
      t=0;i=1;
      while(1)
        {
        for(i=1;i<=n;i++)
           { 
            if(a[i]<h[i])
              l=i;
            if(a[i]==h[i]||i==n)
             {
              r=i;
              break;
              }
            }
        for(i=l;i<=r;i++)
          a[i]=a[i]+1;
        t=t+1;
        for(i=1,m2=0;i<=n;i++)
           if(a[i]==max)
             m2=m2+1;
         if(m1==m2)
           break;
         else
           m2=0;
         }
      printf("%d\n",t);
     return 0;
}
