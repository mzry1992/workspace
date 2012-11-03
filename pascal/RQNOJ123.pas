const
        maxk = 50;
        maxv = 5000;
        maxn = 200;
var
        f:array[0..maxv,0..maxk] of longint;
        wi,vi:array[1..maxn] of longint;
        k,v,n,i,j,x,p1,p2,p3:longint;
        t1,t2,t3:array[0..maxk] of longint;
begin
        readln(k,v,n);
        for i := 1 to n do      readln(wi[i],vi[i]);
        fillchar(f,sizeof(f),0);
        f[0,0] := 1;
        for i := 1 to n do
        for j := v downto wi[i] do
        if f[j-wi[i],0] <> 0 then
        begin
                t1 := f[j];
                t2 := f[j-wi[i]];
                for x := 1 to t2[0] do
                        t2[x] := t2[x]+vi[i];
                t3[0] := t1[0]+t2[0];
                if t3[0] > k then t3[0] := k;
                p1 := 1;
                p2 := 1;
                for p3 := 1 to t3[0] do
                if (t1[p1] > t2[p2]) OR (p2 > t2[0]) then
                begin
                        t3[p3] := t1[p1];
                        inc(p1);
                end
                else
                begin
                        t3[p3] := t2[p2];
                        inc(p2);
                end;
                f[j] := t3;
        end;
        j := 0;
        for i := 1 to k do
                j := j+f[v,i];
        writeln(j);
end.

