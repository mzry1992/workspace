var
        n,i:longint;
        l,ans:qword;
begin
        ans := 0;
        readln(n);
        for i := 1 to n do
        begin
                read(l);
                ans := ans xor l;
        end;
        readln;
        writeln(ans);
end.