program angling;
procedure       setinput;
begin
        assign(input,'angling.in');
        assign(output,'angling.out');
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(input);
        close(output);
end;
var
        t,n,i,w,v,j:longint;
        f:array[0..1000] of longint;
function        max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;
procedure       main;
begin
        fillchar(f,sizeof(f),0);
        readln(t,n);
        for i := 1 to n do
        begin
                readln(w,v);
                for j := t downto w do
                        f[j] := max(f[j],f[j-w]+v);
        end;
        writeln(f[t]);
end;
begin
        setinput;
        main;
        setoutput;
end.