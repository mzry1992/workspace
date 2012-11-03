var i,j,n,sum,temp:longint;
begin
readln(n);
sum:=0;
for i:= 1 to n do
begin
temp:=1;
 for j:= 1 to i do
  temp:=temp*j;
sum:=sum+temp;
end;
writeln(sum);
end.