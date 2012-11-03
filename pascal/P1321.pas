var i,n,j,m,x,y,z:longint;
    mp:array[1..5000,1..5000] of longint;
    wq,vis:array[1..50000] of boolean;

procedure dfs(i:longint);
var x,y:longint;
begin
for x:= 1 to n do
 if mp[i,x] > 0 then
  if (wq[mp[i,x]]) and ( not vis[x] ) then
  begin
  vis[x]:=true;
  wq[x]:=true;
  dfs(x);
  end;
end;


begin
readln(n,j,m);
fillchar(vis,sizeof(vis),false);
fillchar(mp,sizeof(mp),0);
vis[j]:=true;

for i:= 1 to n do
begin
readln(x,y,z);
mp[x,y]:=z;
mp[y,x]:=z;
end;

fillchar(wq,sizeof(wq),false);
wq[j]:=true;
dfs(j);
for x:= 1 to n do
 if vis[x] then writeln(x,':Yes')
 else writeln(x,':No');

end.