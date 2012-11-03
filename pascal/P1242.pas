var
        n,m,i,j,k,t:longint;
        a:array[1..300] of longint;
        g:array[1..300,1..300] of longint;
        f:array[1..300,1..30] of longint;
function        min(a,b:longint):longint;
begin
        if a < b then   exit(a);
        exit(b);
end;
begin
        readln(n,m);
        for i := 1 to n do      read(a[i]);
        readln;
        for i := 1 to n-1 do
        for j := i+1 to n do
        if a[i] > a[j] then
        begin
                t := a[i];      a[i] := a[j];   a[j] := t;
        end;
        for i := 1 to n do
        for j := i to n do
        begin
                t := a[(i+j) div 2];
                g[i,j] := 0;
                for k := i to j do
                        g[i,j] := g[i,j]+abs(t-a[k]);
        end;
        for i := 1 to n do      f[i,1] := g[1,i];
        for i := 2 to n do
        for j := 2 to m do
        begin
                f[i,j] := maxlongint;
                for k := j-1 to i-1 do
                        f[i,j] := min(f[i,j],f[k,j-1]+g[k+1,i]);
        end;
        writeln(f[n,m]);
end.


