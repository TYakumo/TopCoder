#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class UndoHistory
{
	public:
	int minPresses(vector <string> lines)
	{	
		int ret = lines[0].size()+lines.size();
		for(int i = 1; i < lines.size(); i++)
		{			
			int best = 10000;
			for(int k = 0; k < i; k++)
			{
				int cost = lines[i].size(), len = min(lines[k].size(), lines[i].size());
				bool failedFlag = false;
				for(int j = 0; j < len; j++)
					if(lines[k][j] == lines[i][j])
					{
						--cost;		
					}
					else
					{
						failedFlag = true;
						break;
					}
					
				if(failedFlag || lines[k] != lines[i-1] || lines[k].size() != len) cost += 2;
				best = min(best, cost);
			}
			ret += best;
		}
		return ret;
	}
};