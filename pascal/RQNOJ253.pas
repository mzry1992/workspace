var
        n,k,i,j:longint;
        a,b:array[1..3000] of int64;
        flg:boolean;
begin
        readln(n,k);
        for i := 1 to n do      read(a[i]);
        readln;
        for i := 1 to n-1 do
        begin
                b := a;
                for j := 1 to n-i do    b[j] := a[j+1]-a[j];
                a := b;
                flg := true;
                for j := 1 to n-i do
                if a[j] <> 0 then
                begin
                        flg := false;
                        break;
                end;
                if flg then
                begin
                        for j := 1 to n do write(a[j]:4);
                        writeln;
                end;
        end;
        writeln('No');
end.
