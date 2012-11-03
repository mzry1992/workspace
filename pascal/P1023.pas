var n,i,j,x,y,z,k:longint;
    mp:array[1..200,1..200] of boolean;
    ok:array[1..200] of boolean;

procedure dfs(i:longint);
var j:longint;
begin
ok[i]:=false;
for j:= 1 to n do
 if ok[j] and mp[i,j] then dfs(j);
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
k:=0;
fillchar(ok,sizeof(ok),true);
for x:= 1 to n do
 if ok[x] then
  begin
  dfs(x);
  inc(k);
  end;
writeln(k);
end.
