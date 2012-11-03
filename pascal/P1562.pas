var
        k,step:longint;

procedure move(n:longint);
var
        i:longint;
begin
        if n = 4 then
        begin
                inc(step);
                write('step ',step,':OOOO****__');
                for i := 1 to k-n do    write('O*');
                writeln;
                inc(step);
                write('step ',step,':OOO__***O*');
                for i := 1 to k-n do    write('O*');
                writeln;
                inc(step);
                write('step ',step,':OOO*O**__*');
                for i := 1 to k-n do    write('O*');
                writeln;
                inc(step);
                write('step ',step,':O__*O**OO*');
                for i := 1 to k-n do    write('O*');
                writeln;
                inc(step);
                write('step ',step,':O*O*O*__O*');
                for i := 1 to k-n do    write('O*');
                writeln;
                inc(step);
                write('step ',step,':__O*O*O*O*');
                for i := 1 to k-n do    write('O*');
                writeln;
                exit;
        end;
        inc(step);
        write('step ',step,':');
        for i := 1 to n do    write('O');
        for i := 1 to n do    write('*');
        write('__');
        for i := 1 to k-n do    write('O*');
        writeln;
        inc(step);
        write('step ',step,':');
        for i := 1 to n-1 do    write('O');
        write('__');
        for i := 1 to n-1 do    write('*');
        write('O*');
        for i := 1 to k-n do    write('O*');
        writeln;
        move(n-1);
end;

begin
        readln(k);
        step := -1;
        move(k);
end.