var
        t,m,s,i,tm,tt,temp,min,mint,maxs:longint;
        can:boolean;
begin
        readln(m,s,t);
        maxs := -maxlongint;
        mint := maxlongint;
        can := false;
        for i := t downto 0 do
        begin
                tm := m+i*4;
                tt := tm div 10;
                if tt > t then  tt := t;
                if tt+i > t then continue;
                temp := tt*60+(t-(tt+i))*17;
                if temp >= s then
                begin
                        can := true;
                        min := t-(tt+i);
                        while ( min > 0) and (temp-17 >=s) do
                        begin
                                dec(min);
                                temp := temp-17;
                        end;
                        if min+i+tt < mint then mint := min+i+tt;
                end;
                if temp > maxs then      maxs := temp;
        end;
        if can then
        begin
                writeln('Yes');
                writeln(mint);
        end
        else
        begin
                writeln('No');
                writeln(maxs);
        end;
end.
