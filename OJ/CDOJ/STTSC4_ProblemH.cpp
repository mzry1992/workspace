/*
Problem H

The Lost Card  

Description 

Having signed a new contract, ArXoR was facing a new task. Given n cards each of which is labeled with an integer bounded in [-2^31,2^31 - 1], the task is to make a duplicate copy of these n cards. As usual, this dull work was assigned to TheBeet. After he finished duplicating, he brought the 2n cards to ArXoR. But after checking these cards again, they found that one card was lost. It is easy to make a duplication of a card, but not easy to find out which card should be duplicated a again. Could you help these two poor guys , especially, TheBeet.

Input 

The input contains a single case. The case begin with a integer n bounded in [1, 1000000].
Then 2 * n - 1 lines follows, as mentioned above, each of which indicating the integer on the card in TheBeet and ArXoR's hand.

Output 

You should output a single line containing the lost card you have found.

Sample Input 

3
35
4
2
4
35

Sample Output 

2

Source 
���Ŵ�ѧ���Ľ������ƾ��� �ֳ����� 
*/

//��һ���Ǹ�2*n-1�����֣�������n-1�����֣���һ�����ֳɵ�������������Ƕ��١�
//�����׿����������������������Ҫ�˽����������ʣ�
//��1�����κ�����0�����ֵ�������������I XOR 0 = I
//��2����������ͬ���������ֵΪ0����I XOR I = 0
//��3��������������㽻���ɣ���I XOR J XOR K = I XOR K XOR J
//������ans = 0��ÿ����һ������a����ans = ans^a�����Ľ����Ϊans
//�����������룬n-1��������һ�����ɶԵ���������������㽻���ɣ����԰���ȵ�
//����һ��Ȼ����������0�����ֻʣ��һ�����ɶ�����n-1��0�������ʣ�1�����Եõ���
//��õ��Ĵ���Ȼ�����Ǹ���

#include <stdio.h>

long n,temp,ans;

int main()
{
    ans = 0;
    scanf("%ld",&n);
    for (int i = 1;i <= 2*n-1;i++)
    {
        scanf("%ld",&temp);
        ans = ans^temp; //������ 
    }
    printf("%ld\n",ans);
    return 0;
}                                          
