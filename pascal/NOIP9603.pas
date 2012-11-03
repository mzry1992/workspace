var
        top:integer;
        order,do1,do2:char;
        temp,st:string;
begin
        readln(st);
        readln(temp);
        while temp[1] = ' ' do  temp := copy(temp,2,length(temp)-1);
        order := temp[1];
        if order = 'D' then
        begin
                temp := copy(temp,2,length(temp)-1);
                while temp[1] = ' ' do temp := copy(temp,2,length(temp)-1);
                do1 := temp[1];
                if pos(do1,st) = 0 then
                        writeln(do1,' Not Found!')
                else
                writeln(copy(st,1,pos(do1,st)-1)+copy(st,pos(do1,st)+1,length(st)-pos(do1,st)));
        end;
        if order = 'I' then
        begin
                temp := copy(temp,2,length(temp)-1);
                while temp[1] = ' ' do temp := copy(temp,2,length(temp)-1);
                do1 := temp[1];
                temp := copy(temp,2,length(temp)-1);
                while temp[1] = ' ' do temp := copy(temp,2,length(temp)-1);
                do2 := temp[2];
                if pos(do1,st) = 0 then writeln(do1,' Not Found!')
                else
                        writeln(copy(st,1,pos(do1,st)-1)+do1+do2+copy(st,pos(do1,st)+1,length(st)-pos(do1,st)));

        end;
end.