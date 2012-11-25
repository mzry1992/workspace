#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[600];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        if (n%2 == 0)
            puts("possible");
        else
        {
            int cnt = 0;
            for (int i = 0;i < n;i++)
                for (int j = i+1;j < n;j++)
                    if (a[i] > a[j])
                        cnt++;
            if (cnt%2 == 1)
                puts("impossible");
            else
                puts("possible");
        }
	}
	return 0;
}
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int n,a[600];
//
//int main()
//{
//	int totcas;
//	scanf("%d",&totcas);
//	for (int cas = 1;cas <= totcas;cas++)
//	{
//	    scanf("%d",&n);
//	    for (int i = 0;i < n;i++)
//            scanf("%d",&a[i]);
//        if (n%2 == 0)
//            puts("possible");
//        else
//        {
//            int cnt = 0;
//            for (int i = 0;i < n;i++)
//                for (int j = i+1;j < n;j++)
//                    if (a[i] > a[j])
//                        cnt++;
//            if (cnt%2 == 1)
//                puts("impossible");
//            else
//                puts("possible");
//        }
//	}
//	return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int n,a[600];
//
//int main()
//{
//	int totcas;
//	scanf("%d",&totcas);
//	for (int cas = 1;cas <= totcas;cas++)
//	{
//	    scanf("%d",&n);
//	    for (int i = 0;i < n;i++)
//            scanf("%d",&a[i]);
//        if (n%2 == 0)
//            puts("possible");
//        else
//        {
//            int cnt = 0;
//            for (int i = 0;i < n;i++)
//                for (int j = i+1;j < n;j++)
//                    if (a[i] > a[j])
//                        cnt++;
//            if (cnt%2 == 1)
//                puts("impossible");
//            else
//                puts("possible");
//        }
//	}
//	return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int n,a[600];
//
//int main()
//{
//	int totcas;
//	scanf("%d",&totcas);
//	for (int cas = 1;cas <= totcas;cas++)
//	{
//	    scanf("%d",&n);
//	    for (int i = 0;i < n;i++)
//            scanf("%d",&a[i]);
//        if (n%2 == 0)
//            puts("possible");
//        else
//        {
//            int cnt = 0;
//            for (int i = 0;i < n;i++)
//                for (int j = i+1;j < n;j++)
//                    if (a[i] > a[j])
//                        cnt++;
//            if (cnt%2 == 1)
//                puts("impossible");
//            else
//                puts("possible");
//        }
//	}
//	return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int n,a[600];
//
//int main()
//{
//	int totcas;
//	scanf("%d",&totcas);
//	for (int cas = 1;cas <= totcas;cas++)
//	{
//	    scanf("%d",&n);
//	    for (int i = 0;i < n;i++)
//            scanf("%d",&a[i]);
//        if (n%2 == 0)
//            puts("possible");
//        else
//        {
//            int cnt = 0;
//            for (int i = 0;i < n;i++)
//                for (int j = i+1;j < n;j++)
//                    if (a[i] > a[j])
//                        cnt++;
//            if (cnt%2 == 1)
//                puts("impossible");
//            else
//                puts("possible");
//        }
//	}
//	return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int n,a[600];
//
//int main()
//{
//	int totcas;
//	scanf("%d",&totcas);
//	for (int cas = 1;cas <= totcas;cas++)
//	{
//	    scanf("%d",&n);
//	    for (int i = 0;i e");
//        else
//        {
//            int cnt = 0;
//            for (int i = 0;i < n;i++)
//                for (int j = i+1;j < n;j++)
//                    if (a[i] > a[j])
//                        cnt++;
//            if (cnt%2 == 1)
//                puts("impossible");
//            else
//                puts("possible");
//        }
//	}
//	return 0;
//}
//< n;i++)
//            scanf("%d",&a[i]);
//        if (n%2 == 0)
//            puts("possible");
//        else
//        {
//            int cnt = 0;
//            for (int i = 0;i < n;i++)
//                for (int j = i+1;j < n;j++)
//                    if (a[i] > a[j])
//                        cnt++;
//            if (cnt%2 == 1)
//                puts("impossible");
//            else
//                puts("possible");
//        }
//	}
//	return 0;
//}
