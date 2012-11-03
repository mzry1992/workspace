var
        a,b:array[0..20] of integer;
        n,i,j:integer;
begin
        readln(n);
        for i := 1 to n do
                read(a[i]);
        readln;
        fillchar(b,sizeof(b),0);
        for i := 1 to n-1 do
        for j := 0 to i-1 do
        if a[j] < a[i] then     inc(b[i]);
        for i := 0 to n-1 do
                write(b[i]:5);
        writeln;
end.

