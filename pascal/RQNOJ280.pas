var
        n,i,j,tot,k:longint;
        a:array[1..1000] of longint;
        t:array[1..3] of longint;
begin
        readln(n);
        t[1] := 0;
        t[2] := 0;
        t[3] := 0;
        for i := 1 to n do
        begin
                readln(a[i]);
                inc(t[a[i]]);
        end;
        tot := 0;
        for i := 1 to t[1] do
        begin
                for j := t[1]+1 to t[1]+t[2] do
                if ( a[i] = 2) and (a[j] = 1) then
                begin
                        a[i] := 1;
                        a[j] := 2;
                        inc(tot);
                end;
                for j := t[1]+t[2]+1 to n do
                if ( a[i] = 3) and (a[j] = 1) then
                begin
                        a[i] := 1;
                        a[j] := 3;
                        inc(tot);
                end;
        end;
        for i := t[1]+1 to t[1]+t[2] do
        for j := t[1]+t[2]+1 to n do
        if ( a[i] = 3) and ( a[j] = 2) then
        begin
                a[i] := 2;
                a[j] := 3;
                inc(tot);
        end;
        for i := 1 to t[1] do
        for j := t[1]+1 to t[1]+t[2] do
        for k := t[1]+t[2]+1 to n do
        begin
                if ( a[i] = 2) and ( a[j] = 3) and ( a[k] = 1) then
                begin
                        a[i] := 1;
                        a[j] := 2;
                        a[k] := 3;
                        inc(tot);
                        inc(tot);
                end
                else
                if ( a[i] = 3) and ( a[j] = 1) and ( a[k] = 2) then
                begin
                        a[i] := 1;
                        a[j] := 2;
                        a[k] := 3;
                        inc(tot);
                        inc(tot);
                end;
        end;
        writeln(tot);
end.