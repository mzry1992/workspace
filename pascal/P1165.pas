var n,i,j:longint;
    a,b:array[1..100000] of int64;
    tot,l,r,ll,rr:int64;

procedure qsort(l,r:longint);
var i,j,m:longint;
    temp:int64;
begin
m:=a[(l+r) div 2];
i:=l;
j:=r;
repeat
while a[i] < m do inc(i);
while a[j] > m do dec(j);
if i <= j then
 begin
 temp:=a[i];
 a[i]:=a[j];
 a[j]:=temp;
 temp:=b[i];
 b[i]:=b[j];
 b[j]:=temp;
 inc(i);
 dec(j);
 end;
until i > j ;
if l < j then qsort(l,j);
if r > i then qsort(i,r);
end;

begin
readln(n);
for i:= 1 to n do readln(a[i],b[i]);
qsort(1,n);
tot:=0;
l:=a[1];
r:=a[1];
i:=1;
for i:= 1 to n do writeln(a[i],' ',b[i]);
for i:= 1 to n do
begin
ll:=a[i];
rr:=b[i];
if ( ll >= l ) and ( ll <= r ) then
 if rr > r then r:=rr;
if ll > r then
 begin
 tot:=tot+r-l;
 r:=rr;
 l:=ll;
 end;
end;
writeln(tot+r-l);
end.