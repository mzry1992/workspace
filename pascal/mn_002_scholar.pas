uses    sysutils;
var
        flog:text;
        time1,time2:double;
procedure       setinput;
begin
        assign(input,'scholar.in');
        assign(output,'scholar.out');
        assign(flog,'scholar.log');
        append(flog);
        reset(input);
        rewrite(output);
        time1 := now;
end;
procedure       setoutput;
begin
        time2 := now;
        writeln(flog,(time2-time1)*24*3600:0:10);
        close(flog);
        close(input);
        close(output);
end;
procedure       main;
var
        n,i,j:longint;
        chinese,math,english,tot:longint;
        stud:array[1..300] of string;
        studzf:array[1..300] of longint;
        studxh:array[1..300] of longint;
        stemp:string;
        ltemp:longint;

        function        intto3str(i:longint):string;
        var
                temp:string;
        begin
                str(i,temp);
                while length(temp) < 3 do       temp := '0'+temp;
                exit(temp);
        end;

begin
        readln(n);
        for i := 1 to n do
        begin
                readln(chinese,math,english);
                tot := chinese+math+english;
                studzf[i] := tot;
                studxh[i] := i;
                stud[i] := intto3str(tot)+intto3str(chinese)+intto3str(1000-i);
        end;
        for i := 1 to n-1 do
        for j := i+1 to n do
        if stud[i] < stud[j] then
        begin
                stemp := stud[i];       stud[i] := stud[j];     stud[j] := stemp;
                ltemp := studzf[i];     studzf[i] := studzf[j]; studzf[j] := ltemp;
                ltemp := studxh[i];     studxh[i] := studxh[j]; studxh[j] := ltemp;
        end;
        for i := 1 to 5 do
                writeln(studxh[i],' ',studzf[i]);
end;
begin
        setinput;
        main;
        setoutput;
end.