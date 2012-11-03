const
        jamnum = 'abcdefghijklmnopqrstuvwxyz';
var
        s,t,w,step:longint;
        be,max,now:string;
function next(str:string):string;
var
        i,temp1,temp2:longint;
        st:string;
begin
        i := w;
        st := str;
        while st[i] = jamnum[t-w+i] do  dec(i);
        temp1 := 1;
        temp2 := ord(st[i]);
        while i <= w do
        begin
                st[i] := chr(temp2+temp1);
                inc(temp1);
                inc(i);
        end;
        exit(st);
end;
begin
        assign(input,'count.in');
        reset(input);
        assign(output,'count.out');
        rewrite(output);
        readln(s,t,w);
        readln(be);
        max := copy(jamnum,t-w+1,w);
        if be = max then halt;
        step := 0;
        now := be;
        while ( step < 5) and (now <> max) do
        begin
                inc(step);
                now := next(now);
                writeln(now);
        end;
        close(input);
        close(output);
end.


