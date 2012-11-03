var k,tv,n,i,j,max,total,kk,a,b,m1:longint;
    m,v:array[1..200] of longint;

procedure beibao(var tmax,k:longint);
var f:array[0..5000] of longint;
    i,j,now,t,temp:longint;
begin
fillchar(f,sizeof(f),0);
for i:= 1 to n do
 for j:= tv downto m[i] do
  if f[j] < f[j-m[i]] + v[i] then
   if f[j-m[i]] + v[i] < max then
    begin
    f[j]:=f[j-m[i]]+v[i];
    if j = tv then temp:=v[i];
    end;
now:=f[tv];
tmax:=now-temp;
t:=0;
for i:= tv downto 0 do
 if f[i] = tmax then inc(t);
for i:= 0 to tv do write(f[i],' ');
write('|',temp,'|');
tmax:=f[tv];
k:=t;
end;

function min(a,b:longint):longint;
begin
if a < b then exit(a);
exit(b);
end;

begin
readln(k,tv,n);
max:=0;
for i:= 1 to n do
begin
 readln(m[i],v[i]);
 max:=max+v[i];
end;
inc(max);
total:=0;
kk:=0;
while kk < k do
 begin
 beibao(a,b);
 max:=a;
 if kk + b <= k then
 begin
  kk:=kk+b;
  total:=total+a*b;
 end
 else
 begin
  b:=k-kk;
  kk:=k;
  total:=total+a*b;
 end;
 writeln(a,'|',b);
 end;
writeln(total);
end.
