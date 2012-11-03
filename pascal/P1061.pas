var n,m,i,j,k:longint;
    a:array[0..5100] of longint;
    f:array[0..5100,0..1100] of longint;
function min(a,b:longint):longint;
begin
if a=-1 then exit(b);
if b=-1 then exit(a);
if a < b then exit(a);
exit(b);
end;
begin
fillchar(f,sizeof(f),0);
readln(m,n);
for i:= 1 to n do read(a[i]);
for i:= n downto 1 do
 for j:= 1 to m do
  if n-i+1 >= j*3 then
   f[i,j]:=min(f[i+1,j],f[i+2,j-1]+sqr(a[i+1]-a[i]))
   else begin f[i,j]:=-1;break;end;
writeln(f[1,m]);
end.

