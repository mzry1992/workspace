var x,y,i,j,f:longint;
    s,p,q:array[1..100] of longint;
begin
fillchar(p,sizeof(p),0);
fillchar(q,sizeof(q),0);
fillchar(s,sizeof(s),0);
readln(x,y);
write(x div y);
x:=x mod y;
if x = 0 then begin writeln; halt; end;
i:=0;    write('.');  f:=100;
while i < 100 do
 begin
 inc(i);
 x:=x*10;
 s[i]:=(x div y);
 x:=x mod y;
 p[i]:=s[i];
 q[i]:=x;
 if x = 0 then begin f:=i; break; end;
 end;
if f = 100 then
for x:= 1 to 99 do
 for y:= x+1 to 100 do
  if p[x] = p[y] then
   if q[x] = q[y] then
    begin
    if x > 1 then
     for i:= 1 to x-1 do write(s[i]);
    write('(');
    for i:= x to y-1 do write(s[i]);
    writeln(')');
    halt;
    end;
for i:= 1 to f do write(s[i]);
writeln;
end. 