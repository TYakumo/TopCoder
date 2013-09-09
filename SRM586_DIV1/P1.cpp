#include <vector>
#include <algorithm>
using namespace std;

class PiecewiseLinearFunction
{
	public:
	int maximumSolutions(vector <int> Y)
	{
		int ret = 0;
		for(int i = 0; i < Y.size(); i++)
			Y[i] <<= 1;
			
		for(int i = 1; i < Y.size(); i++)
			if(Y[i] == Y[i-1])
				return -1;
		vector <int> p;
		
		for(int i = 0; i < Y.size(); i++)
		{
			p.push_back( Y[i] );
			p.push_back( Y[i]+1 );
			p.push_back( Y[i]-1 );
		}
		
		for(int i = 0; i < p.size(); i++)
		{
			int res = 0;
			for(int j = 1; j < Y.size(); j++)
			{
				int minV = min(Y[j], Y[j-1]), maxV = max(Y[j], Y[j-1]);
				if(p[i] > minV && p[i] < maxV)
					++res;
				else if(p[i] == Y[j-1])
					++res;
				else if(p[i] == Y[j] && j == Y.size()-1)
					++res;
			}
			ret = max(ret, res);
		}
		return ret;
	}
};