#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

class TheUniverseUnravels
{
	public:
		vector <string> predictCoordinates(vector <string> coords, vector <string> ranks, vector <int> minDist, vector <int> maxDist)
		{
			int n=coords.size();
			vector <string> res;
			res.clear();
			for (int i=0;i<n;i++)
			{
				string s;
				s="500";
				for (int j=1;j<10;j++)
					s+=" 500";
				res.push_back(s);
			}
			return res;
		}
};
