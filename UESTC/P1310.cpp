#include <iostream>
using namespace std;

int t,ft,r,c,n,k,link[600];//link����ƥ��� 
bool map[600][600],cover[600];//map�������ͼ��cover���һ�����Ƿ�Ϊ���͵� 

void readin() //���ݶ��� 
{
     int i,j;
     cin >> n >> k;
     for (i = 1;i <= n;i++)
     for (j = 1;j <= n;j++)
         map[i][j] = false;
     for (i = 1;i <= k;i++)
     {
         cin >> r >> c;
         map[r][c] = true;
     }
}

bool find(int i) //��i������Ѱ��������������ҵ�����true�����򷵻�false 
{
     int k,q;
     for (k = 1;k <= n;k++) //�˴������Ż������ȿ���δƥ��߿������޼ӿ��ٶ� 
     if ((map[i][k] == true) && (cover[k] == false))
     {
                    q = link[k];
                    link[k] = i;
                    cover[k] = true;
                    if ((q == 0) || (find(q) == true))  return true; //������� 
                    link[k] = q;
     }
     return false;
}

void km() //KM�㷨 
{
     int i,j;
     for (i = 1;i <= n;i++)
         link[i] = 0;
     for (i = 1;i <= n;i++) //ö��ÿ���� 
     {
         for (j = 1;j <= n;j++)
             cover[j] = false;
         find(i);
     }
}
     
void count() //�ۼӴ� 
{
     int i,ans;
     ans = 0;
     for (i = 1;i <= n;i++)
     if (link[i] != 0) ans++;
     cout << ans << endl;
}

int main()
{
    cin >> t;
    for (ft = 1;ft <= t;ft++)
    {
        readin();
        km();
        count();
    }
    return 0;
}
