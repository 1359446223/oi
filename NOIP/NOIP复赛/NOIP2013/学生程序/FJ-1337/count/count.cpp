#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i,n,x,j,y;
	int f=0;
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		if(i==x)
		f++;
		else
		{
			if(i%10==x)
			f++;
			else
			{
				if(i%100==x)
				f++;
				else
				{
					if(i%1000==x)
					f++;
					else
					{
						if(i%10000==x)
						f++;
						else
						{
							if(i%100000==x)
		                    f++;
		                    else
		                    {
								if(i%1000000==x)
							    f++;
						    }
					    }
				    }
			    }
		    }
	    }
    }
    for(i=1;i<=n;i++)
    if(i/10==x)
    f++;
	else
	{
		if(i/100==x)
		f++;
		else
		{
			if(i/1000==x)
			f++;
			else
			{
				if(i/10000==x)
				f++;
				else
				{
					if(i/100000==x)
				    f++;
				    else
					{
						if(i/1000000==x)
						f++;
					}
				}
			}
		}
	}
	cout<<f<<endl;
	return 0;
} 
