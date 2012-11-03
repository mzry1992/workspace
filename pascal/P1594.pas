var n,v,k,i,j:integer;
    f:array[0..100,0..200] of longint;
    a:array[1..100] of integer;

function max(a,b:integer):integer;
begin
if a > b then exit(a);
exit(b);
end;

begin
fillchar(f,sizeof(f),0);
readln(n,v,k);
for i:= 1 to n-1 do read(a[i]);
f[n-1,v]:=v;
if ( f[n-1,v] >= a[n-1] ) and ( f[n-1,v] <= a[n-1]+k ) then
begin
for i:= n-2 downto 1 do
 for j:= a[i] to a[i] + k do
 if ( ( f[i+1,j] <> 0 ) or ( f[i+1,j+1] <> 0 ) or ( f[i+1,j-1] <> 0 ) ) then
  f[i,j]:=max(max(f[i+1,j],f[i+1,j-1]),f[i+1,j+1])+j
 else f[i,j]:=0;
i:=0;
for j:= a[1] to a[1] + k do
 if f[1,j] > i then i:=f[1,j];
end
else i:= 0 ;
if i <> 0 then writeln(i/(n-1):0:2)
else writeln('REN JIU SHI BU NENG REN CI!');
end.