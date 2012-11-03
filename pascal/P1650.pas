var
        school:array[1..10000,1..2] of integer;
        nam:array[1..200] of string;
        themax:array[1..200] of double;
        fn,fm,fi,i,x,y,totsch,t,j:longint;
        tmin:double;
        ch:char;
        tstr:string;
begin
        readln(fn,fm,fi);
        totsch := 0;
        for x := 1 to fn do
        begin
                for y := 1 to fm do
                begin
                        read(ch);
                        if ch = '#' then
                        begin
                                inc(totsch);
                                school[totsch,1] := x;
                                school[totsch,2] := y;
                        end;
                end;
                readln;
        end;
        for i := 1 to fi do
        begin
                readln(nam[i]);
                themax[i] := -10e8;
                for x := 1 to fn do
                begin
                        for y := 1 to fm do
                        begin
                                read(ch);
                                if ch = '#' then
                                begin
                                        tmin := 10e8;
                                        for t := 1 to totsch do
                                        begin
                                                if tmin > sqrt(sqr(school[t,1]-x)+sqr(school[t,2]-y)) then
                                                        tmin := sqrt(sqr(school[t,1]-x)+sqr(school[t,2]-y));
                                        end;
                                        if tmin > themax[i] then
                                                themax[i] := tmin;
                                end;
                        end;
                        readln;
                end;
        end;
        for i := 1 to fi-1 do
        for j := i+1 to fi do
        begin
                if themax[i] > themax[j] then
                begin
                        tstr := nam[i];         nam[i] := nam[j];       nam[j] := tstr;
                        tmin := themax[i];      themax[i] := themax[j]; themax[j] := tmin;
                end;
                if themax[i] = themax[j] then
                if nam[i] > nam[j] then
                begin
                        tstr := nam[i];         nam[i] := nam[j];       nam[j] := tstr;
                        tmin := themax[i];      themax[i] := themax[j]; themax[j] := tmin;
                end;
        end;
        for i := 1 to fi do
        begin
                writeln(nam[i]);
                writeln(themax[i]:0:5);
        end;
end.

