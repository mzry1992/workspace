var
        st,s1,s2:string;
        dp:array[0..100,0..100] of longint;
        i,j:longint;
function        min(a,b:longint):longint;
begin
        if a > b then   exit(b);
        exit(a);
end;

begin
        while   not eof do
        begin
                readln(st);
                s1 := copy(st,1,pos(' ',st)-1);
                s2 := copy(st,pos(' ',st)+1,length(st)-pos(' ',st));
                fillchar(dp,sizeof(dp),$127);
                for i := 1 to 100 do
                begin
                        dp[i,0] := i;
                        dp[0,i] := i;
                end;
                dp[0,0] := 0;
                for i := 1 to length(s1) do
                for j := 1 to length(s2) do
                begin
                        dp[i,j] := min(dp[i-1,j],dp[i,j-1])+1;
                        if s1[i] = s2[j] then
                        dp[i,j] := min(dp[i,j],dp[i-1,j-1]+1);
                end;
                writeln(dp[length(s1),length(s2)]);
        end;
end.

