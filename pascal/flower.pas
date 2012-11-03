program flower;
procedure       setinput;
begin
        assign(input,'flower.in');
        assign(output,'flower.out');
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(input);
        close(output);
end;
var
        n,l,r,i:longint;
        d,f,c:array[1..1000] of longint;

procedure       main;
begin
        readln(n,l,r);
        for i := 1 to n do      read(d[i]);
        readln;
        for i := 1 to n do      read(f[i]);
        readln;
        for i := 1 to n do      read(c[i]);
        readln;

end;
begin
        main;
end.
