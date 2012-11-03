type
        integer = longint;
var
        a,b:integer;
function        sum(a,b:integer):integer;
begin
        exit(a+b);
end;
begin
        readln(a,b);
        writeln(sum(a,b));
end.