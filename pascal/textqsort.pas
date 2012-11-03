uses sysutils,crt;
var a:array[1..1000000] of longint;
    t,n,i,j,k:longint;
    t0,t1:tdatetime;

procedure qsort(l,r:longint);
var i,j,k,temp:longint;
begin
i:=l;
j:=r;
k:=a[(i+j) div 2];
repeat
while a[i] < k do inc(i);
while a[j] > k do dec(j);
if i <= j then
 begin
 inc(t);
 temp:=a[i];
 a[i]:=a[j];
 a[j]:=temp;
 inc(i);
 dec(j);
 end;
until i > j ;
if l < j then qsort(l,j);
if i < r then qsort(i,r);
end;

procedure swapsort;
var tt:tdatetime;
begin
for i:= 1 to n-1 do
 for j:= i to n do
  if a[i] > a[j] then
   begin
   tt:=now;
   if ( tt - t0 ) * 86400 > 5 then
    begin
    writeln('Test Over 5 second!');
    writeln('-------------Ssort-------------');
    writeln('Swap Time:');
    writeln(t);
    writeln('Time:');
    writeln((tt-t0)*8640000 :0:10,'ms');
    writeln('-------------------------------');
    writeln;
    exit;
    end;
   inc(t);
   k:=a[i];
   a[i]:=a[j];
   a[j]:=k;
   end;
end;

begin
Assign(output,'out.txt');
rewrite(output);
Clrscr;
n:=5;
repeat
writeln('N = ',n);
writeln('Test Begin');
for i:= 1 to n do
 a[i]:= n + 1 - i ;
t:=0;
t0:=now;
writeln('Test Qsort...');
qsort(1,n);
t1:=now;
writeln('-------------Qsort-------------');
writeln('Swap Time:');
writeln(t);
writeln('Time:');
writeln((t1-t0)*8640000 :0:10,'ms');
writeln('-------------------------------');
for i:= 1 to n do
 a[i]:= n + 1 - i ;
t:=0;
t0:=now;
writeln('Test Ssort...');
swapsort;
t1:=now;
if (t1-t0)*86400 < 5  then
begin
writeln('-------------Ssort-------------');
writeln('Swap Time:');
writeln(t);
writeln('Time:');
writeln((t1-t0)*8640000 :0:10,'ms');
writeln('-------------------------------');
writeln;
end;
n:=n*10 ;
until n> 1000000 ;
writeln('End Test');
close(output);
end.
