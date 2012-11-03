#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-10;

struct Point3D
{
    double x,y,z;
    Point3D() {}
    Point3D(double _x,double _y,double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    Point3D operator -(const Point3D& b)const
    {
        return Point3D(x-b.x,y-b.y,z-b.z);
    }
    Point3D operator *(const Point3D& b)const
    {
        return Point3D(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
    double operator &(const Point3D& b)const
    {
        return x*b.x+y*b.y+z*b.z;
    }
};
struct Line3D
{
    Point3D s,e;
    Line3D() {}
    Line3D(Point3D _s,Point3D _e)
    {
        s = _s;
        e = _e;
    }
};

double Norm(Point3D p)
{
    return sqrt(p&p);
}
double Inclination(Line3D L1,Line3D L2)
{
    Point3D u = L1.e-L1.s;
    Point3D v = L2.e-L2.s;
    double res = ((u&v)/(Norm(u)*Norm(v)));
    if (res > 1-eps)
		res = 1.0;
	if (res < -1+eps)
		res = -1.0;
	return acos(res);
}

//lat1 (-π/2 < lat1 < π/2), lng1 (-π < lng1 < π).
Point3D getPoint3D(double lat,double lng,double r)
{
    lat += pi/2;
    lng += pi;
    return Point3D(r*sin(lat)*cos(lng),r*sin(lat)*sin(lng),r*cos(lat));
}

double r,h,lat0,lng0,lat1,lng1;
Point3D pa,pb,V;
double ry;

double calc(double theta)
{
    double s = sin(theta);
    double c = cos(theta);
    double x,y,z;
    x = V.x;
    y = V.y;
    z = V.z;
    Point3D pp = Point3D((x*x*(1-c)+c)*pa.x+(x*y*(1-c)-z*s)*pa.y+(x*z*(1-c)+y*s)*pa.z,
                         (y*x*(1-c)+z*s)*pa.x+(y*y*(1-c)+c)*pa.y+(y*z*(1-c)-x*s)*pa.z,
                         (x*z*(1-c)-y*s)*pa.x+(y*z*(1-c)+x*s)*pa.y+(z*z*(1-c)+c)*pa.z);

//	printf("theta = %.3f, pp = (%.3f %.3f %3f)\n",theta,pp.x,pp.y,pp.z);
//	printf("%.3f\n",Norm(pp));

    return pp.z;
}

double gao(double l,double r)
{
    double mid;
    for (int tim = 0; tim < 200; tim++)
    {
        mid = (l+r)/2;
        if (calc(mid) > ry)
            l = mid;
        else
            r = mid;
    }
    return l;
}

double gao2(double l,double r)
{
    double mid;
    for (int tim = 0; tim < 200; tim++)
    {
        mid = (l+r)/2;
        if (calc(mid) > ry)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf",&r,&h,&lat0,&lng0,&lat1,&lng1) != EOF)
    {
        pa = getPoint3D(lat0,lng0,r+h);
        pb = getPoint3D(lat1,lng1,r+h);

        V = pa*pb;
        double nV = Norm(V);
        V = Point3D(V.x/nV,V.y/nV,V.z/nV);

        double theta = Inclination(Line3D(Point3D(0,0,0),pa),Line3D(Point3D(0,0,0),pb));

//		printf("pa = (%.3f %.3f %.3f)\n",pa.x,pa.y,pa.z);
//		printf("pb = (%.3f %.3f %.3f)\n",pb.x,pb.y,pb.z);

        ry = -sqrt((r+h)*(r+h)-r*r);
        double sl,sr,smid1,smid2;
        sl = 0;
        sr = theta;
        for (int tim = 0; tim <= 200; tim++)
        {
            smid1 = sl+(sr-sl)/3.0;
            smid2 = sl+2.0*(sr-sl)/3.0;

            if (calc(smid1) < calc(smid2))
                sl = smid1;
            else
                sr = smid2;
        }

        double maxpos = sl;

        sl = 0;
        sr = theta;
        for (int tim = 0; tim <= 200; tim++)
        {
            smid1 = sl+(sr-sl)/3.0;
            smid2 = sl+2.0*(sr-sl)/3.0;

            if (calc(smid1) > calc(smid2))
                sl = smid1;
            else
                sr = smid2;
        }
        double minpos = sl;
        double posa,posb;

        double res;
        if (fabs(lat0) < eps && fabs(lat1) < eps)
        {
            res = 1.0;
        }
        else
        {
            if (fabs(minpos) > eps && fabs(minpos-theta) > eps)
            {
                posa = gao(0,minpos);
                posb = gao2(minpos,theta);

                res = (posa+theta-posb)/theta;
            }
            else if (fabs(maxpos) > eps && fabs(maxpos-theta) > eps)
            {
//            	cout << "fuck" << endl;
                posa = gao2(0,maxpos);
                posb = gao(maxpos,theta);
//                printf("posa = %.3f, posb = %.3f, maxpos = %.3f\n",posa,posb,maxpos);
                res = (posb-posa)/theta;
            }
            else
            {
                posa = gao(0,theta);

                if (calc(0) < ry)
                {
                	posa = gao2(0,theta);
                    res = (theta-posa)/theta;
                }
                else
                {
                	posa = gao(0,theta);
                    res = posa/theta;
                }
            }
        }
//		printf("%.3f\n",ry);
//		printf("min = %.3f, max = %.3f\n",calc(minpos),calc(maxpos));
//		printf("a = %.3f, b = %.3f\n",calc(posa),calc(posb));
//		printf("theta = %.3f\n",theta);

        printf("%.3f\n",fabs(100.0*res));
    }
    return 0;
}

