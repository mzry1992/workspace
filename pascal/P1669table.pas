type
        arr = array[0..500] of longint;
var
        n,i,count:longint;
        ans:arr;
function long(a:arr):longint;
var
        t:longint;
begin
        t := 500;
        while (a[t] = 0) and (t > 0) do dec(t);
        if t = 0 then t := 1;
        exit(t);
end;
function chen(a:arr;b:longint):arr;
var
        i,j:longint;
begin
        j := 0;
        for i := 1 to a[0] do
        begin
                a[i] := a[i]*b+j;
                j := a[i] div 10;
                a[i] := a[i] mod 10;
        end;
        repeat
                inc(a[0]);
                a[a[0]] := j mod 10;
                j := j div 10;
        until   j = 0;
        a[0] := long(a);
        exit(a);
end;
procedure outp(a:arr);
var
        t:longint;
begin
        inc(count);
        t := 1;
        while a[t] = 0 do inc(t);
        write(a[t]:5);
        if count mod 10 = 0 then writeln;
end;
begin
        assign(output,'P1669table1n.txt');
        rewrite(output);
        count := 0;
        for n := 1 to 1000 do
        begin
                fillchar(ans,sizeof(ans),0);
                ans[0] := 1;
                ans[1] := 1;
                for i := 1 to n do
                if (n mod 5 <> 0) then
                        ans := chen(ans,i);
                outp(ans);
        end;
        close(output);
end.
