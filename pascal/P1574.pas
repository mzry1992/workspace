var n,k,i,j,max,temp:longint;
    m,b:array[1..1000] of longint;
    f:array[0..1000] of longint;
begin
readln(n,k);
while ( n <> 0 ) and ( k <> 0 ) do
 begin
 max:=0;
 for i:= 1 to n do read(m[i]);
 for i:= 1 to n do read(b[i]);
 for i:= 1 to n - 1 do
  for j:= i to n do
   if b[i] < b[j] then
    begin
    temp:=b[i];
    b[i]:=b[j];
    b[j]:=temp;
    temp:=m[i];
    m[i]:=m[j];
    m[j]:=temp;
    end;
 f[0]:=0;
 for i:= 1 to n do
  for j:= k downto 1 do
   if f[j-1] + m[i] - b[i] * ( j - 1 ) > f[j] then
   begin
    f[j] := f[j-1] + m[i] - b[i] * ( j - 1 ) ;
    if f[j] > max then max:=f[j];
   end;
 writeln(max);
 readln(n,k);
 end;
end.