var
        g:array[1..2000,1..2000] of longint;
        dis:array[1..2000] of longint;
        n,i,j,k:longint;

function max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;

begin
        readln(n);
        readln(i,j,k);
        fillchar(g,sizeof(g),0);
        while (( i <> 0 ) and ( j <> 0 ) and ( k <> 0 )) do
        begin
                g[i,j] := k;
                readln(i,j,k);
        end;
        fillchar(dis,sizeof(dis),0);
        for i := 1 to n do
        for j := 1 to n do
        if g[i,j] <> 0 then
                dis[j] := max(dis[i],g[i,j]);
        close;
        for i := 2 to n do writeln(dis[i]);
end.
