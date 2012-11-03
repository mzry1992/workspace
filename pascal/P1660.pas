var
        n,i:longint;
        b:array[1..2000] of longint;
        use:array[1..2000] of longint;
        count:array[0..200] of byte;
procedure dfs(dep:byte);
var
        i:longint;
begin
        if dep = n+1 then
        begin
                i := 1;
                inc(count[i]);
                while (count[i] >= 10) and (i <= count[0]) do
                begin
                        count[i+1] := count[i+1]+count[i] div 10;
                        count[i] := count[i] mod 10;
                        inc(i);
                end;
                if count[count[0]] > 10 then
                begin
                        inc(count[0]);
                        count[count[0]] := count[count[0]-1] div 10;
                        count[count[0]-1] := count[count[0]-1] mod 10;
                end;
                exit;
        end;
        for i := 1 to n do
        if
        if not use[i] then
        begin
                use[i] :=
begin
        readln(n);
        for i := 1 to n do      read(b[i]);
        readln;
        count[0] := 1;
        count[1] := 0;
        fillchar(use,sizeof(use),false);
        dfs(1);
end.