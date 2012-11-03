var
        maxt,n,i,j,max:longint;
        w,v:array[1..100] of longint;
        f:array[0..1000] of longint;
begin
        readln(maxt,n);
        for i := 1 to n do
                readln(w[i],v[i]);
        max := 0;
        fillchar(f,sizeof(f),0);
        for i := 1 to n do
        for j := maxt downto w[i] do
        if f[j] < f[j-w[i]]+v[i] then
        begin
                f[j] := f[j-w[i]]+v[i];
                if f[j] > max then
                        max := f[j];
        end;
        writeln(max);
end.