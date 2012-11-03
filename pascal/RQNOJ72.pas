var
        n,i,j:longint;
        w:array[1..100] of longint;
        dp,tdp:array[0..10000] of boolean;
        sum:array[0..100] of longint;
begin
        readln(n);
        sum[0] := 0;
        for i := 1 to n do
        begin
                readln(w[i]);
                sum[i] := sum[i-1]+w[i];
        end;
        fillchar(tdp,sizeof(tdp),false);
        tdp[0] := true;
        for i := 1 to n do
        begin
                fillchar(dp,sizeof(dp),false);
                for j := 0 to sum[i] do
                        dp[j] := tdp[abs(j+w[i])] or tdp[abs(j-w[i])] or dp[j];
                tdp := dp;
        end;
        for i := 0 to sum[n] do
        if tdp[i] then
        begin
                writeln(i);
                halt;
        end;
end.
