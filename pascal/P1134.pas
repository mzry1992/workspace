var a:array[1..4] of integer;
    i,n,m,x:longint;
    canuse:array[1..4] of boolean;
    flg:boolean;

procedure dfs(dep:integer;sum:real);
var i,j:integer;
    y,z:integer;
begin
if dep = 4 then
begin
if ( trunc(sum) div x > 0 ) and ( trunc(sum) div x < 10 ) then
begin
 if sum > 0 then
 if abs((frac( sum / 100 )) * 100 - m ) < 1E-4 then
  begin
  flg:=false;
  end;
 if sum < 0 then
 if abs((frac( sum / 100 )) * 100 + m ) < 1E-4 then
  begin
  flg:=false;
  end;
end;
exit;
end;
for i:= 1 to 4 do
 if canuse[i] then
  begin
  canuse[i]:=false;
  if sum <> 0 then dfs(dep+1,a[i] / sum ) ;
  dfs(dep+1,a[i]-sum);
  dfs(dep+1,sum+a[i]);
  dfs(dep+1,sum-a[i]);
  dfs(dep+1,sum*a[i]);
  dfs(dep+1,sum / a[i] );
  canuse[i]:=true;
  end;
end;


begin
readln(a[1],a[2],a[3],a[4]);
readln(n);
if n <> 1 then
begin
readln(m);
while n <> 1 do
begin

x:=1;
for i:= 1 to n-1 do
 x:=x*10;

flg:=true;

for i:= 1 to 4 do
 begin
 fillchar(canuse,sizeof(canuse),true);
 canuse[i]:= false ;
 dfs(1,a[i]);
 end;

if flg then
writeln(0)
else writeln(1);

readln(n);
if n <> 1 then
readln(m);
end;
end;
end.
