var
        mid,n,i,x:longint;
        ans:qword;
        y:array[1..10000] of longint;
procedure       qsort(l,r:longint);
var
        i,j,m,t:longint;
begin
        i := l; j := r; m := y[(l+r) div 2];
        repeat
                while y[i] < m do       inc(i);
                while y[j] > m do       dec(j);
                if i <= j then
                begin
                        t := y[i];      y[i] := y[j];   y[j] := t;
                        inc(i);
                        dec(j);
                end;
        until i > j ;
        if i < r then   qsort(i,r);
        if l < j then   qsort(l,j);
end;

begin
        readln(n);
        for i := 1 to n do      readln(x,y[i]);
        qsort(1,n);
        mid := y[(1+n) shr 1];
        ans := 0;
        for i := 1 to n do
                ans := abs(y[i]-mid)+ans;
        writeln(ans);
end.