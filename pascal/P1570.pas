var n,m,k,i,kk,max,maxa:longint;
    a:array[1..10000] of integer;
    f:array[1..10000] of longint;
begin
readln(n);
maxa:=0;
for m:= 1 to n do begin read(a[m]);  if a[m] > maxa then maxa:=a[m] ; end;
max:=0;
for k:= 1 to n - 1 do
if ( n / k * maxa ) > max then
begin
fillchar(f,sizeof(f),0);
 for i:= 1 to n do
 begin
  if ( i - k ) > 0 then
   if f[i] < f[i-k] + a[i] then
    f[i]:=f[i-k]+a[i];
   if f[i] < a[i] then
    f[i]:=a[i];
  if f[i] > max then
  begin
  kk:=k;
  max:=f[i];
  end;
 end;
end;
writeln(max,' ',kk);
end.
