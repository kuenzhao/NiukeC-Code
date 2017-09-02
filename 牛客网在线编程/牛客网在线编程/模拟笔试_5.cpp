#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//
//#include <iostream>
//using namespace std;
//const int MAXN = 1000000 + 10;
//const int MOD = 1000000007;
//
//int cnt, dp[MAXN], prime[MAXN];
//
//void init() {
//	// prime
//	memset(dp, 0, sizeof(dp));
//	cnt = 0;
//	for (int i = 2; i<MAXN; ++i) 
//	{
//		if (dp[i] == 0) 
//		{
//			prime[cnt++] = i;
//			for (int j = 2 * i; j<MAXN; j += i) 
//			{
//				dp[j] = 1;
//			}
//		}
//	}
//}
//
//int main() {
//
//	int n;
//
//	init();
//	while (scanf("%d", &n) != EOF) {
//		long long ans = 1, ct = 1, tmp;
//
//		for (int i = 0; i<cnt && prime[i] <= n; ++i)
//		{
//			tmp = prime[i];
//			ct = 1;
//			while (tmp <= n) {
//				tmp *= prime[i];
//				++ct;
//			}
//			ans = (ans * ct) % MOD;
//		}
//
//		printf("%lld\n", ans);
//	}
//
//	return 0;
//}


/*˼·�� 1.��i��������������ôdp[i] = dp[i - 1] * 2��������Ϊ������ǰ�����������û��������ϵ�����YN���� 
2.��i���������������ݴΣ�Ҳ������6���������֣���ᷢ�֣����Ѿ���2, 3Ψһȷ���ˣ�����23�ֱ���YY����ô6һ����Y��
	23�ֱ���YN��NY��NN��6һ����N������˵��ʱ����dp[i] = dp[i - 1]
3.��i�������������ݴΣ�������Ψһȷ��������4����2ΪYʱ��4��ȷ����������Y��Ҳ������N����4��2���뼯�ϣ���2ȡ��4�ض�ȡ��
������NN��YN��YY�����������ô����һ�£�����8����3��Ԫ�صļ��ϣ���4�������9����2��Ԫ�صļ��ϣ�3��9������3�������
�Դ����ơ������Щ�����˼��ɣ���Ϊ��Щ����֮���໥��Ӱ��*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

const int MOD = 1E9 + 7;
const int maxn = 1e6 + 5;

int vis[maxn];

int main()
{
	int n;
	while (cin >> n)
	{
		long long ans = 1;

		for (int i = 2; i <= n; i++)
		{
			int cnt = 0;
			if (vis[i])
				continue;
			for (int j = i + i; j <= n; j += i)        //�������ı���
			{
				vis[j] = 1;
			}
			//��i���ݴ�
			long long mi = i;       //�� int �����
			while (mi <= n)
			{
				cnt++;
				mi *= i;
			}

			ans = ans * (cnt + 1) % MOD;
		}
		cout << ans << endl;
	}
}