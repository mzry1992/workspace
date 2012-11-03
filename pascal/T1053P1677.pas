var
        sname,tmb:ansistring;
        minl,ti,lname:longint;

function        check(mb:ansistring):boolean;
var
        i,j,l:longint;
begin
        i := 1;
        j := 1;
        l := length(mb);
        if sname[lname] <> mb[l] then   exit(false);
        repeat
                while (sname[j] = mb[i]) and (i <= l) do
                begin
                        inc(i); inc(j);
                end;
                if j = lname+1 then     exit(true);
                if sname[j] <> mb[1] then       exit(false);
                i := 1;
        until   j >= lname;
        exit(true);
end;

begin
        assign(input,'P1677.txt');
        reset(input);
        readln(sname);
        close(input);
        lname := length(sname);
        ti := 2;
        while ( sname[ti] <> sname[1] ) and (ti <= lname) do inc(ti);
        if ti = lname+1 then
        begin
                writeln(lname);
                halt;
        end;
        repeat
                tmb := copy(sname,1,ti-1);
                if check(tmb) then
                begin
                        writeln(ti-1);
                        halt;
                end;
                inc(ti);
                while ( sname[ti] <> sname[1] ) and (ti <= lname) do inc(ti);
        until   ti = lname+1;
        writeln(lname);
end.
