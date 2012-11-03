var
        i:longint;
begin
        assign(output,'P1455.in');
        rewrite(output);
        randomize;
        for i := 1 to 5 do
                write(random(9));
        writeln;
        writeln(random(10));
        close(output);
end.
