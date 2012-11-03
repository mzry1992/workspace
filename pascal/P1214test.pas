const
        max = 1000;
var
        n,i,ans,t1,t2,t3:longint;
begin
        assign(output,'P1214out.txt');
        rewrite(output);
        for n := 1 to max do
        begin
                t2 := (n+2) div 6 + n shr 1 + 1 and n;
                writeln(n,'     ',n-t2);
        end;
        close(output);
end.
