type
        num = array[0..100] of longint;
var
        dp:array[0..61,0..61,0..61] of num;
        i,j,k,n:longint;
        zero:num;
function        max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
function        jia(a,b:num):num;
var
        temp:num;
        i,j:longint;
begin
        fillchar(temp,sizeof(temp),0);
        temp[0] := max(a[0],b[0]);
        j := 0;
        for i := 1 to temp[0] do
        begin
                temp[i] := a[i]+b[i]+j;
                j := temp[i] div 10000;
                temp[i] := temp[i] mod 10000;
        end;
        while j > 0 do
        begin
                inc(temp[0]);
                temp[temp[0]] := j mod 10000;
                j := j div 10000;
        end;
        exit(temp);
end;
procedure       outpp(i:longint);
begin
        if (1000 <= i ) and (i < 10000) then    begin   write(i);   exit;   end;
        if (100  <= i ) and (i < 1000 ) then    begin   write('0',i);   exit;   end;
        if (10   <= i ) and (i < 100  ) then    begin   write('00',i);   exit;   end;
        if (0    <= i ) and (i < 10   ) then    begin   write('000',i);   exit;   end;
end;
procedure       outp(a:num);
var
        i:longint;
begin
        write(a[a[0]]);
        for i := a[0]-1 downto 1 do       outpp(a[i]);
        writeln;
end;
begin
        zero[0] := 1;
        zero[1] := 0;
        readln(n);
        inc(n);
        for i := 1 to n-2 do
        for j := i+1 to n-1 do
        for k := j+1 to n do
                dp[i,j,k] := zero;
        zero[1] := 1;
        dp[0,0,0] := zero;
        dp[1,0,0] := zero;
        dp[1,1,0] := zero;
        dp[1,1,1] := zero;
        for i := 1 to n do
        for j := 1 to i do
        for k := 1 to j do
                dp[i,j,k] := jia(jia(dp[i-1,j,k],dp[i,j-1,k]),dp[i,j,k-1]);
        outp(dp[n,n,n]);
end.