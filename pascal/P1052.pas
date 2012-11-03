var n,i,j,k:longint;
    temp:real;
    a:array[1..100,1..100] of real;
begin
readln(n);
for i:= 1 to n do
begin
for j:= 1 to n + 1 do read(a[i,j]);
readln;
end;

for i:= 1 to n-1 do
begin
if a[i,i] = 0 then
begin
j:=i+1;
while a[j,i] = 0 do inc(j);
for k:= 1 to n+1 do
begin
temp:=a[i,k]; a[i,k]:=a[j,k]; a[j,k]:=temp;
end;
end;
for j:= i+1 to n do
begin
temp:=a[j,i];
 for k:= 1 to n+1 do
 a[j,k]:=a[j,k]-a[i,k]*(temp/a[i,i]);
end;
end;
for i:= 1 to n do
 if a[i,i] < 0 then
  for j:= i to n+1 do
   a[i,j]:=-a[i,j];

for i:= 1 to n - 1 do
 for j:= i+1 to n do
 begin
 temp:=a[i,j];
  for k:= j to n + 1 do
   a[i,k]:=a[i,k]-a[j,k]*temp/a[j,j];
 end;

for i:= 1 to n do
 if a[i,i] > 1 then
 begin
 temp:=a[i,i];
  for j:= i to n+1 do
   a[i,j]:=a[i,j]/temp;
 end;
for i:= 1 to n do
begin
if round(a[i,n+1]) = -0 then a[i,n+1]:=0;
write(round(a[i,n+1]),' ');
end;
writeln;
end.
