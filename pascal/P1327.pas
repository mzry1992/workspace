var n,i,j:integer;
    a:array[1..5000] of char;
    f:array[1..5000,0..5000] of integer;
begin
readln(n);
fillchar(f,sizeof(f),0);
for i:= 1 to n do read(a[i]);
for j:= 1 to n-1 do
 for i:= 1 to n-j do
  begin
  if a[i] = a[i+j] then f[i,j]:=f[i+1,j-2];
  if a[i] <> a[i+j] then
   begin
   if f[i+1,j-1] > f[i,j-1] then
    f[i,j]:=f[i,j-1]+1
   else f[i,j]:=f[i+1,j-1] + 1 ;
   end;
  end;
writeln(f[1,n-1]);
end.
