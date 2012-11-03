const
        base:array[1..4,1..4] of 0..1 = ((1,0,0,0),
                                         (1,1,0,0),
                                         (1,0,1,0),
                                         (1,1,1,1));
var
        t,n,k,i:longint;
begin
        readln(t);
        for i := 1 to t do
        begin
                readln(n,k);
                writeln(base[n mod 4,k mod 4]);
        end;
end.

