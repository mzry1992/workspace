// POJ 1142

#include <iostream>
#include <cmath>
using namespace std;

int n,ans,atot,btot;

int getatot(int ans) //����ans �ĸ�λ����������֮�� 
{
    int temp;
    temp = 0;
    while (ans != 0)
    {
          temp += ans%10;
          ans /= 10;
    }
    return temp;
}


int prime(int i) //�ж�i�Ƿ�Ϊ����������Ƿ���0�����򷵻�1 
{
    int j,k;
    k = (int)sqrt(i);
    if (i == 2) return 0;
    if (i%2 == 0) return 1;
    for (j = 3;j <= k;j++)
        if (i%j == 0) return 1;
    return 0;
}

int getbtot(int ans) //���η���ans��������������λ����֮�� 
{
    int i;
    if (prime(ans) == 0) return getatot(ans); //�������������ô����������ĸ�λ��֮�� 
    for (i = 2;i <= (int)sqrt(ans);i++)
    if (ans%i == 0)
       return getbtot(i)+getbtot(ans/i); //����ֳ��������������δ����������� 
}

int main()
{
    cin >> n;
    while (n != 0)
    {
          for (ans = n+1;;ans++) //��n+1��ʼö�� 
          if (prime(ans) == 1)
          {
              atot = getatot(ans);
              btot = getbtot(ans);
              if (atot == btot)
              {
                       cout << ans << endl;
                       break;
              }
          }
          cin >> n;
    }
    return 0;
}
