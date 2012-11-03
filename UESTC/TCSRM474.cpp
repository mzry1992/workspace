#include <string>
using namespace std;

class PalindromesCount
{
      public:
      int count(string A,string B)
      {
          int ans,i,j,la,lb,lt;
          char temp[100];
          bool flag;
          la = lb = ans = 0;
          while (A[la] != '\0')  la++;
          while (B[lb] != '\0')  lb++;
          for (i = 0;i <= la;i++)
          {
              lt = 0;
              for (j = 0;j <= i-1;j++)
              {
                  temp[lt] = A[j];
                  lt++;
              }
              for (j = 0;j < lb;j++)
              {
                  temp[lt] = B[j];
                  lt++;
              }
              for (j = i;j < la;j++)
              {
                  temp[lt] = A[j];
                  lt++;
              }
              lt--;
              flag = true;
              for (j = 0;j <= lt/2;j++)
              if (temp[j] != temp[lt-j])
                 flag = false;
              if (flag == true)
                 ans++;
          }                 
          return ans;
      };
};      
