var
        n,m,i,j,k:longint;
        mp:array[1..50,1..50] of longint;
        f:array[0..100,0..50,0..50] of longint;
function max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;
begin
        readln(n,m);
        for i := 1 to n do
        begin
                for j := 1 to m do      read(mp[i,j]);
                readln;
        end;
        fillchar(f,sizeof(f),0);
        for i := 1 to n+m-1 do
        for j := 1 to n do
        for k := 1 to n do
        if j <> k then
        begin
                f[i,j,k] := f[i-1,j,k];
                f[i,j,k] := max(f[i-1,j,k-1],f[i,j,k]);
                f[i,j,k] := max(f[i-1,j-1,k],f[i,j,k]);
                f[i,j,k] := max(f[i-1,j-1,k-1],f[i,j,k]);
                f[i,j,k] := f[i,j,k]+mp[j,i-j]+mp[k,i-k];
        end;
        writeln(f[n+m-1,n-1,n]);
end.