var n,i,j,k,x,y,z,max,temp,la,lb:integer;
    a,b:array[1..20] of char;
    st:string;
function min(a,b:integer):integer;
begin
if a<b then exit(a);
exit(b);
end;
begin
readln(n);
for i:= 1 to n do
 begin
 readln(st);
 j:=1;
 la:=0;
 lb:=0;
 while st[j] <> ' ' do
 begin
  a[j]:=st[j];
  inc(j);
  inc(la);
 end;
 k:=j+1;
 while k <= length(st) do
 begin
  b[k-j]:=st[k];
  inc(k);
  inc(lb);
 end;
 max:=0;
 for x:= 1 to la do
  for y:= 1 to lb do
  if a[x] = b[y] then
  begin
  temp:=0;
   for z:= 1 to min(la-x+1,lb-y+1) do
   if a[x+z-1] = b[y+z-1] then inc(temp) else break;
  if temp > max then max:=temp;
  end;
 writeln(max);
 end;
end.
