program mountain;
var
        tot,n,i,j,now,l,r:longint;
        x,y:array[1..100000] of longint;

procedure       qsort(l,r:longint);
var
        i,j,m,temp:longint;
begin
        i := l; j := r; m := x[(i+j) shr 1];
        repeat
                while m > x[i] do       inc(i);
                while m < x[j] do       dec(j);
                if i <= j then
                begin
                        temp := x[i];   x[i] := x[j];   x[j] := temp;
                        temp := y[i];   y[i] := y[j];   y[j] := temp;
                        inc(i);
                        dec(j);
                end;
        until   i > j;
        if i < r then qsort(i,r);
        if l < j then qsort(l,j);
end;
procedure       setinput;
begin
        assign(input,'mountain.in');
        assign(output,'mountain.out');
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(input);
        close(output);
end;
procedure       main;
begin
        readln(tot,n);
        for i := 1 to n do      readln(x[i],y[i]);
        qsort(1,n);
        now := 0;
        l := x[1];
        r := y[1];
        for i := 1 to n do
        begin
                if x[i] <= r then
                begin
                        if y[i] > r then        r := y[i];
                end
                else
                begin
                        now := now+r-l+1;
                        l := x[i];
                        r := y[i];
                end;
        end;
        now := now+r-l+1;
        writeln(tot+1-now);
end;
begin
        setinput;
        main;
        setoutput;
end.
