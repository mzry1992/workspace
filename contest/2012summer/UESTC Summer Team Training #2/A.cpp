#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
char s1[5],s2[10],s[20];
map<string,int> mp;
char word[20][5]={"A","A#","Bb","B","C","C#","Db","D","D#","Eb","E","F","F#","Gb","G","G#","Ab"};
int main()
{
    mp.clear();
    mp["A"]=1;
    mp["A#"]=mp["Bb"]=2;
    mp["B"]=3;
    mp["C"]=4;
    mp["C#"]=mp["Db"]=5;
    mp["D"]=6;
    mp["D#"]=mp["Eb"]=7;
    mp["E"]=8;
    mp["F"]=9;
    mp["F#"]=mp["Gb"]=10;
    mp["G"]=11;
    mp["G#"]=mp["Ab"]=12;

  //  mp["Ab minor"]=mp["A# major"]=mp["A# minor"]=mp["C# major"]=mp["Db minor"]=1;
  //  mp["D# major"]=mp["D# minor"]=mp["Gb major"]=mp["Gb minor"]=mp["G# major"]=1;
	int cas=1;
	while(scanf("%s",s1)!=EOF)
	{
	    memset(s2,0,sizeof(s2));
	    memset(s,0,sizeof(s));
        scanf("%s",s2);
        int i;
        bool flag=false;
        for(i=0;i<17;i++)
            if(strcmp(word[i],s1)!=0&&mp[word[i]]==mp[s1])
            {
                flag=true;
                strcpy(s,word[i]);
                strcat(s," ");
                strcat(s,s2);
                printf("Case %d: %s\n",cas++,s);
            }
        if(!flag)
            printf("Case %d: UNIQUE\n",cas++);
        memset(s1,0,sizeof(s1));
	}
	return 0;
}
