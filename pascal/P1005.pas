var
        st,temp:string;
        ss:ansistring;
        num:longint;
        find:boolean;
begin
        readln(st);
        num := 0;
        find := false;
        ss := '';
        while not find do
        begin
                inc(num);
                str(num,temp);
                ss := ss+temp;
                if pos(st,ss) <> 0 then find := true;
        end;
        writeln(ss);
end.

