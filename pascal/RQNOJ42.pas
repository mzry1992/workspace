var
        n,k,i,j:longint;
        f,a:array[1..5000] of longint;
        m,tm:double;
function        max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;
begin
        readln(n,k);
        for i := 1 to n do      readln(a[i]);
        f[1] := 1;
        for i := 2 to n do
        begin
                f[i] := n;
                m := 19921005;
                for j := i-1 downto max(1,i-k) do
                begin
                        tm := (a[i]-a[j])/(i-j);
                        if tm < m then  m := tm;
                        if tm <= m then
                        if f[j]+1 < f[i] then
                                f[i] := f[j]+1;
                end;
        end;
        writeln(f[n]);
end.

