#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int getnum(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch-'0';
    return ch-'A'+10;
}

int a[4][4],c[4][4];
unsigned char b[4];
char buf[5];

void output(int num)
{
    printf("%02X",num);
}

int d(int num)
{
    if (num > 0xff)
        return num^0x1b;
    return num;
}

void gmix_column(unsigned char *r)
{
    unsigned char a[4];
    unsigned char b[4];
    unsigned char c;
    unsigned char h;
    /* The array 'a' is simply a copy of the input array 'r'
     * The array 'b' is each element of the array 'a' multiplied by 2
     * in Rijndael's Galois field
     * a[n] ^ b[n] is element n multiplied by 3 in Rijndael's Galois field */
    for(c=0; c<4; c++)
    {
        a[c] = r[c];
        /* h is 0xff if the high bit of r[c] is set, 0 otherwise */
        h = (unsigned char)((signed char)r[c] >> 7); /* arithmetic right shift, thus shifting in either zeros or ones */
        b[c] = r[c] << 1; /* implicitly removes high bit because b[c] is an 8-bit char, so we xor by 0x1b and not 0x11b in the next line */
        b[c] ^= 0x1B & h; /* Rijndael's Galois field */
    }
    r[0] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1]; /* 2 * a0 + a3 + a2 + 3 * a1 */
    r[1] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2]; /* 2 * a1 + a0 + a3 + 3 * a2 */
    r[2] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3]; /* 2 * a2 + a1 + a0 + 3 * a3 */
    r[3] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0]; /* 2 * a3 + a2 + a1 + 3 * a0 */
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                scanf("%s",buf);
                a[i][j] = getnum(buf[0])*16+getnum(buf[1]);
            }
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0;i < 4;i++)
                b[i] = a[i][j];
            gmix_column(b);
            for (int i = 0;i < 4;i++)
                c[i][j] = b[i];
        }
        for (int i = 0; i < 4; i++)
        {
            output(c[i][0]);
            for (int j = 1; j < 4; j++)
            {
                printf(" ");
                output(c[i][j]);
            }
            puts("");
        }
        if (cas < totcas)
            puts("");
    }
    return 0;
}
