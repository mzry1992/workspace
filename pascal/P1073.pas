var k,temp,n,step,total,ans:longint;
begin
readln(n);
temp:=1;
step:=0;
total:=1;
for k:= 1 to n do
 begin
 inc(step);
 ans:=(ans+temp) mod 10000 ;
 if step = total then
  begin
  inc(total);
  step:=0;
  temp:=(temp*2) mod 10000 ;
  end;
 end;
writeln(ans);
end.