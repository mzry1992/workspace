uses    sysutils;
var
        n,count:longint;
        bt,et:double;
function prime(n:longint):boolean;
var
        k,m:longint;
begin
        m := trunc(sqrt(n));
        if n = 1 then exit(false);
        if n = 2 then exit(true);
        if n and 1 = 0 then exit(false);
        for k := 2 to m do
        if n mod k = 0 then exit(false);
        exit(true);
end;
begin
        assign(output,'PrimeNum.txt');
        rewrite(output);
        bt := now;
        count := 0;
        for n := 1 to 1000000 do
        begin
                if prime(n) then
                begin
                        write(n:10);
                        inc(count);
                        if count mod 5 = 0 then writeln;
                end;
        end;
        writeln;
        et := now;
        writeln('Total Use : ',(et-bt)*24*3600:0:5,' ms');
        close(output);
end.