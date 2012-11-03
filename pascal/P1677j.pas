var
        i:longint;
begin
        assign(output,'p1677.txt');
        rewrite(output);
        for i := 1 to 1000000 do
        begin
                write('a');
                if random < 0.5 then    write('e');
        end;
        writeln;
        close(output);
end.
