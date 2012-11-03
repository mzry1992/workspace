var
        n,temp:longint;
begin
        assign(output,'P1662.txt');
        rewrite(output);
        writeln(100000,' ',100000);
        randomize;
        for n := 1 to 100000 do
        begin
                temp := random(maxlongint div 2)+maxlongint div 2;
                write(temp,' ');
        end;
        writeln;
        for n := 1 to 100000 do
        begin
                temp := random(maxlongint div 2)+maxlongint div 2;
                write(temp,' ');
        end;
        writeln;
        close(output);
end.