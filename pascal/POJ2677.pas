var mp:array[0..101,0..101] of integer;
    i,x,y,s1,s2:longint;
begin
for x:= 0 to 101 do
 for y:= 0 to 101 do mp[x,y]:=100;
s1:=0;
s2:=0;
readln(i);
for x:= 1 to i do
begin
for y:= 1 to i do read(mp[x,y]);
readln;
end;
for x:= 1 to i do
 for y:= 1 to i do
 begin
  if mp[x,y] <= 50 then inc(s1);
  if mp[x,y] <= 50 then
  if ((mp[x-1,y]<=50) and (mp[x+1,y]<=50) and (mp[x,y-1]<=50) and (mp[x,y+1]<=50)) then inc(s2);
 end;
writeln(s1,' ',s1-s2);
end.