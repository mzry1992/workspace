const
        g = 0.57721566490153286060651209;
var
        i,n:longint;
        ans:double;
begin
        readln(n);
        if n <= 100000000 then
        begin
                ans := 0;
                for i := 1 to n do
                        ans := ans + 1/i;
        end
        else
                ans := g+ln(n);
        writeln(ans:0:8);
end.