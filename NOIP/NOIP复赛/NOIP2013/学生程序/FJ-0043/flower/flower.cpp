#include<cstdio>
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int i,n,h[100001],f[100001][2],l[100001][2],ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    f[1][0]=0;
    f[1][1]=0;
    l[1][0]=1;
    l[1][1]=1;
    for(i=2;i<=n;i++)
    {
        f[i][0]=n;
        f[i][1]=n;
    }
    for(i=2;i<=n;i++)
    {
        if(h[l[i-1][1]]>h[i])
        {
            f[i][0]=f[i-1][1];
            l[i][0]=i;
        }
        if(h[i]>h[l[i-1][1]]||h[i]==h[l[i-1][1]])
        {
            if(f[i][0]>f[i-1][1]+2)
            {
                f[i][0]=f[i-1][1]+2;
                l[i][0]=l[l[i-1][1]-1][0];
            }
        }
        if(h[l[i-1][0]]>h[i]||h[l[i-1][0]]==h[i])
        {
            if(f[i][0]>f[i-1][0]+1)
            {
                f[i][0]=f[i-1][0]+1;
                l[i][0]=i;
            }
        }
        if(h[i]>h[l[i-1][0]])
        {
            if(f[i][0]>f[i-1][0]+1)
            {
                f[i][0]=f[i-1][0]+1;
                l[i][0]=l[i-1][0];
            }
        }
        if(h[l[i-1][0]]<h[i])
        {
            f[i][1]=f[i-1][0];
            l[i][1]=i;
        }
        if(h[l[i-1][0]]>h[i]||h[l[i-1][0]]==h[i])
        {
            if(f[i][1]>f[i-1][0]+2)
            {
                f[i][1]=f[i-1][0]+2;
                l[i][1]=l[l[i-1][0]-1][1];
            }
        }
        if(h[l[i-1][1]]<h[i])
        {
            if(f[i][1]>f[i-1][1]+1)
            {
                f[i][1]=f[i-1][1]+1;
                l[i][1]=i;
            }
        }
        if(h[l[i-1][1]]>h[i]||h[l[i-1][1]]==h[i])
        {
            if(f[i][1]>f[i-1][1]+1)
            {
                f[i][1]=f[i-1][1]+1;
                l[i][1]=l[i-1][1];
            }
        }
    }
    if(f[n][0]<f[n][1])
        ans=n-f[n][0];
    else
        ans=n-f[n][1];
    printf("%d\n",ans);
    return 0;
}
