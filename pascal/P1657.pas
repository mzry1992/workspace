var
        n,i,j,k:byte;
        na:array[1..180] of ansistring;
        ww,onwer,gv:array[1..180] of longint;
        fm,mp,f:array[1..180,1..180] of longint;
begin
        readln(n);
        for i := 1 to n do      read(ww[i]);
        readln;
        for i := 1 to n do      read(onwer[i]);
        readln;
        for i := 1 to n do      readln(na[i]);
        for i := 1 to n do
        begin
                for j := 1 to n do      read(mp[i,j]);
                readln;
        end;
        f := mp;
        for k := 1 to n do
        for i := 1 to n do
        for j := 1 to n do
        if i <> j then
        if (f[i,j] > f[i,k]+f[k,j]) then
                f[i,j] := f[i,k]+f[k,j];
        for i := 1 to n do
        for j := 1 to n do
        if i <> j then
                fm[i,j] := ww[i]-f[onwer[i],j]
        else
                fm[i,j] := ww[i];
        for i := 1 to n do
        begin
                for j := 1 to n do      write(fm[i,j],' ');
                writeln;
        end;
end.
