#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MOD = 1000000007;
class GooseInZooDivOne
{
	public:
	int count(vector <string> field, int dist)
	{
		vector <int> num;
		bool used[100][100];
		long long dp[2510];
		memset(used, 0, sizeof(used));		
		vector < pair<int, int> > que;
		
		//number precalculation
		for(int i = 0; i < field.size(); i++)
			for(int j = 0; j < field[0].size(); j++)
				if(field[i][j] == 'v' && !used[i][j])
				{
					que.clear();
					que.push_back( make_pair(i, j) );
					used[i][j] = true;
					int front = 0;
					while(front < que.size())
					{
						int nr = que[front].first, nc = que[front].second;
						for(int a = 0; a <= dist; a++)
							for(int b = 0; a+b <= dist; b++)
							{
								int newr = nr-a, newc = nc-b;
								if(newr >= 0 && newr < field.size() && newc >= 0 && newc < field[0].size() && !used[newr][newc] && field[newr][newc] == 'v')
								{
									que.push_back( make_pair(newr, newc) );
									used[newr][newc] = true;
								}
								newr = nr-a, newc = nc+b;
								if(newr >= 0 && newr < field.size() && newc >= 0 && newc < field[0].size() && !used[newr][newc] && field[newr][newc] == 'v')
								{								
									que.push_back( make_pair(newr, newc) );
									used[newr][newc] = true;
								}
								newr = nr+a, newc = nc+b;
								if(newr >= 0 && newr < field.size() && newc >= 0 && newc < field[0].size() && !used[newr][newc] && field[newr][newc] == 'v')
								{								
									que.push_back( make_pair(newr, newc) );
									used[newr][newc] = true;
								}
								newr = nr+a, newc = nc-b;
								if(newr >= 0 && newr < field.size() && newc >= 0 && newc < field[0].size() && !used[newr][newc] && field[newr][newc] == 'v')
								{								
									que.push_back( make_pair(newr, newc) );
									used[newr][newc] = true;
								}
							}
						++front;
					}
					num.push_back( que.size() );
				}
		
		//DP
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		
		int sum = 0;
		for(int i = 0; i < num.size(); i++)
		{
			for(int j = sum; j >= 0; j--)
			{
				dp[ j+num[i] ] = (dp[ j+num[i] ] + dp[j])%MOD;
			}
			sum += num[i];
		}
		
		long long ret = 0;
		for(int i = 2; i <= sum; i+=2)
			ret = (ret + dp[i])%MOD;
		return ret;
	}
};