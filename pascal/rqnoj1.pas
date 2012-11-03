var
        n,i,j,count:byte;
        temp:longint;
        a:array[1..100] of longint;
        flg:boolean;
begin
        readln(n);
        count := 0;
        for i := 1 to n do
        begin
                read(temp);
                flg := true;
                for j := 1 to count do
                if a[j] = temp then
                        flg := false;
                if flg then
                begin
                        inc(count);
                        a[count] := temp;
                end;
        end;
        readln;
        n := count;
        for i := 1 to n-1 do
        for j := i+1 to n do
                if a[j] < a[i] then
                begin
                temp := a[j];   a[j] := a[i];   a[i] := temp;
                end;
        writeln(n);
        for i := 1 to n do      write(a[i],' ');
        writeln;
end.