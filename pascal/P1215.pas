var x,y,z,k,l,t:longint;
    f:array[0..16,0..16] of int64;
    ans:int64;
begin
readln(k,l);
fillchar(f,sizeof(f),0);
for x:= 1 to k - 1 do
 f[1,x]:=1;
for x:= 2 to l do
 for y:= 0 to k - 1 do
  for z:= 0 to k - 1 do
   if ( z <> y - 1 ) and ( z <> y + 1 ) then
    f[x,z]:=f[x,z]+f[x-1,y];

ans:=0;
for y:= 0 to k - 1 do ans:=ans+f[l,y];
writeln(ans);
for x:= 1 to l do
begin
 for y:= 0 to k - 1 do write(f[x,y]);
writeln;
end;
end.
