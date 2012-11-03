var s1,s2,a,b,c:integer;
begin
for a:= 1 to 9 do
 for b:= 0 to 9 do
  for c:= 0 to 9 do
   begin
   s1:=a*100+b*10+c;
   s2:=a*a*a+b*b*b+c*c*c;
   if s1 = s2 then writeln(s1);
   end;
end.