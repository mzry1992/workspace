var
        k,n,fm,i,j,ans:longint;
        a:array[1..32] of 0..1;
begin
        readln(k,n);
        fm := 1;
        for i := 1 to 32 do
                a[i] := n shr (i-1) and 1;
        i := 32;
        while a[i] = 0 do dec(i);
        ans := 0;
        for j := 1 to i do
        begin
                ans := ans + fm*a[j];
                fm := fm*k;
        end;
        writeln(ans);
end.

