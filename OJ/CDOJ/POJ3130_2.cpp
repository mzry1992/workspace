/**
 * ��άACM���㼸��ģ��
 * ע��������͸��ĺ�EPS
 * #include <cmath>
 * #include <cstdio>
 * By OWenT
 */

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const double eps = 1e-8;
const double pi = std::acos(-1.0);
//��
class point
{
public:
    double x, y;
    point(){};
    point(double x, double y):x(x),y(y){};

    static int xmult(const point &ps, const point &pe, const point &po)
    {
        return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
    }
};

//�����ʾ������
class pVector
{
public:
    point s, e;//�����ʾ�����[s]���յ�[e]

    pVector(){}
    pVector(const point &s, const point &e):s(s),e(e){}

    //�����������Ĳ��,����������[_Off]
    double operator *(const pVector &_Off) const
    {
        return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
    }

    //ֱ��ƽ�У�������ֱ������[_Off]
    bool parallel(const pVector &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }

    //��ֱ�߽��㣬������Ŀ��ֱ��[_Off]
    point crossLPt(pVector _Off)
    {
        //ע�����ж�ƽ�к��غ�
        point ret = s;
        double t = ((s.x - _Off.s.x) * (_Off.s.y - _Off.e.y) - (s.y - _Off.s.y) * (_Off.s.x - _Off.e.x))
                / ((s.x - e.x) * (_Off.s.y - _Off.e.y) - (s.y - e.y) * (_Off.s.x - _Off.e.x));
        ret.x += (e.x - s.x) * t;
        ret.y += (e.y - s.y) * t;
        return ret;
    }
};

class polygon
{
public:
    const static long maxpn = 2000;
    point pt[maxpn];//�㣨˳ʱ�����ʱ�룩
    long n;//��ĸ���

    //-----------��ƽ�潻-------------
    //���Ӷ�:O(nlog2(n))
    //#include <algorithm>
    //��ƽ����㼫�Ǻ���[�������Ч�ʿ����ó�Ա������¼]
    static double hpc_pa(const pVector &_Off)
    {
        return atan2(_Off.e.y - _Off.s.y, _Off.e.x - _Off.s.x);
    }
    //��ƽ�潻������[����˳��: 1.���� 2.ǰ���ֱ���ں�������]
    static bool hpc_cmp(const pVector &l, const pVector &r)
    {
        double lp = hpc_pa(l), rp = hpc_pa(r);
        if(fabs(lp - rp) > eps)
            return lp < rp;
        return point::xmult(l.s, r.e, r.s) < 0.0;
    }
    //���ڼ����˫�˶���
    pVector dequeue[maxpn];
    //��ȡ��ƽ�潻�Ķ����
    //��������������[l]����������[ln];(��ƽ�淽����������ߣ�
    polygon& halfPanelCross(pVector _Off[], int ln)
    {
        int i, tn;
        n = 0;
        std::sort(_Off, _Off + ln, hpc_cmp);
        //ƽ����������ߵ�ɸѡ
        for(i = tn = 1; i < ln; i ++)

            if(fabs(hpc_pa(_Off[i]) - hpc_pa(_Off[i - 1])) > eps)
                _Off[tn ++] = _Off[i];
        ln = tn;
        //cout << "Line" << endl;
        //for (int i = 0;i < ln;i++)
        //    cout << hpc_pa(_Off[i]) << ' ' << _Off[i].s.x << ' ' << _Off[i].s.y << ' ' << _Off[i].e.x << ' ' << _Off[i].e.y << endl;
        int bot = 0, top = 1;
        dequeue[0] = _Off[0];
        dequeue[1] = _Off[1];
        for(i = 2; i < ln; i ++)
        {
            cout << i << ' ' << bot << ' ' << top << endl;
            for (int ii = bot;ii <= top;ii++)
                cout << dequeue[ii].s.x << ' ' << dequeue[ii].s.y << ' ' << dequeue[ii].e.x << ' ' << dequeue[ii].e.y << endl;
            if(dequeue[top].parallel(dequeue[top - 1]) ||
                dequeue[bot].parallel(dequeue[bot + 1]))
                return (*this);
            while(bot < top &&
                point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), _Off[i].e, _Off[i].s) > eps)
                top --;
            while(bot < top &&
                point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), _Off[i].e, _Off[i].s) > eps)
                bot ++;
            dequeue[++ top] = _Off[i];
        }

        while(bot < top &&
            point::xmult(dequeue[top].crossLPt(dequeue[top - 1]), dequeue[bot].e, dequeue[bot].s) > eps)
            top --;
        while(bot < top &&
            point::xmult(dequeue[bot].crossLPt(dequeue[bot + 1]), dequeue[top].e, dequeue[top].s) > eps)
            bot ++;
        //���㽻��(ע�ⲻֱͬ���γɵĽ�������غ�)
        cout << "Q" << endl;
        for (i = bot;i <= top;i++)
            cout << dequeue[i].s.x << ' ' << dequeue[i].s.y << ' ' << dequeue[i].e.x << ' ' << dequeue[i].e.y << endl;
        if(top <= bot + 1)
            return (*this);
        for(i = bot; i < top; i ++)
            pt[n ++] = dequeue[i].crossLPt(dequeue[i + 1]);
        if(bot < top + 1)
            pt[n ++] = dequeue[bot].crossLPt(dequeue[top]);
        return (*this);
    }
};

pVector line[polygon::maxpn];
point pt[polygon::maxpn];
polygon ans;

int main()
{
    int n, i;
    int t = 1;
    //freopen("d:\\in.txt", "r", stdin);
    //freopen("d:\\myout.txt", "w", stdout);
    while(::scanf("%d", &n), n)
    {
        for(i = n-1; i >= 0; i --)
            ::scanf("%lf %lf", &pt[i].x, &pt[i].y);
        for(i = 0; i < n; i ++)
            line[i] = pVector(pt[(i + 1) % n], pt[i]);

        ans.halfPanelCross(line, n);
        if(ans.n > 0)
            ::printf("1\n");
        else
            ::printf("0\n");
    }
    return 0;
}
