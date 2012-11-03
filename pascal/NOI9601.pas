var
        a,b,t,tt,k:integer;
begin
        readln(a,b);
        writeln(' ',a:4);
        writeln('X',b:4);
        writeln('-----');
        t := b;
        k := 0;
        if b > 10 then
        repeat
                if t mod 10 > 0 then
                begin
                        tt := a * (t mod 10);
                        writeln(' ',tt:(4-k));
                end
                else
                        if t > 10 then writeln(' ',0:(3-k),'0')
                        else
                                writeln(' ',0:(4-k));
                t := t div 10;
                inc(k);
        until t = 0;
        if b > 10 then writeln('-----');
        writeln(a*b:5);
end.