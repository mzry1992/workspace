var
         a,b,c,ta,tb,tc,i,j:int64;
function        check:boolean;
begin
        check := false;
        if i = 10000 then       exit;
        if ( a >= b ) and ( a >= c ) and ( a < b+c ) then       exit(true);
        if ( b >= a ) and ( b >= c ) and ( b < a+c ) then       exit(true);
        if ( c >= a ) and ( c >= b ) and ( c < b+a ) then       exit(true);
end;

begin
        while not eof do
        begin
                i := 1;
                readln(a,b,c);
                if check = false then
                begin
                        writeln(-1);
                        continue;
                end;
                i := -1;
                repeat
                        inc(i);
                        ta := b+c-a;
                        tb := a+c-b;
                        tc := a+b-c;
                        a := ta;
                        b := tb;
                        c := tc;
                until check = false;
                if i < 10000 then       writeln(i)
                else    writeln('The voyage seemed endless...')
        end;
end.
