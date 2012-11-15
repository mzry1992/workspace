#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("t.txt","r",stdin);
    freopen("outout.cpp","w",stdout);
    cout << "#include<iostream>" << endl;
    cout << "#include<cstdio>" << endl;
    cout << "using namespace std;" << endl;
    cout << "int aa[50][50];" << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    int a,b,c;
    while (scanf("%d%d%d",&a,&b,&c) != EOF)
        cout << "aa[" << a << "][" << b << "] = " << c << ";" << endl;
    cout << "int n,m;" << endl;
    cout << "bool first = true;" << endl;
    cout << "while (scanf(\"%d%d\",&n,&m) != EOF)" << endl;
    cout << "{" << endl;
    cout << "if (!first)" << endl;
    cout << "printf(\"\\n\");" << endl;
    cout << "first = false;" << endl;
    cout << "printf(\"%d\\n\",aa[n][m]);" << endl;
    cout << "}" << endl;
    cout << "}" << endl;
}
