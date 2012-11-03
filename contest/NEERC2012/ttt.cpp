/*任意步长(p,q)无限棋盘可达性判定*/
bool check(int dx,int dy,int p,int q)
{
    if (p < 0) p = -p;
    if (q < 0) q = -q;
    LL g = gcd(p,q);
    if (dx % g || dy % g) return false;
    dx /= g,dy /= g,p = (p / g) & 1,q = (q / g) & 1;
    return !(p == q && ((dx ^ dy) & 1));
}
/*拓展:
若可选马步可以有 N 种(pi,qi),令 g = gcd(p1,q1,p2,q2...pN,qN),则不在 g 的整
        数倍点上的节点肯定不可达。坐标除 2g,同时将可选马步除 g 之后放缩到 2×2 之
        内,
        即(pi / g % 2,gi / g % 2)。
        若放缩后马步中有(1,0)或(0,1),
        则全放缩后全棋盘可达,
        否则只可达偶点。*/
/*(2,1)马步无限棋盘最小距离*/
int dis(int dx,int dy)
{
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (dx < dy) swap(dx,dy);
    if (dx & 1)
    {
        if (dy & 1) return dis(dx+1,dy-1);
        if (dx == 1 && dy == 0) return 3;
        return dis(dx+3,dy)-1;
    }
    if (dy & 1)
    {
        if (dx == 4 && dy == 3) return 3;
        return dis(dx-2,dy-1)+1;
    }
    if (dx == 0 && dy == 0) return 0;
    if (dx == 2 && dy == 2) return 4;
    int c = (((dx-1) / 4)+1)*2;
    if (dx & 2) dy -= 2;
    if (dy <= c) return c;
    dy -= c;
    return c+(dy-2) / 6*2+2;
}


