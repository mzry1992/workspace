var
        i,j:longint;
begin
        assign(output,'P1697.txt');
        rewrite(output);
        writeln('200 200 ',200*200);
        for i := 1 to 200 do
        begin
                write('l1 ');
                write('v ');
                writeln('l',i);
        end;
        for i := 1 to 200 do
        for j := 1 to 200 do    writeln('l',i,' l',j);
        close(output);
end.
