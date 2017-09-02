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


/*思路： 1.第i个数是素数，那么dp[i] = dp[i - 1] * 2，这是因为素数和前面的所有数都没有依赖关系，因此YN都行 
2.第i个数不是素数的幂次，也就是像6这样的数字，你会发现，它已经被2, 3唯一确定了，例如23分别是YY，那么6一定是Y，
	23分别是YN或NY或NN，6一定是N，所以说这时候有dp[i] = dp[i - 1]
3.第i个数是素数的幂次，它不能唯一确定，比如4，当2为Y时，4不确定，可以是Y，也可以是N。将4和2放入集合，若2取，4必定取，
所以有NN，YN，YY三种情况。那么引申一下，加入8就是3个元素的集合，共4种情况，9就是2个元素的集合（3、9），有3种情况，
以此类推。最后将这些情况相乘即可，因为这些集合之间相互不影响*/
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
			for (int j = i + i; j <= n; j += i)        //处理他的倍数
			{
				vis[j] = 1;
			}
			//求i的幂次
			long long mi = i;       //用 int 会溢出
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