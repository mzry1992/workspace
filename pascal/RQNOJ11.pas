var
        m,n,i,j:longint;
        tot:array[0..9] of longint;
        st:string;
begin
        readln(m,n);
        fillchar(tot,sizeof(tot),0);
        for i := m to n do
        begin
                str(i,st);
                for j := 1 to length(st) do
                        inc(tot[ord(st[j])-ord('0')]);
        end;
        for i := 0 to 8 do      write(tot[i],' ');
        writeln(tot[9]);
end.