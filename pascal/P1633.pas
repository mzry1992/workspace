var testcase,testnow:integer;
    n1,n2,i,j:longint;
    s1,s2:array[0..500] of longint;
    f:array[0..500,0..500] of longint;

procedure qsort1(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l;   j:=r;   m:=s1[(i+j) div 2];
repeat
while s1[i] < m do inc(i);
while s1[j] > m do dec(j);
if i <= j then
begin
temp:=s1[i];    s1[i]:=s1[j];   s1[j]:=temp;
inc(i); dec(j);
end;
until i > j ;
if i < r then qsort1(i,r);
if l < j then qsort1(l,j);
end;


procedure qsort2(l,r:longint);
var i,j,m,temp:longint;
begin
i:=l;   j:=r;   m:=s2[(i+j) div 2];
repeat
while s2[i] < m do inc(i);
while s2[j] > m do dec(j);
if i <= j then
begin
temp:=s2[i];    s2[i]:=s2[j];   s2[j]:=temp;
inc(i); dec(j);
end;
until i > j ;
if i < r then qsort2(i,r);
if l < j then qsort2(l,j);
end;

begin
assign(input,'11.txt');
reset(input);
readln(testcase);
for testnow:= 1 to testcase do
begin
readln(n1,n2);
for i:= 1 to n1 do readln(s1[i]);
for i:= 1 to n2 do readln(s2[i]);
qsort1(1,n1);
qsort2(1,n2);
for i:= 1 to n1 do
 for j:= 1 to n2 do f[i,j]:=maxlongint;
f[0,0]:=0;
for i:= 1 to n1 do
 for j:= 1 to n2 do
 if i <= j then
  if (n1-i) <= (n2-j) then
  begin
  if i <= j-1 then
   if f[i,j] > f[i,j-1] then f[i,j]:=f[i,j-1];
   if f[i,j] > f[i-1,j-1]+abs(s1[i]-s2[j]) then f[i,j]:=f[i-1,j-1]+abs(s1[i]-s2[j]);
  end;
writeln(f[n1,n2]);
end;
close(input);
end.
