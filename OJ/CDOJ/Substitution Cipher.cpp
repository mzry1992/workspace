#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ys[26];
char word1[] = "Tnyp yp i cgfkaeb ikfht Phkptythtyfs Lycneg. Iaa aettegp ugfb i tf q ige biccej tf i cegbhtityfs fu tnebpeaxep, onyln beisp tnit yt yp i kydeltyfs. Mfh pnfhaj tgm tf jelgmct tne jeplgyctyfs. Kht onit mfh pnfhaj phkbyt yp tne cgfvgib tnit eslgmct tnyp jeplgctyfs. Tne tept yscht dhpt lfstiysp iaa fse-kmte lnigiltegp.";
char word2[] = "Tf bize yt eipyeg tf jelgmct, cigt fu oyzy cive fu Phkptythtyfs Lycneg yp whftej.";
char word3[] = "Ys lgmctfvgicnm, i phkptythtyfs lycneg yp i betnfj fu eslgmctyfs km onyln hsytp fu caiystert ige gecailej oytn lycnegtert illfgjysv tf i gevhaig pmpteb; tne hsytp bim ke pysvae aettegp (tne bfpt lfbbfs), ciygp fu aettegp, tgycaetp fu aettegp, byrthgep fu tne ikfxe, isj pf ufgtn. Tne geleyxeg jelycnegp tne tert km cegufgbysv is ysxegpe phkptythtyfs.";
char word4[] = "Phkptythtyfs lycnegp lis ke lfbcigej oytn tgispcfpytyfs lycnegp. Ys i tgispcfpytyfs lycneg, tne hsytp fu tne caiystert ige geiggisvej ys i jyuuegest isj hphiaam whyte lfbcaer fgjeg, kht tne hsytp tnebpeaxep ige aeut hslnisvej. Km lfstgipt, ys i phkptythtyfs lycneg, tne hsytp fu tne caiystert ige getiysej ys tne pibe pewhesle ys tne lycnegtert, kht tne hsytp tnebpeaxep ige iategej.";
char commad[10];

int main()
{
    for (int i = 0;i <= 'z'-'a';i++)
        ys[i] = 'A'-'a';
    for (int i = 0;i < strlen(word1);i++)
    if (word1[i] >= 'A' && word1[i] <= 'Z')
        word1[i] = word1[i]+32;
    for (int i = 0;i < strlen(word2);i++)
    if (word2[i] >= 'A' && word2[i] <= 'Z')
        word2[i] = word2[i]+32;
    for (int i = 0;i < strlen(word3);i++)
    if (word3[i] >= 'A' && word3[i] <= 'Z')
        word3[i] = word3[i]+32;
    for (int i = 0;i < strlen(word4);i++)
    if (word4[i] >= 'A' && word4[i] <= 'Z')
        word4[i] = word4[i]+32;
    ys['t'-'a'] = 't'-'a';
    ys['n'-'a'] = 'h'-'a';
    ys['y'-'a'] = 'i'-'a';
    ys['p'-'a'] = 's'-'a';
    ys['i'-'a'] = 'a'-'a';
    ys['d'-'a'] = 'j'-'a';
    while (true)
    {
        gets(commad);
        cout << "===================" << endl;
        for (int i = 0;i < 26;i++)
        if (ys[i] != 'A'-'a')
        {
            printf("%c %c\n",i+'a',ys[i]+'a');
        }
        printf("\n");
        cout << "===================" << endl;
        ys[commad[0]-'a'] = commad[2]-'a';
        for (int i = 0;i < strlen(word1);i++)
        {
            if (word1[i] >= 'a' && word1[i] <= 'z')
            {
                if (ys[word1[i]-'a'] == 'A'-'a')
                    printf("%c",word1[i]-'a'+'A');
                else
                printf("%c",ys[word1[i]-'a']+'a');
            }
            else
                printf("%c",word1[i]);
        }
        printf("\n\n\n");
        for (int i = 0;i < strlen(word2);i++)
        {
            if (word2[i] >= 'a' && word2[i] <= 'z')
            {
                if (ys[word2[i]-'a'] == 'A'-'a')
                    printf("%c",word2[i]-'a'+'A');
                else
                printf("%c",ys[word2[i]-'a']+'a');
            }
            else
                printf("%c",word2[i]);
        }
        printf("\n\n\n");
        for (int i = 0;i < strlen(word3);i++)
        {
            if (word3[i] >= 'a' && word3[i] <= 'z')
            {
                if (ys[word3[i]-'a'] == 'A'-'a')
                    printf("%c",word3[i]-'a'+'A');
                else
                printf("%c",ys[word3[i]-'a']+'a');
            }
            else
                printf("%c",word3[i]);
        }
        printf("\n\n\n");
        for (int i = 0;i < strlen(word4);i++)
        {
            if (word4[i] >= 'a' && word4[i] <= 'z')
            {
                if (ys[word4[i]-'a'] == 'A'-'a')
                    printf("%c",word4[i]-'a'+'A');
                else
                printf("%c",ys[word4[i]-'a']+'a');
            }
            else
                printf("%c",word4[i]);
        }
        printf("\n\n\n");
    }
}
