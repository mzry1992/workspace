var
        a,b,c:longint;
begin
        while not eof do
        begin
                readln(a,b);
                c := a+b;
                writeln(c);
        end;
end.