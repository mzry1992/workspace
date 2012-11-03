var
        i,j,k:longint;
begin
        assign(output,'P1690.in');
        rewrite(output);
        writeln('1 100');
        k := 1000;
        for i := 1 to 99 do
        begin
                writeln(k,' 0 1');
                writeln(i+1,' ',10);
                k := k-10;
        end;
        writeln('0 0 0');
        close(output);
end.