#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class RouteIntersection
{
      public:
      string isValid(int N, vector <int> coords, string moves)
      {
             string VALID,NVALID;
             int lm,i,j,tempp;
             int s[60],o[60],top,nt,ts,to;
             VALID = "VALID";
             NVALID = "NOT VALID";
             lm = top = nt = 0;
             while (moves[lm] != '\0')    lm++;
             for (i = lm-1;i >= 0;i--)
             {
                 ts = coords[i];
                 if (ts > N)    return NVALID;
                 if (moves[i] == '+') to = 1;
                 else         to = 0;
                 tempp = 0;
                 for (j = 1;j <= top;j++)
                 if (s[j] != 0)
                 if (s[j] == ts)
                 {
                          if (o[j] != to)
                             tempp = j;
                          else
                              return NVALID;
                 }
                 if (tempp == 0)
                 {
                           top++;
                           nt++;
                           s[top] = ts;
                           o[top] = to;
                 }
                 else
                 {
                           nt--;
                           s[tempp] = 0;
                 }              
                 if (nt == 0)   return NVALID;   
             }
             if (nt > 1)  return NVALID;
             return VALID;
      };
};      
