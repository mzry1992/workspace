#include<iostream>
using namespace std;
int temp[ 20 ];
int main()
{
    int i, n, min;
    while( cin >> n )
    {
        for( i = 0; i < n; i++ )
            cin >> temp[ i ];
        min = temp[ 0 ];
        for( i = 1; i < n ; i++ )
            min = min^temp[ i ];
        if( min == 0 )
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
