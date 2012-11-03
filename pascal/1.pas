var
        i,a,b,c,ta,tb,tc:longint;
begin
        a := 7;
        b := 2;
        c := 4;
        for i := 1 to 3 do
        begin
                ta := a shr (i-1) and 1;
                tb := b shr (i-1) and 1;
                tc := c shr (i-1) and 1;
                writeln(ta,' ',tb,' ',tc);
        end;
end.

