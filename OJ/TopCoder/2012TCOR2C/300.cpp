#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class GreedyTravelingSalesman
{
public:
    int worstDistance(vector <string>, vector <string>, vector <string>, vector <string>);
};

int dis[30][30],n;
vector<int > tdis;

int calc()
{
    int now = 0,use = 1,res = 0;
    for (int i = 1; i < n; i++)
    {
        int mindis = 10000,minid = n;
        for (int j = 0; j < n; j++)
            if (((use>>j)&1) == 0)
                if (dis[now][j] < mindis)
                {
                    mindis = dis[now][j];
                    minid = j;
                }
        use |= (1<<minid);
        res += dis[now][minid];
        now = minid;
    }
    return res;
}

int GreedyTravelingSalesman::worstDistance(vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones)
{
    n = thousands.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = 1000*(thousands[i][j]-'0');
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] += 100*(hundreds[i][j]-'0');
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] += 10*(tens[i][j]-'0');
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] += 1*(ones[i][j]-'0');
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        tdis.clear();
        for (int j = 0; j < n; j++)
            if (i != j)
                tdis.push_back(dis[i][j]);
        tdis.push_back(9999);
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                //for (int k = 0; k < tdis.size(); k++)
                //    for (int q = -1; q <= 0; q++)
                //        if (tdis[k]+q > 0)
                for (int k = 1;k < 10000;k++)
                        {
                            int tmp = dis[i][j];
                            dis[i][j] = k;//tdis[k]+q;
                            res = max(res,calc());
                            dis[i][j] = tmp;
                        }
            }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    string t0[] = {"055", "505", "550"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"000", "000", "000"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"000", "000", "000"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"000", "000", "000"};
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 14999;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    string t0[] = {"018", "101", "990"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"000", "000", "990"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"000", "000", "990"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"000", "000", "990"};
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 17999;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    string t0[] = {"00888", "00999", "00099", "00009", "00000"}
                  ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"00000", "00999", "00099", "00009", "00000"}
                  ;
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"00000", "10999", "11099", "11109", "11110"}
                  ;
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"01000", "00999", "00099", "00009", "00000"}
                  ;
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 37997;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    string t0[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"011111", "101111", "990998", "999099", "999809", "999980"};
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 39994;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4()
{
    string t0[] = {"09", "90"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"09", "90"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"09", "90"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"09", "90"};
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 9999;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5()
{
    string t0[] = {"0930", "1064", "0104", "1070"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"0523", "1062", "6305", "0810"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"0913", "0087", "3109", "1500"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"0988", "2030", "6103", "5530"};
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 14124;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test6()
{
    string t0[] = {"0329", "2036", "2502", "8970"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"0860", "5007", "0404", "2770"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"0111", "2087", "2009", "2670"};
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"0644", "1094", "7703", "7550"};
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 17785;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test7()
{
    string t0[] = {"098444156277392825243100607342", "200097656837707947798866622385",
                   "290231695687128834848596019656", "407026565077650435591867333275",
                   "843401002617957470339040852874", "349970591997218853400632158696",
                   "419933000593511123878416328483", "696294503254214847884399055978",
                   "641473980706392541888675375279", "936720077098054565078142449625",
                   "203476089500970673371115103717", "511071853860312304204656816567",
                   "347105714685052402147763392257", "125122220860203856679947732062",
                   "121462979669220132944063071653", "928254504048223043681383050365",
                   "502607124708785202536036594373", "793596587517012870906900400361",
                   "712360060935346182084840996318", "761671392040312345002273366240",
                   "812935320276738878200716148806", "228506917464479046839069740872",
                   "755395721473881083093906155745", "192597782177910118061710039501",
                   "721382839206745793530453013267", "076061794267810491768114700256",
                   "857528357758085424372388710251", "173322450800442594145600093043",
                   "761667192345925280210514410800", "521229810525064090301842864060"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"098270581534726237580246464451", "108829763716747148395013332067",
                   "830061279541380758964430491222", "431005058477371114834129826284",
                   "601807314489142917339949914290", "330640126699733151822328009407",
                   "851821069798846354566780680271", "648888407535627630663351884365",
                   "051398660825518466890170447894", "631934884097214069747147155777",
                   "768071219404930950472885304916", "924954163330715847561718395488",
                   "189910033179029204426829479070", "960645776060701332402794474433",
                   "244875842263950931884758650019", "528470075229660077692189442311",
                   "752198673046476808978058423064", "899325998610605600525587569431",
                   "965750123741820904031880230236", "121658852172052167706008445728",
                   "556199378085507717770434101126", "864838242791403197110088834005",
                   "593435343245223500439707230479", "622529771475840345624500421425",
                   "503486612623475041392122088159", "518334626169655694269507400008",
                   "967091631529233593414345370288", "300474162107271438029222620086",
                   "010527691044447729596127150108", "742822904991333205419603623270"
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    string t2[] = {"029421809872798033258029765788", "705135039569772524273274786652",
                   "170567418260893393020344098265", "401043354947659563658581268242",
                   "746709065616595245635350557925", "739570024549618413776557843034",
                   "184597012262496958610853505745", "689811400727818703807051112784",
                   "894453010121164288965541305235", "323145029073008946088869964941",
                   "834269564400729646453274750586", "538976762970745472202055589093",
                   "765511399939087047106252621388", "906733295711605356366138410423",
                   "107653940551700559321642810836", "428402693021051075533830345295",
                   "386782660475155103347385287948", "936626025836194580089064628716",
                   "718522629491464055045890912121", "370656945845300237607868352243",
                   "951908186614186444840337711498", "535178875249889835014025850038",
                   "505970047705717604298603983975", "484398304612602344941130624527",
                   "048342694079170795987835013947", "860331019262176299872846206272",
                   "549663926438975145562538360932", "329735455392841851511474791078",
                   "711755200061373546828858448100", "778808866574640894148527759780"
                  };
    vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
    string t3[] = {"050738147930236727719964251439", "804492562859282318664226330103",
                   "610197568193830684654773608216", "279000416545607314567843085541",
                   "782201171759873927350740022455", "043370803444176631019883186675",
                   "566092086050401228622782761449", "469598907881602996036692882305",
                   "116923500417992303845370254124", "796876115092839169954790509461",
                   "783836410405270687557924090071", "095144151150833738671751747749",
                   "354474585664039135189964700948", "328968176148004939648962631420",
                   "829651915384290848347221555092", "170980383407813034573738951375",
                   "728655435703349509419725538350", "121896684176286430427852435647",
                   "315710894574884960021671476788", "592177839598531202003634382961",
                   "876587919610157913350259498196", "505517243779897451333006271744",
                   "618607877753891664471800511372", "826358757330233811836040764274",
                   "206641252044293046424432092833", "704519364781672964993499009545",
                   "624793571592392775564426440338", "571938479010503551295729304078",
                   "077967252884369103891335711508", "870185204806328841827105139840"
                  };
    vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
    GreedyTravelingSalesman * obj = new GreedyTravelingSalesman();
    clock_t start = clock();
    int my_answer = obj->worstDistance(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 39896;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main()
{
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    time = test6();
    if (time < 0)
        errors = true;

    time = test7();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
