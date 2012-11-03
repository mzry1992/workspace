var
        a,b:longint;
function        gcd(a,b:longint):longint;
begin
        if b = 0 then exit(a);
        exit(gcd(b,a mod b));
end;

begin
        while not eof do
        begin
                readln(a,b);
                writeln(gcd(a,b));
        end;
end.