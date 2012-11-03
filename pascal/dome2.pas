var
        i,a,b,c,ans:longint;
begin
        a := 23;
        write('    ');
        for i := 8 downto 1 do
                write(a shr (i-1) and 1);
        writeln;
        write('or  ');
        b := 2;
        for i := 8 downto 1 do
                write(b shr (i-1) and 1);
        writeln;
        writeln('---------------------');
        write('=   ');
        ans := a or b;
        for i := 8 downto 1 do
                write(ans shr (i-1) and 1);
        writeln;
        write('xor ');
        c := 5;
        for i := 8 downto 1 do
                write(c shr (i-1) and 1);
        writeln;
        writeln('---------------------');
        write('=   ');
        ans := a or b xor c;
        for i := 8 downto 1 do
                write(ans shr (i-1) and 1);
        writeln;
end.