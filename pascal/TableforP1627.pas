const
        n = 1000;
var
        i,ran:longint;
begin
        randomize;
        assign(output,'1.txt');
        rewrite(output);
        writeln(n,' ',random(10),' ',random(10));
        for i := 1 to n do
        begin
                ran := random(10);
                write(ran,' ');
        end;
        writeln;
        for i := 1 to n do
        begin
                ran := random(10);
                write(ran,' ');
        end;
        writeln;
        for i := 1 to n do
        begin
                ran := random(10);
                write(ran,' ');
        end;
        writeln;
        close(output);
end.
