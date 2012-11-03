var
        i:longint;
begin
        assign(output,'P1693.out');
        rewrite(output);
        writeln('200 200');
        Randomize;
        for i := 1 to 200 do
                write(random(19930713),' ');
        writeln;
        for i := 1 to 200 do
                write(random(19930713),' ');
        writeln;
        close(output);
end.