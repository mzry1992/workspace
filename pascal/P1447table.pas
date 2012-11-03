var
        i:integer;
begin
        assign(output,'P1447out.txt');
        rewrite(output);
        for i := 1 to 200 do
                write(1);
        writeln;
        close(output);
end.