var km,i,ikm,c,oi,min:real;
    x,y,n:integer;
    a,b:array[0..50] of real;

procedure dfs(dep:integer;oil,cost,now:real);
var toil:real;
begin
if dep > n  then
begin
writeln(cost:0:1);
if cost < min then min:=cost;
exit;
end;
toil:=oil-(a[dep]-now)/ikm;
if toil - (a[dep+1]-a[dep])/ikm <= 0 then
 dfs(dep+1,i,cost+(i-toil)*b[dep]+20,a[dep])
else
begin
if toil - (a[dep+1]-now)/ikm >= i/2 then
 dfs(dep+1,toil,cost,now)
else
 begin
 dfs(dep+1,toil,cost,now);
 dfs(dep+1,i,cost+(i-toil)*b[dep]+20,a[dep]);
 end;
end;
end;

begin
readln(km);
readln(i,ikm,c,n);
a[0]:=0; b[0]:=c/i;
a[n+1]:=km; b[n+1]:=0;
for x:= 1 to n do readln(a[x],b[x]);
min:=1e38;
dfs(1,i,c,0);
writeln(min:0:1);
end.