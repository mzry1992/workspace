program x1;
var n,min,max,a,b,c,d:integer;
begin
readln(n);
n:=n*10;
max:=0;
min:=maxint;
for a:= 0 to n div 6 do
 for b:= 0 to (n-6*a) div 7 do
  for c:= 0 to (n-6*a-7*b) div 8 do
   for d:= 0 to (n-6*a-7*b-8*c) div 9 do
    if a*6+b*7+c*8+d*9 = n then
    begin
     if (a+b+c+d) > max then
      max:= a+b+c+d;
     if (a+b+c+d) < min then
      min:= a+b+c+d;
    end;
writeln('Zuiduo=',max);
writeln('Zuishao=',min);
end.