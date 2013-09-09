const int MOD = 1000000007;
class TrafficCongestion
{
	public:
	int theMinCars(int treeHeight)
	{	
		long long dp[2], sum = 0, prev = 0;
		
		dp[0] = 1;
		for(int i = 0; i < treeHeight; i++)
		{		
			sum = (sum + prev)%MOD;
			dp[1] = (1+sum*2)%MOD;
			prev = dp[0];
			dp[0] = dp[1];
		}
		
		return dp[0];
	}
};