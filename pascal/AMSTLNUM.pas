var
        a,b,c:integer;
begin
        for a := 0 to 9 do
        for b := 0 to 9 do
        for c := 0 to 9 do
        if (a+b+c) > 0 then
        begin
                if a*100+b*10+c=a*a*a+b*b*b+c*c*c then
                begin
                        case    a*100+b*10+c    of
                                100..999    :       writeln(a,b,c,' = ',a,'^3+',b,'^3+',c,'^3');
                                10..99      :       writeln(b,c,' = ',b,'^3+',c,'^3');
                                1..9        :       writeln(c,' = ',c,'^3');
                        end;
                end;
        end;
end.