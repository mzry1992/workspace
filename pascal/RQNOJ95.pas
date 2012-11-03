var
        m,n,mw,i,j,k,w,v:longint;
        dp:array[0..1000,0..1000] of longint;
function        max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;

begin
        readln(n,m,mw);
        fillchar(dp,sizeof(dp),0);
        for i := 0 to mw do
        for j := 1 to n do     dp[i,j] := -maxlongint;
        for i := 1 to n do
        begin
                readln(w,v);
                for j := mw downto w do
                for k := m downto 1 do
                        dp[j,k] := max(dp[j,k],dp[j-w,k-1]+v);
        end;
        if dp[mw,m] < 0 then dp[mw,m] := 0;
        writeln(dp[mw,m]);
end.
