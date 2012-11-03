var i,j,k,n,m,total,fornumber:integer;
    a:array[1..50] of longint;
    mp:array[0..51,0..51] of boolean;

begin
readln(total);
for fornumber:= 1 to total do
begin
fillchar(mp,sizeof(mp),false);

readln(n,m);

for i:= 1 to n-1 do read(a[i]);
readln;

for i:= 1 to m do
begin
readln(x,y);
mp[x,y]:=true;
end;

for k:= 0 to n do
 for i:= 0 to n do
  for j:= 0 to n do
   if mp[i,k] and mp[i,j] then mp[i,j]:=true;

if mp[0,n] then


end;

end.