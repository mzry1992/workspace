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
厦门大学第四届程序设计竞赛 现场决赛 
*/

//这一题是给2*n-1个数字，其中有n-1对数字，有一个数字成单，问这个数字是多少。
//很容易可以用异或运算解决，首先需要了解这三个性质：
//（1），任何数与0的异或值还是这个数，即I XOR 0 = I
//（2），两个相同的数的异或值为0，即I XOR I = 0
//（3），异或运算满足交换律，即I XOR J XOR K = I XOR K XOR J
//首先令ans = 0，每读入一个数字a，令ans = ans^a，最后的结果即为ans
//（可以这样想，n-1对数加上一个不成对的数，由于异或满足交换律，可以把相等的
//数放一起，然后两两异或得0，最后只剩下一个不成对数和n-1个0，由性质（1）可以得到最
//后得到的答案显然就是那个数

#include <stdio.h>

long n,temp,ans;

int main()
{
    ans = 0;
    scanf("%ld",&n);
    for (int i = 1;i <= 2*n-1;i++)
    {
        scanf("%ld",&temp);
        ans = ans^temp; //异或操作 
    }
    printf("%ld\n",ans);
    return 0;
}                                          
