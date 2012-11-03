var jc:array[0..20] of qword;
    i,j,n,k,h:longint;
    ans:int64;
begin
jc[0]:=1;
for i:= 1 to 20 do jc[i]:=jc[i-1]*i;
readln(n,k,h);
ans:=(jc[n] div jc[n-k] ) * (jc[n] div jc[n-k] );
for i:= 1 to h do
 begin
 readln(k);
 ans:=ans div jc[k];
 end;
writeln(ans);
end.