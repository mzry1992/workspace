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

class CheckerFreeness {
public:
	string isFree(vector <string>, vector <string>, vector <string>, vector <string>);
};

vector<long long> Gao(vector<string> x)
{
    vector<long long> ans;
    long long tmp;
    stringstream sin;
    for (int i = 0;i < x.size();i++)
        sin << x[i];
    while (sin >> tmp)
        ans.push_back(tmp);
    return ans;
}

struct Point
{
    long long x,y;
    int typ;
    int id;
    Point(){}
    Point(long long _x,long long _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    long long operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};
Point p[500],tp[1000],base;
//n0 : 需要计数的点的个数
int n0,n1,n,m;
//cnt[i][j] : 取i为中心，从x负半轴到向量ij的区域内点的个数，不包括j点。
//cntleft[i][j] : 向量ij的左手方向有多少个点
int cnt[500][500],cntleft[500][500];
//预处理p[j]-p[i]。。加速很明显。。
Point pv[500][500];

bool cmp(const Point& a,const Point &b)
{
    //使用叉积极角排序，没考虑共线的情况
    if (a.y*b.y <= 0)
    {
        if (a.y > 0 || b.y > 0) return a.y < b.y;
        if (a.y == 0 && b.y == 0)   return a.x < b.x;
    }
    return a*b > 0;
}

//射线ab和ac之间的点数，不包括a,b,c这三个点
int calc1(int a,int b,int c)
{
    if (cmp(pv[a][b],pv[a][c]) == false)
        swap(b,c);
    int res = cnt[a][c]-cnt[a][b]-p[b].typ;
    if (pv[a][b]*pv[a][c] < 0)
        res = n0-p[a].typ-p[b].typ-p[c].typ-res;

    return res;
}

//三角形x,y,z内的点数，不包括x,y,z三点
int calc2(int x,int y,int z)
{
    if (pv[x][z]*pv[x][y] > 0)
        swap(y,z);
    int res = cntleft[x][z]+cntleft[z][y]+cntleft[y][x];
    res += calc1(x,y,z)+calc1(y,z,x)+calc1(z,x,y);
    res -= 2*(n0-p[x].typ-p[y].typ-p[z].typ);
    return res;
}

string CheckerFreeness::isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
    vector<long long> wx = Gao(whiteX);
    vector<long long> wy = Gao(whiteY);
    vector<long long> bx = Gao(blackX);
    vector<long long> by = Gao(blackY);

    n0 = wx.size();
    n1 = bx.size();
    n = n0+n1;
    for (int i = 0;i < n0;i++)
    {
        p[i] = Point(wx[i],wy[i]);
        p[i].typ = 1;//需要计数的点
    }
    for (int i = 0;i < n1;i++)
    {
        p[n0+i] = Point(bx[i],by[i]);
        p[n0+i].typ = 0;
    }

    for (int i = 0;i < n;i++)
    {
        m = 0;
        base = p[i];
        for (int j = 0;j < n;j++)
            if (i != j)
            {
                pv[i][j] = tp[m] = p[j]-base;
                tp[m].id = j;
                tp[m++].typ = p[j].typ;
            }

        sort(tp,tp+m,cmp);
        for (int j = 0;j < m;j++)
            tp[m+j] = tp[j];

        for (int j = 0,tot = 0;j < m;j++)
        {
            cnt[i][tp[j].id] = tot;
            tot += tp[j].typ;
        }

        for (int j = 0,k = 0,tot = 0;j < m;j++)
        {
            while (k == j || (k < j+m && tp[j]*tp[k] > 0))
                tot += tp[k++].typ;
            tot -= tp[j].typ;
            cntleft[i][tp[j].id] = tot;
        }
    }

    for (int i = 0;i < n0;i++)
        for (int j = n0;j < n;j++)
            for (int k = j+1;k < n;k++)
            {
                if (calc1(i,j,k)-calc2(i,j,k) > 0)
                {
                    return "NO";
                }
            }
    return "YES";
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"1 2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"2 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1 2"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"1 2"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	CheckerFreeness * obj = new CheckerFreeness();
	clock_t start = clock();
	string my_answer = obj->isFree(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"2", "5", "3", " ", "1", "7", "3"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"180 254"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"32", "5 1", "42"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"462 423"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	CheckerFreeness * obj = new CheckerFreeness();
	clock_t start = clock();
	string my_answer = obj->isFree(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"1 10000000 9999999"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"1 9999999 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 5000000 9999998"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"2 5000001 9999999"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	CheckerFreeness * obj = new CheckerFreeness();
	clock_t start = clock();
	string my_answer = obj->isFree(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"2"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"4"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	CheckerFreeness * obj = new CheckerFreeness();
	clock_t start = clock();
	string my_answer = obj->isFree(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
,"93 5922 714 2258 4369 9524 302 8417 6620 1143"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	CheckerFreeness * obj = new CheckerFreeness();
	clock_t start = clock();
	string my_answer = obj->isFree(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"3539553 8372753 2114662 3461196 6595374 3187001 29", "38256 360443 3247691 2404838 6500539 7070816 20757", "06 7373859 2851481 7441690 4068511 5192344 6003561", " 8812453 2509899 4232411 7539381 7459090 1367068 6", "426770 3665067 3623682 8403933 5573794 5719894 481", "7499 7430907 3908090 6577112 2669198 456770 226842", "7 850109 5622379 891203 2243050 6925687 7585301 22", "98431 1399237 3754778 2735655 1289551 1663819 6717", "473 513359 5085299 8224763 7951414 5385026 6584543", " 6693703 4307413 4776302 4796285 3932856 9928364 2", "378237 5727586 7226207 4599064 590378 7037567 2434", "714 2262609 4533902 4462304 412767 189748 5896326 ", "1744170 449979 4846792 9729347 2807165 1189040 941", "735 4101524 1502438 3450095 174915 4409397 2206617", " 5618394 2460323 4901206 3745398 722482 2773339 24", "65348 4206157 6255259 1226942 6226110 6347527 1438", "731 6400078 7331835 2458121 4704536 4331391 359914", "4 4468423 4559132 6260013 2003395 5964372 4143287 ", "6466944 1169213 9675427 7655533 2904067 3311092 42", "93675 6896545 3574437 9021921 3974050 768509 88086", "45 5180163 7137476 491483 1489598 3113759 7133383 ", "3179296 3198538 5981503 4094736 2172029 954159 341", "5245 38932 3408252 2697581 1170806 5765162 8869313", " 5298772 8576354 3536241 3900126 6184183 345486 66", "05644 3214030 2274277 2603908 6034746 269928 20121", "83 2964598 4976525 9751730 839472 475496 2554758 1", "632088 7461827 2233517 1617496 588686 4031038 1053", "479 6832431 552237 6334997 2912527 7253656 2335057", " 201530 1351184 2030514 2419146 38809 4605832 2457", "393 5037649 8625538 6536295 758462 726560 4564430 ", "2185271 1410676 4713484 4883596 3952870 5266581 86", "86687 2993953 7220540 850376 1768186 1210128 97818", "81 4616139 2131716 1966683 3392859 2097647 5479304", " 4771859 5292923 3223533 3023333 1217634 7483280 2", "678977 1205756 4399089 4172783 8020588 467837"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"5990483 9722469 5872907 7742990 7908483 4948719 78", "21283 3363257 7280153 6777939 7803152 7664301 9235", "662 6368470 6160837 9953197 8214394 9878445 591188", "2 7039925 6175684 6929026 7664293 8508845 6763465 ", "6065202 7882522 5000907 7759928 5924491 7867699 73", "92978 7212439 7124331 6536685 8407691 5812637 8344", "380 6101080 7098088 6458843 6424281 6909199 852033", "4 3645756 5067763 6490895 7850213 9081991 6922368 ", "8326534 7450414 6599038 9431851 9026981 9525782 70", "70189 8881639 7552108 7408089 6148539 6630386 8396", "348 8566281 6490297 8183330 8429935 5892281 882925", "3 4218540 3795571 9518885 6442634 6514695 6974471 ", "6668939 3791182 7517833 8097895 7785826 6650914 40", "99168 3398375 7905650 7052478 5155065 5207239 6685", "457 6904943 9038633 5330342 7133843 4565378 601561", "7 5193958 7435792 9656365 6330265 8964522 8513867 ", "6260069 7929358 7199413 7581472 4038519 5204451 70", "60383 9461652 6885618 6570886 6967734 5367985 8091", "955 6087752 9965000 5452082 8213496 7541054 704501", "3 5851073 6219725 9348535 9272670 7694464 5430404 ", "9492776 9464508 8149100 9298204 3095186 8200956 71", "94144 7970559 6114153 7455833 8526863 7222445 6772", "190 2963857 9265594 4766416 6423236 8236199 417664", "2 6248173 8780381 7818482 9276264 9674564 9582793 ", "9969050 3606524 6738316 7782492 5411105 5705717 66", "15472 3364637 5688934 9716131 7643372 9495780 8626", "308 9441015 5786526 4597225 9467244 9824893 519759", "4 4291287 5155549 8530867 9956276 6866273 7725275 ", "8160631 8222035 9312452 7028760 6050119 5858092 87", "42240 4211014 7596350 8381889 7469325 9605974 9842", "260 5004229 3253785 8991526 9242428 7283580 750422", "9 8752008 6891398 7212717 8007049 8369465 7919915 ", "6613475 4191009 7137247 9670655 7582226 8559260 75", "65077 4952969 3799704 7898003 7568255 9454432 7605", "930 8379900 3320285 7567225 3958688 4364809 708377", "4 5495615 6805728 8973190"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"9125494 2670534 7541571 2907441 8397845 4100920 71", "06205 7277135 5142116 9257313 5902142 8922927 4556", "820 9756767 9695353 5325599 6996639 9299621 376771", "8 3149414 2226103 7767564 5119839 4385415 2543636 ", "9655413 9148564 2598556 8813541 9365847 4006158 75", "41025 1175014 7806859 5677795 6972282 7827243 2662", "133 9417848 1202754 5880651 5495833 129716 8295356", " 9147530 3385212 7613602 8534016 3237331 7334968 5", "462459 5312132 5514965 6609325 7350595 8030542 673", "4376 5812482 9805842 6798407 4239554 8936535 72968", "63 7654491 801577 8197601 3902526 7548731 6307006 ", "3730140 8111010 3193762 9430407 2839472 9438354 44", "95288 3344210 1994657 3158980 8797914 5316060 4927", "023 5998341 9192496 8981160 5728832 7860750 356388", "7 7535755 6395925 9184954 5004660 840489 2785258 1", "757088 316461 4220598 7155500 2470372 208095 31988", "50 3934664 8767067 5632799 3513184 9783751 4913494", " 6341278 9405138 9623850 4818298 6528409 6900041 4", "434197 3327060 5028694 8024305 7439988 8432361 929", "3040 9973989 2816369 9798969 2313722 5952618 16076", "68 9335690 9797101 5769092 6574150 7642083 3752392", " 6376663 1612990 7733756 5331989 7289551 4663401 5", "355633 7535289 5200766 4025079 4875575 2284703 590", "9498 8007624 7983491 7415743 1765005 4848617 78037", "14 6165695 2593294 9291625 6175837 4037661 2706507", " 233858 1001230 8251653 5924453 1506068 7088277 92", "39045 4902579 9494739 96602 4770303 7853780 849517", "7 8283352 7985321 5679139 1611373 6722421 5771706 ", "2552127 632856 1419815 6516147 5756230 8521406 723", "2794 5273780 6390667 6968231 3677578 5527784 35505", "39 9203199 9894777 9595508 2826283 1682435 4801246", " 5655229 8074253 1467858 7420565 8918040 9280679 7", "520990 3325806 5598280 8466823 3537794 5491796 767", "5747 177097 2657200 660286 3278713 9153718 5011456", " 2639924 5910320 3818536 8541634 8620377 4428862 7", "613485 3213110"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	string t3[] = {"4938597 1921095 5639475 959621 616816 2186334 4937", "256 4854820 3360992 5594923 4524731 2348503 229032", " 803349 3577354 4464673 851364 5565058 3087224 117", "5820 3334822 105273 1917908 4616834 3246815 260560", "2 5759988 3310416 3213144 3181262 2646360 6073256 ", "2377999 4758582 2250176 2387150 3736913 454904 184", "3089 1717505 598174 1195560 614355 1501137 6088482", " 1772276 5617142 3124940 2125925 5192609 860130 35", "24759 2006870 2776378 4939803 1308985 3828405 2692", "876 1446204 1621782 2276314 178847 226126 5569852 ", "449908 165893 2686325 3648851 3590622 1026163 4940", "191 901232 2352518 3151184 1190580 1363663 2228633", " 1766929 355102 4567002 2574032 4779520 2442181 58", "18220 6990853 5292638 1624760 1998720 3245292 3634", "115 108518 3587755 2202109 3743415 2160010 42422 8", "48049 1927273 475988 1587116 1980238 1374364 37843", "52 4278342 3454819 1506376 752517 3770322 4463758 ", "3426925 4242582 1226506 949472 1903232 641650 2241", "124 2672541 2655825 2314311 5801740 406150 922671 ", "6074576 212082 1883658 1973078 2290153 4187023 127", "4397 2436185 3718792 483301 4003925 3145575 514148", "9 5117407 5292227 1248207 4960790 129608 1430306 2", "345710 1062171 3041806 4567207 5681582 5430672 338", "2814 2613876 2844788 4021243 3977170 151667 415000", "6 1236838 1652017 3623986 1886059 1186057 1721976 ", "4582485 2654634 23058 1565030 1394038 5197390 2174", "136 1214244 4481518 1109972 218930 4394074 2448099", " 853847 287402 709176 152671 1978752 688059 155388", " 3221531 2563281 4942450 1272815 197670 5784138 19", "47092 1005924 840093 6694745 3473718 304801 790125", " 1212480 147194 1706194 5649012 238535 3129065 524", "7713 2833697 5310457 1751653 2112178 3543774 23875", "73 3486515 4139140 357795 2889795 1461193 2997573 ", "2105008 3304944 3185115 827870 3625710 674821 2416", "792 4142334 4442180 3030884"};
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	CheckerFreeness * obj = new CheckerFreeness();
	clock_t start = clock();
	string my_answer = obj->isFree(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main() {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
