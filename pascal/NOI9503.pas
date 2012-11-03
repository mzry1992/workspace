var
        n,ta,tb,t1,t2,tt:longint;
begin
        ta := 0;
        tb := 0;
        for n := 1 to 1000 do
        begin
                tt := n;
                t1 := 0;
                t2 := 0;
                repeat
                        if tt and 1 = 1 then    inc(t1)
                        else                    inc(t2);
                        tt := tt shr 1;
                until tt = 0;
                if t1 > t2 then inc(ta)
                else            inc(tb);
        end;
        writeln(ta);
        writeln(tb);
end.