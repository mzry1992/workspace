var
        n,k,tk,tl,i,now:longint;
        a,b,c:array[1..1000] of longint;
begin
        readln(n,k);
        for tk := 1 to k do     readln(a[tk],b[tk],c[tk]);
        for tl := 1 to 10 do
        begin
                now := tl;
                for i := k downto 1 do
                begin
                        if c[i]+1 <= now then
                        begin
                                if (c[i]+b[i]-a[i]+1) >= now then
                                        now := now-c[i]-1+a[i]
                                else
                                if b[i] >= now then
                                        now := now-(b[i]-a[i]+1);
                        end
                        else
                        if a[i] <= now then
                                now := now+(b[i]-a[i]+1);
                end;
                writeln(now);
        end;
end.
