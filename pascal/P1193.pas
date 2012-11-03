var
        n,i,j,k1,k2,k3:longint;
        a:array[0..10000] of longint;
        f:array[0..10000,0..1,0..1,0..1] of longint;
begin
        readln(n);
        for i := 1 to n do      read(a[i]);
        readln;
        fillchar(f,sizeof(f),0);
        f[0,0,0,0] := 1;
        f[0,0,0,1] := 1;
        f[1,0,0,0] := 1;
        f[1,0,0,1] := 1;
        f[1,0,1,0] := 1;
        f[1,0,1,1] := 1;
        for i := 2 to n do
        for k1 := 0 to 1 do
        for k2 := 0 to 1 do
        for k3 := 0 to 1 do
        for j := 0 to 1 do
        if (k1+k2+k3 = a[i]) and (j+k1+k2 = a[i-1]) then
                f[i,k1,k2,k3] := f[i,k1,k2,k3]+f[i-1,j,k1,k2];
        i := 0;
        for k1 := 0 to 1 do
        for k2 := 0 to 1 do
        if (k1+k2 = a[n]) then
                i := i+f[n,k1,k2,0];
        writeln(i);
end.