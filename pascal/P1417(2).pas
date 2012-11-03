var tt,x,y,z,n,r,g,b,t,gg,i,max:longint;
begin
readln(n,r,g,b,t);
max:=0;
for x:= 0 to n - 1 do
 for y:= 0 to n do
  begin
  tt:=0;
  z:=n-x-y;
  t:=t+x*b;
  if y > 0 then
   begin
   gg:=0;
   i:=0;
   repeat
   tt:=tt+gg*t;
   inc(i);
   gg:=gg+g;
   until i = n ;
   tt:=tt+gg*t*z;
   end;
  tt:=tt+r*t*z;
  if tt > max then max := tt;
  end;
writeln(max);
end.
