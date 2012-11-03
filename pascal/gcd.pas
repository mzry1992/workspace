var x,y,total,i,j:longint;

function gcd(a,b:longint):longint;
begin
if b = 0 then exit(a);
exit(gcd(b,a mod b));
end;

begin
readln(x,y);
total:=0;
for i:= x to y do
 for j:= x to y do
  if i*j = x*y then
   if gcd(i,j) = x then inc(total);
writeln(total);
end.
