uses sysutils;
var mp:array[1..5,1..5] of boolean;
    n,sum,i:integer;
    us:array[0..20] of boolean;
    t0,t1:tdatetime;

procedure check;
var i,j,total:integer;
    flg:boolean;
begin
total:=0;
for i:= 1 to 5 do
begin
flg:=true;
 for j:= 1 to 5 do
  if mp[i,j] then begin flg:=false; break; end;
if flg then inc(total);
flg:=true;
 for j:= 1 to 5 do
  if mp[j,i] then begin flg:=false; break; end;
if flg then inc(total);
end;
flg:=true;
for i:= 1 to 5 do
 if mp[i,i] then begin flg:=false; break; end;
if flg then inc(total);
flg:=true;
for i:= 1 to 5 do
 if mp[i,6-i] then begin flg:=false; break; end;
if flg then inc(total);
if us[total] then us[total]:=false;
end;

procedure dfs(x,y,k:integer);
begin
if (25-5*(x-1)-y) < k  then exit;
if k = 0 then
begin
check; exit;
end;
inc(y);
if y > 5 then begin inc(x); y:=1 ; end;
if x > 5 then exit;
dfs(x,y,k);
mp[x,y]:=false;
dfs(x,y,k-1);
mp[x,y]:=true;
end;

begin
assign(output,'P1146(2).txt');
rewrite(output);
for n:= 1 to 25 do
begin
fillchar(mp,sizeof(mp),true);
fillchar(us,sizeof(us),true);
t0:=now;
dfs(1,0,n);
sum:=0;
for i:= 1 to 20 do
 if not us[i] then sum:=sum+i;
write(sum,',');
writeln;
t1:=now;
writeln((t1-t0)*86400000 :0 :10);
end;
close(output);
end.
