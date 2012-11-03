var
        n,m,i,j:longint;
        tot:int64;
        dp:array[0..50,0..5] of int64;
begin
        readln(n,m);
        fillchar(dp,sizeof(dp),0);
        dp[0,0] := 1;
        for i := 1 to n do
        begin
                for j := 0 to m-1 do
                        dp[i,0] := dp[i,0]+dp[i-1,j];
                for j := 1 to m-1 do
                        dp[i,j] := dp[i-1,j-1];
        end;
        tot := 0;
        for j := 0 to m-1 do    tot := tot+dp[n,j];
        writeln(tot);
end.