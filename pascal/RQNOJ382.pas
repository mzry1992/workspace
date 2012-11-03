var
        dp:array[0..10,0..10,0..10] of int64;
        n,i,j,k:longint;
begin
        fillchar(dp,sizeof(dp),0);
        dp[0,0,0] := 1;
        dp[1,0,0] := 1;
        dp[1,1,0] := 1;
        dp[1,1,1] := 1;
        readln(n);
        inc(n);
        for i := 1 to n do
        for j := 1 to i do
        for k := 1 to j do
                dp[i,j,k] := dp[i-1,j,k]+dp[i,j-1,k]+dp[i,j,k-1];
        writeln(dp[n,n,n]);
end.