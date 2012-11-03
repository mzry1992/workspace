const
        maxb = 21;
        maxc = 35000;
var
        i,j,c,b:longint;
        a:array[1..maxb] of longint;
        tot:array[0..maxb] of longint;
        f:array[0..maxb,0..maxc] of boolean;
begin
        readln(c,b);
        for i := 1 to b do
        begin
                read(a[i]);
                if a[i] > c then a[i] := 0;
        end;
        readln;
        fillchar(tot,sizeof(tot),0);
        for i := 1 to b do
        begin
                tot[i] := tot[i-1]+a[i];
                if tot[i] > c then tot[i] := c;
        end;
        fillchar(f,sizeof(f),false);
        f[0,0] := true;
        for i := 1 to b do
        begin
                for j := 0 to a[i]-1 do
                        f[i,j] := f[i-1,j];
                for j := a[i] to tot[i] do
                        f[i,j] := f[i-1,j] or f[i-1,j-a[i]];
        end;
        for i := c downto 0 do
        if f[b,i] then
        begin
                writeln(i);
                halt;
        end;
end.
