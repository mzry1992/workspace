var
        maxm,n,i,j,tw,tv,max:longint;
        w,v:array[1..25] of longint;
        f:array[0..30000] of longint;
begin
        readln(maxm,n);
        for i := 1 to n do
        begin
                readln(tw,tv);
                w[i] := tw;
                v[i] := tw*tv;
        end;
        max := 0;
        fillchar(f,sizeof(f),0);
        for i := 1 to n do
        for j := maxm downto w[i] do
        if f[j] < f[j-w[i]]+v[i] then
        begin
                f[j] := f[j-w[i]]+v[i];
                if f[j] > max then
                        max := f[j];
        end;
        writeln(max);
end.