var
        n,i,k,l,r:longint;
        a,b:array[1..100000] of longint;
        ans:int64;
procedure qsort1(l,r:longint);
var
        i,j,mid,temp:longint;
begin
        i := l; j := r; mid := a[(i+j) shr 1];
        repeat
        while a[i] < mid do     inc(i);
        while a[j] > mid do     dec(j);
        if i <= j then
        begin
                temp := a[i];   a[i] := a[j];   a[j] := temp;
                inc(i); dec(j);
        end;
        until i > j;
        if i < r then   qsort1(i,r);
        if l < j then   qsort1(l,j);
end;
procedure qsort2(l,r:longint);
var
        i,j,mid,temp:longint;
begin
        i := l; j := r; mid := b[(i+j) shr 1];
        repeat
        while b[i] > mid do     inc(i);
        while b[j] < mid do     dec(j);
        if i <= j then
        begin
                temp := b[i];   b[i] := b[j];   b[j] := temp;
                inc(i); dec(j);
        end;
        until i > j;
        if i < r then   qsort2(i,r);
        if l < j then   qsort2(l,j);
end;
begin
        readln(n,k);
        for i := 1 to n do      read(a[i]);
        readln;
        for i := 1 to n do      read(b[i]);
        readln;
        qsort1(1,n);
        qsort2(1,n);
        ans := 0;
        l := 1; r := n;
        while k > 0 do
        begin
                if abs(b[l]-a[l]) >= abs(a[r]-b[r]) then
                begin
                        ans := ans+int64(abs(b[l]-a[l]));
                        inc(l);
                end
                else
                begin
                        ans := ans+int64(abs(a[r]-b[r]));
                        dec(r);
                end;
                dec(k);
        end;
        writeln(ans);
end.