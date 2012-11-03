var
        s1,s2:ansistring;
        k,i,j,l1,l2:longint;
        dp:array[0..2000,0..2000] of longint;
function        min(a,b:longint):longint;
begin
        if a < b then   exit(a);
        exit(b);
end;
begin
        readln(s1);     l1 := length(s1);
        readln(s2);     l2 := length(s2);
        readln(k);
        fillchar(dp,sizeof(dp),$127);
        for i := 1 to 2000 do
        begin
                dp[i,0] := i*k;
                dp[0,i] := i*k;
        end;
        dp[0,0] := 0;
        for i := 1 to l1 do
        for j := 1 to l2 do
        begin
                dp[i,j] := min(dp[i-1,j],dp[i,j-1])+k;
                dp[i,j] := min(dp[i,j],dp[i-1,j-1]+abs(ord(s1[i])-ord(s2[j])));
        end;
        writeln(dp[l1,l2]);
end.
