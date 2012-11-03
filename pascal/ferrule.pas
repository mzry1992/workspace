program ferrule;
procedure       setinput;
begin
        assign(input,'ferrule.in');
        assign(output,'ferrule.out');
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(input);
        close(output);
end;
procedure       main;
var
        h,n,i,tot:longint;
        a:array[1..100] of longint;
begin
        readln(n);
        for i := 1 to n do      read(a[i]);
        readln;
        readln(h);
        tot := 0;
        for i := 1 to n do
        if a[i] <= h+30 then inc(tot);
        writeln(tot);
end;
begin
        setinput;
        main;
        setoutput;
end.
