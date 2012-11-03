var
        n,i,j,x,y:integer;
begin
        readln(n,i,j);
        for y := 1 to n do
                write('<',i,',',y,')');
        writeln;
        for x := 1 to n do
                write('<',x,',',j,')');
        writeln;
        x := i;
        y := j;
        while (x > 0) and (y > 0) do
        begin
                dec(x);
                dec(y);
        end;
        while (x < n) and ( y < n ) do
        begin
                inc(x);
                inc(y);
                write('<',x,',',y,')');
        end;
        writeln;
        x := i;
        y := j;
        while (x <= n) and ( y > 0 ) do
        begin
                inc(x);
                dec(y);
        end;
        while (x > 0) and ( y < n) do
        begin
                dec(x);
                inc(y);
                write('<',x,',',y,')');
        end;
        writeln;
end.