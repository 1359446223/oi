#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
//==================
int n,p,a[1000001],							//���� 
	tz[1000001],fs[1000001],				//��תվ 
	ALLAns;									//��� 

int A(int n) {								//n��������a[]���ֵ
	int Ans=0,Ans1=0; 
	int i;
    for (i=1; i<=n; i++) {
		if (a[i]>0) {
			Ans1=Ans1+a[i];
		}
		else {
			if (Ans1>Ans)
				Ans=Ans1;
			Ans1=0;
		}
	}
	if (Ans==0) {
		if (Ans1==0) {
			Ans=a[1];
			for (i=2; i<=n; i++)
				if(a[i]>Ans)
					Ans=a[i];
		}
		else
			Ans=Ans1;
	}
	return Ans;
}

int main ( ) {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //================================
    int i,j,
		s;									//fs�ٶ����ֵ�����á� 
	
	scanf("%d%d",&n,&p);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);

	tz[1]=a[1];
    fs[1]=a[1];
//  ��ʼ�������� 
    for (i=2; i<=n; i++)
		tz[i]=A(i);
//	�����������������ֵ���������� int A (...)�С� 
	for (i=2; i<=n; i++) {
		s=tz[1]+fs[1];
		for (j=1; j<i; j++)
			if(tz[j]+fs[j]>s)
				s=tz[j]+fs[j];
		fs[i]=s;
	}
//	������������˷���������ֵ�� 
	ALLAns=fs[1];
	for (i=1; i<=n; i++)
		if (fs[i]>ALLAns)
			ALLAns=fs[i];
//	���Դ�����С�������ҳ�����������һ���ķ����ˡ�
	if (ALLAns>p)
		ALLAns=ALLAns%p;
//	ALLAns���������Ĵ���ALLAns mod p)
	printf("%d\n",ALLAns);
	
	//================================
    fclose(stdin);
    fclose(stdout);
    system ("pause");
    return 0;
}
