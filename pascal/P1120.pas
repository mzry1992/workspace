var
        n,m,x,y,k,tb,temp,sum,now,tcost:longint;
        a:array[1..20,1..20] of longint;
        b:array[1..400,1..3] of longint;
begin
        readln(n,m,k);
        tb := 0;
        for x := 1 to n do
        begin
                for y := 1 to m do
                begin
                        read(a[x,y]);
                        if a[x,y] > 0 then
                        begin
                                inc(tb);
                                b[tb,1] := x;
                                b[tb,2] := y;
                                b[tb,3] := a[x,y];
                        end;
                end;
                readln;
        end;
        for x := 1 to tb-1 do
        for y := x+1 to tb do
        if b[x,3] < b[y,3] then
        begin
                temp := b[x,3]; b[x,3] := b[y,3];       b[y,3] := temp;
                temp := b[x,2]; b[x,2] := b[y,2];       b[y,2] := temp;
                temp := b[x,1]; b[x,1] := b[y,1];       b[y,1] := temp;
        end;
        sum := b[1,3];
        k := k-(b[1,1]+1);
        now := 1;
        while true do
        begin
                inc(now);
                tcost := abs(b[now,1]-b[now-1,1])+abs(b[now,2]-b[now-1,2])+1+b[now,1];
                if tcost <= k then
                begin
                        sum := sum+b[now,3];
                        k := k-tcost+b[now,1];
                end
                else
                begin
                        writeln(sum);
                        halt;
                end;
        end;
end.



