const
        maxn = 1000;
var
        n,k,i,j,tmax,imax,tot,x,y:longint;
        m:array[1..maxn,0..maxn] of longint;
        f:array[1..maxn] of longint;
        t1,t2:double;
procedure       del(root:longint);
var
        i,j:longint;
begin
        for i :=
end;
procedure       findmax;
begin
end;
begin
        readln(n,k);
        fillchar(f,sizeof(f),0);
        tmax := 0;
        imax := 0;
        for i := 1 to n do
        begin
                read(x);
                if x > 0 then
                begin
                        for j := 1 to x do
                        begin
                                read(y);
                                inc(m[y,0]);
                                m[y,m[y,0]] := i;
                                inc(f[y]);
                                if f[y] > tmax then
                                begin
                                        tmax := f[y];
                                        imax := y;
                                end;
                        end;
                end;
                readln;
        end;
        tot := 0;
        while k > 0 do
        begin
                del(imax);
                findmax;
                dec(k);
        end;
        writeln(tot);
end.