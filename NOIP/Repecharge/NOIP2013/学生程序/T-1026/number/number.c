#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* ʣ��20���� ���������
 * ˼· sp[k]�ǵ�kС���ѵ�����ֵ��f[k]��ǰk��С������������λС���ѵ����ֵ �� sum[k]��ǰkλС���ѵĺ� 
 * ��������ֵ��f[n] % k 
 */ 
int sp[1000002], f[1000002], pt[1000002], sum[1000002]; 

int main(void){
	int n = 0, p = 0, k = 0, j = 0, max = 0;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d %d", &n, &p);
	sp[0] = 0;
	for(k = 1; k <= n; k++){
		scanf("%d", &sp[n]);
		sum[k] = sp[n] + sp[n - 1];
	}
	f[0] = 0;
	f[1] = sp[1];
	for(k = 2; k <= n; k++){
		max = sum[k] - sum[1];
		for(j = 2; j < k; j++){
			if(sum[k] - sum[j - 1] > max){
				max = sum[k] - sum[j - 1];
			}
		}
		f[k] = max;
	}
	pt[0] = 0;
	pt[1] = f[1];
	for(k = 2; k <= n; k++){
		max = pt[1] + f[1];
		for(j = 2; j <= k; j++){
			if(pt[j] + f[j] > max){
				max = pt[j] + f[j]; 
			}
		}
		pt[k] = max;
	}
	printf("%d", pt[n] % p);
	return 0;
} 
