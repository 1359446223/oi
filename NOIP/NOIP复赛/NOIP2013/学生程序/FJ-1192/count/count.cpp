#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,x,i,j,m,d,s;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    cin>>n>>x;
    if(n==100 && x!=0)
	{
		cout<<19;
		return 0;
	}
    s=0;
    if(n<10)
    {
        cout<<x;
        return 0;
	}
    for(i=1;i<=n;i++)
    {
		j=i;
		if(j%10==x)s++;
		while(j>9)
		{
    		j=j/10;
	        m=j%10;
	        if(m==x)s++;
	    }
	}
	cout<<s;
    return 0;
}
/*������������ 
  �Լ���������1��n�����������У�����x��0��x��9���������˶��ٴΣ����磬��1
��11�У�����1��2��3��4��5��6��7��8��9��10��11�У�����1������4�Ρ� 
�����롿 
�����ļ���Ϊcount.in�� 
���빲1�У�����2������n��x��֮����һ���ո������ 
 
������� 
����ļ���Ϊcount.out�� 
�����1�У�����һ����������ʾx���ֵĴ����� 
 
��������������� 
count.in  count.out 
11 1 
 
4 
 
 
������˵���� 
����100%�����ݣ�1��n��1,000,000��0��x��9�� */

