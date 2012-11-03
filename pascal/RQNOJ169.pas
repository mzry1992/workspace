var
        cost:array[1..10] of longint;
        dist,i,j:longint;
        dp:array[0..100] of longint;
function        min(a,b:longint):longint;
begin
        if a < b then   exit(a);
        exit(b);
end;
begin
        for i := 1 to 10 do     read(cost[i]);
        readln;
        readln(dist);
        dp[0] := 0;
        for i := 1 to dist do
        begin
                dp[i] := maxlongint;
                for j := 1 to 10 do
                        dp[i] := min(dp[i],dp[i-j]+cost[j]);
        end;
        writeln(dp[dist]);
end.
