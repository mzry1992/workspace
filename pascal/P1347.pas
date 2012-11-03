var n,kk,i,j,k:integer;
    f:array[1..40,0..6] of longint;
    num:array[1..40,1..40] of longint;
    st,temp:string;
begin
readln(n,kk);
readln(st);
for i:= 1 to n do
 for j:= i to n do
  begin
  temp:=copy(st,i,j-i+1);
  val(temp,num[i,j],k);
  end;
fillchar(f,sizeof(f),0);
for i:= 1 to n do
 f[i,0]:=num[1,i];
for i:= 1 to n do
 for j:= 1 to kk do
  for k:= j to i-1 do
   if f[i,j] < f[k,j-1]*num[k+1,i] then
    f[i,j]:=f[k,j-1]*num[k+1,i];
writeln(f[n,kk]);
end.