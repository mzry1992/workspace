var
        n,m,x,y:longint;
        a:array[1..1100,1..1100] of longint;
begin
        readln(n,m);
        for x := 1 to n do
        begin
                for y := 1 to m do      read(a[x,y]);
                readln;
        end;
end.