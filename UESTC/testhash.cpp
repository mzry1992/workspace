#include <ext/hash_map>
#include <cstdio>
using namespace __gnu_cxx;

struct longlong_hash
{
    size_t operator()(const long long& a) const
    {
        return a%19921005;
    }
};

int main()
{
    printf("%d %d\n",sizeof(size_t),sizeof(long long));
    hash_map<long long, long long, longlong_hash> hmap;
    return 0;
}
