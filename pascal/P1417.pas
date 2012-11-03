var tt,x,y,z,n,r,g,b,t,gg,i,tt2,tt3:longint;
    max:longint;
begin
readln(n,r,g,b,t);
max:=0;
for x:= 0 to n - 1 do
 for y:= 0 to n do
 if x + y <= n then
  begin
  z:=n-x-y;
  tt:=(r+g*y)*(t+x*b)*z+(y*(y-1) div 2 )*g*(t+x*b);
  tt2:=(r+g*y)*(t+x*b)*z+(y*(y-1) div 2 )*g*t;
  tt3:=r*(t+x*b)+(y*(y-1) div 2)*g*(t+x*b);
  writeln(tt,' ',tt2,' ',tt3,' ',x,' ',y,' ',z);
  end;
end.
