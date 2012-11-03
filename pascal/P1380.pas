var
        a,b,i,j,total,louchen:longint;
        f:array[1..10000] of longint;

begin
        readln(a,b);
        for i := 1 to a do readln(f[i]);
        for i := 1 to a-1 do
        for j := i+1 to a do
                if i*f[i] = j*f[j] then louchen := (i+j) div 2;
        j := louchen;
        total := 0;
        if b = 0 then
                for i := 1 to j do total := total + f[i]
        else
                for i := a downto j do total := total + f[i];
        writeln(louchen,' ',total);
end.




