#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Player
{
    int times,id;
    Player() {}
    Player(int _times,int _id)
    {
        times=_times;
        id=_id;
    }
    bool operator<(const Player &a) const
    {
        return times>a.times;
    }
};
class Game
{
    int number,index,sum;
    Player friends[100];
    vector<int> games[100];
    void out(int x)
    {
        for (int i=0; i<games[x].size(); i++)
            printf("%d %d\n",1+friends[x].id,1+friends[games[x][i]].id);
    }
public:
    void init();
    void solve();
};
void Game::init()
{
    scanf("%d",&number);
    for (int i=0; i<number; i++)
        games[i].clear();
    sum=0;
    for (int i=0; i<number; i++)
    {
        int x;
        scanf("%d",&x);
        friends[i]=Player(x,i);
        sum+=x;
    }
    sum/=2;
    sort(friends,friends+number);
    for (int i=0,tot=0; i<number; i++)
    {
        tot+=friends[i].times;
        if (tot>=sum+i)
        {
            index=i;
            break;
        }
    }
    if (!index)
        return ;
    friends[0].times--;
    friends[index].times--;
    for (int i=1; i<index; i++)
        friends[i].times-=2;
}
void Game::solve()
{
    printf("%d\n",sum);
    for (int i=number-1; i; i--)
        while (friends[i].times--)
        {
            int maxi=index;
            for (int j=0; j<index; j++)
                if (friends[j].times>friends[maxi].times)
                    maxi=j;
            friends[maxi].times--;
            games[maxi].push_back(i);
        }
    out(0);
    for (int i=0; i<index; i++)
    {
        printf("%d %d\n",1+friends[i+1].id,1+friends[i].id);
        out(i+1);
    }
}
int main()
{
    Game game;
    game.init();
    game.solve();
}
