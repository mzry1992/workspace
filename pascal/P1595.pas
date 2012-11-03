var n:longint;
    g:array[1..1000,1..1000] of boolean;
    dfsend,order,cd:array[1..1000] of longint;
    visit:array[1..1000] of boolean;
    i,j,k,cd0,rd0:longint;

procedure dfs1(i:longint);
var j:longint;
begin
visit[i]:=true;
for j:= 1 to n do
if g[i,j] and (not visit[j]) then dfs1(j);
inc(k);
dfsend[i]:=k;
end;

procedure dfs2(i:longint);
var j:longint;
begin
visit[i]:=false;
for j:= 1 to n do
if g[i,j] and (visit[j]) then begin inc(cd[i]) ; dfs2(j); end;
if cd[i] = 0 then inc(cd0);
end;

begin
readln(n);
for i:= 1 to n-1 do
begin
read(j);
while j <> 0 do
begin
g[i,j]:=true;
read(j);
end;
end;
fillchar(visit,sizeof(visit),false);
k:=0;
for i:= 1 to n do
if not visit[i] then
dfs1(1);
for i:= 1 to n do
order[n-dfsend[i]+1]:=i;
k:=0;
fillchar(cd,sizeof(cd),0);
for i:= 1 to n do
if visit[i] then
begin
inc(rd0);
inc(k);
dfs2(i);
end;
writeln(rd0);
writeln(cd0,' ',rd0);
end.