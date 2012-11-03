var
        n,m,i,j:longint;
        a,b,c:array[1..5000] of longint;
        g:array[0..5001,0..5001] of longint;
        cross:array[0..5000,0..5000] of boolean;
        f:array[0..5001] of longint;
begin
        readln(n,m);
        fillchar(cross,sizeof(cross),false);
        for i := 1 to m do
        begin
                readln(a[i],b[i],c[i]);
                g[a[i]-1,b[i]] := c[i];
                cross[a[i]-1,b[i]] := true;
        end;
        for i := 1 to n do
        begin
                f[i] := maxlongint;
                g[i-1,i] := 1;
                cross[i-1,i] := true;
                g[i,i-1] := 0;
                cross[i,i-1] := true;
        end;
        f[0] := 0;
        for i := 1 to n do
        for j := 0 to n do
        if cross[j,i] then
        if f[i] > f[j]+g[j,i] then
                f[i] := f[j]+g[j,i];
        writeln(f[n]);
end.