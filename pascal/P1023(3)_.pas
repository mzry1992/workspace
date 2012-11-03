var n,i,j,x,y,z:longint;
    mp:array[1..200,1..200] of boolean;
    use,ok:array[1..200] of boolean;

procedure dfs(dep:integer);
var x,y:integer;
    temp:array[1..200] of boolean;
    flg:boolean;
begin
if dep = i then
begin
flg:=true;
for x:= 1 to n do if not ok[x] then flg:=false;
if flg then
 begin
 writeln(i);
 halt;
 end;
exit;
end;
for x:= 1 to n do temp[x]:=ok[x];
for x:= 1 to n do
 if not use[x] then
  begin
  use[x]:=true;
  for y:= 1 to n do
   if mp[x,y] then ok[y]:=true;
  dfs(dep+1);
  use[x]:=false;
  for y:= 1 to n do ok[y]:=temp[y];
  end;
end;


begin
readln(n);
fillchar(mp,sizeof(mp),false);
for i:= 1 to n do
 begin
 read(j);
 mp[i,i]:=true;
 while j <> 0 do
  begin
  mp[i,j]:=true;
  read(j);
  end;
 end;
for i:= 1 to 2 do
 for x:= 1 to n do
  for y:= 1 to n do
   for z:= 1 to n do
    if ( mp[x,z] and mp[z,y] ) then mp[x,y]:=true;

for i:= 1 to n do
begin
fillchar(use,sizeof(use),false);
fillchar(ok,sizeof(ok),false);
dfs(0);
end;

writeln('  1 2 3 4 5 6 7 8 9');
for i:= 1 to n do
begin
write(i,' ');
 for j:= 1 to n do write(ord(mp[i,j]));
writeln;
end;

end.
