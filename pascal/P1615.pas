var n,i,t,m,d:longint;
    ans:int64;
    a:array[1..100000] of longint;

function min(a,b:longint):longint;
begin
if a < b then exit(a);
exit(b);
end;

begin
readln(n);
for i:= 1 to n do read(a[i]);
ans:=0;
for i:= 2 to n - 1 do
 begin
 t:=a[i-1]; m:=a[i]; d:=a[i+1];
 if (m > t) and (m > d) then
  if m-t < m-d then
   begin
   a[i]:=t;
   ans:=ans+m-t;
   end
  else
   begin
   a[i]:=d;
   ans:=ans+m-d;
   end;
 if (m < t) and (m < d) then
  if t-m < d-m then
   begin
   a[i]:=t;
   ans:=ans+t-m;
   end
  else
   begin
   a[i]:=d;
   ans:=ans+d-m;
   end;
 end;
for i:= 2 to n do ans:=ans+abs(a[i]-a[i-1]);
writeln(ans);
end.

