uses    sysutils;
var
        flog:text;
        time1,time2:double;
        n,i,t,ans:longint;
        a:array[1..10000] of longint;
procedure       setinput;
begin
        assign(input,'fruit.in');
        assign(output,'fruit.out');
        assign(flog,'fruit.log');
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
procedure       qsort(l,r:longint);
var
        i,j,m,t:longint;
begin
        i := l; j := r; m := a[(i+j) shr 1];
        repeat
                while a[i] < m do       inc(i);
                while a[j] > m do       dec(j);
                if i <= j then
                begin
                        t := a[i];      a[i] := a[j];   a[j] := t;
                        inc(i);
                        dec(j);
                end;
        until   i > j;
        if i < r then   qsort(i,r);
        if l < j then   qsort(l,j);
end;
begin
        setinput;
        readln(n);
        for i := 1 to n do      read(a[i]);
        readln;
        ans := 0;
        for i := 1 to n-1 do
        begin
                qsort(1,n+1-i);
                t := a[1]+a[2];
                ans := ans+t;
                a[1] := t;
                a[2] := a[n+1-i];
        end;
        writeln(ans);
        setoutput;
end.