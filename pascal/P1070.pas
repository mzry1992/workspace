const copyright = 'Kissy';
var
        x,y:array[1..300000] of longint;
        c:array[1..300000] of qword;
        f,usedbian:array[1..1000] of longint;
        n,m,i,j,f1,f2,tempci,deletbiani:longint;
        min1,min2,minnow:qword;

function findf(i:longint):longint;
begin
        if f[i] = i then exit(f[i]);
        f[i] := findf(f[i]);
        exit(f[i]);
end;

procedure qsort(l,r:longint);
var
        i,j,temp,m:longint;
begin
        i := l; j := r; m := c[(i+j) div 2];
        repeat
                while c[i] < m do inc(i);
                while c[j] > m do dec(j);
                if i <= j then
                begin
                        temp := x[i];   x[i] := x[j];   x[j] := temp;
                        temp := y[i];   y[i] := y[j];   y[j] := temp;
                        temp := c[i];   c[i] := c[j];   c[j] := temp;
                        inc(i); dec(j);
                end;
        until i > j;
        if i < r then qsort(i,r);
        if l < j then qsort(l,j);
end;

begin
        readln(n,m);
        if m < n-1 then
        begin
                writeln('Cost: -1');
                writeln('Cost: -1');
                halt;
        end;
        for i := 1 to m do      readln(x[i],y[i],c[i]);
        for i := 1 to n do      f[i] := i;
        qsort(1,m);
        i := 0;
        j := 0;
        min1 := 0;
        while j < n-1 do
        begin
                inc(i);
                f1 := findf(x[i]);
                f2 := findf(y[i]);
                if f1 <> f2 then
                begin
                        f[f1] := f2;
                        inc(j);
                        usedbian[j] := i;
                        min1 := min1+c[i];
                end;
        end;
        if m = n - 1 then
        begin
                writeln('Cost: ',min1);
                writeln('Cost: -1');
                halt;
        end;
        min2 := maxlongint * maxlongint;
        for deletbiani := 1 to n-1 do
        begin
                tempci := c[usedbian[deletbiani]];
                c[usedbian[deletbiani]] := -1;
                for i := 1 to n do f[i] := i;
                i := 0;
                j := 0;
                minnow := 0;
                while j < n-1 do
                begin
                        inc(i);
                        if c[i] <> -1 then
                        begin
                                f1 := findf(x[i]);
                                f2 := findf(y[i]);
                                if f1 <> f2 then
                                begin
                                        f[f1] := f2;
                                        inc(j);
                                        minnow := minnow+c[i];
                                end;
                        end;
                end;
                c[usedbian[deletbiani]] := tempci;
                if minnow < min2 then min2 := minnow;
        end;
        writeln('Cost: ',min1);
        writeln('Cost: ',min2);
end.
