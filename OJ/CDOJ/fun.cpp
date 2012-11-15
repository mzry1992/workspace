#include<stdio.h>
#include<string>
#include<iostream>
#include<set>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        set <string> m;
        string s;
        cin>>s;
        m.insert(s);
        for (int i=1;i<s.size();i++)
        {
            string s1=s.substr(0,i);
            string s2=s.substr(i,s.size());
            cout<<s1<<endl;
            cout<<s2<<endl;
            if (m.find(s1+s2)==m.end())
                m.insert(s1+s2);
            if (m.find(s2+s1)==m.end())
                m.insert(s2+s1);
            s1.();
        }
        cout<<m.size()<<endl;
    }
}
