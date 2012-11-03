var n,m,i,min:longint;
    l,r,w:array[1..3000] of longint;
    b:array[1..5000] of boolean;

procedure dfs(dep,now:longint);
var i,j,time:longint;
begin

if dep > m then
begin
if now < min then min:=now;
exit;
end;

time:=0;
for i:= l[dep] to r[dep] do
if not b[i] then inc(time);

if time > w[dep] then exit;

if time = w[dep] then begin dfs(dep+1,now); exit; end;

if time < w[dep] then
begin
for i:= l[dep] to r[dep] do
if b[i] then
begin
b[i]:=false; dfs(dep,now+1); b[i]:=true;
end;
end;

end;

procedure qsort(ll,rr:longint);
var i,j,k,temp:longint;
begin
i:=ll;
j:=rr;
k:=l[(i+j) div 2];
repeat
while l[i] < k do inc(i);
while l[j] > k do dec(j);
if i <= j then
 begin
 temp:=l[i]; l[i]:=l[j]; l[j]:=temp;
 temp:=r[i]; r[i]:=r[j]; r[j]:=temp;
 temp:=w[i]; w[i]:=w[j]; w[j]:=temp;
 inc(i);
 dec(j);
 end;
until i > j ;
if ll < j then qsort(ll,j);
if i < rr then qsort(i,rr);
end;

begin
readln(n,m);
fillchar(b,sizeof(b),true);
for i:= 1 to m do readln(l[i],r[i],w[i]);
qsort(1,m);
min:=5000;
dfs(1,0);
writeln(min);
end.

