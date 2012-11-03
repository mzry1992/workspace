#include <iostream>
#include <queue>

struct heapmin
{
       int x;
       bool operator < (const struct heapmin &temp) const
       {
            return x > temp.x;
       }
}

int main()
{
    return 0;
}
