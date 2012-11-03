var
        n,x,y,v,i,j:longint;
        g:array[1..2000,1..2000] of longint;
        f:array[1..2000] of longint;

function max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;

function min(a,b:longint):longint;
begin
        if a < b then exit(a);
        exit(b);
end;

begin
        assign(input,'in.txt');
        assign(output,'out2.txt');
        reset(input);
        rewrite(output);
        readln(n);
        f[1] := maxlongint;
        for i := 2 to n do f[i] := 0;
        fillchar(g,sizeof(g),0);
        readln(x,y,v);
        while not (( x=0) and (y=0) and (v=0)) do
        begin
                g[x,y] := v;
                readln(x,y,v);
        end;
        for i := 2 to n do
        for j := 1 to n do
        if i <> j then
        if f[j] <> 0 then
        if g[j,i] <> 0 then
                f[i] := max(min(f[j],g[j,i]),f[i]);
        for i := 2 to n do writeln(f[i]);
        close(input);
        close(output);
end.

