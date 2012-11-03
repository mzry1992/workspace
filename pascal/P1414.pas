var
        num:string;
        n,i:byte;
        max:char;
        maxpos:byte;
begin
        readln(num);
        readln(n);
        for i := 1 to n do
        begin
                maxpos := 1;
                while (num[maxpos] <= num[maxpos+1]) and (maxpos < length(num)) do
                        inc(maxpos);
                num := copy(num,1,maxpos-1)+copy(num,maxpos+1,length(num)-maxpos);
        end;
        while (num[1] = '0') and (length(num) > 1) do
                num := copy(num,2,length(num)-1);
        writeln(num);
end.
