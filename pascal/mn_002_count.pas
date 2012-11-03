uses    sysutils;
const
        jamnum = 'abcdefghijklmnopqrstuvwxyz';
var
        s,t,w,loop,i,j:longint;
        max,num:string;
        flog:text;
        t1,t2:double;
procedure       setinput;
begin
        assign(input,'count.in');
        assign(output,'count.out');
        assign(flog,'count.log');
        append(flog);
        reset(input);
        rewrite(output);
        t1 := now;
end;
procedure       setoutput;
begin
        t2 := now;
        writeln(flog,(t2-t1)*24*3600:0:10);
        close(flog);
        close(input);
        close(output);
end;
begin
        setinput;
        readln(s,t,w);
        readln(num);
        max := copy(jamnum,t-w+1,w);
        loop := 1;
        while (loop <= 5) and (num <> max) do
        begin
                i := w;
                while num[i] = max[i] do        dec(i);
                num[i] := succ(num[i]);
                for j := i+1 to w do
                        num[j] := succ(num[j-1]);
                writeln(num);
                inc(loop);
        end;
        setoutput;
end.
