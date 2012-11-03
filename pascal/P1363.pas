var n,i,j,k,time:longint;
    ch:char;
    st,temp:string;
    a:array[1..100] of 1..4;
    b:array[1..100] of longint;
    f:array[1..500] of longint;

procedure cheng(k:longint);
var i,qian:longint;
begin
qian:=0;
for i:= 1 to 500 do
begin
f[i]:=f[i]*k+qian;
qian:=f[i] div 10;
f[i]:=f[i] mod 10;
end;
end;

begin
readln(n);
for i:= 1 to n do
begin
read(ch);
a[i]:=ord(ch)-ord('A')+1;
end;
readln;
for i:= 1 to n do
begin
readln(st);
j:=-1; k:=-1; time:=0;
repeat
k:=k+2; j:=k;
while st[k] <> '%' do inc(k);
inc(time);
until time = a[i];
temp:=copy(st,j,k-j);
val(temp,b[i]);
end;
fillchar(f,sizeof(f),0); f[1]:=1;
time:=0;
for i:= 1 to n do
begin
if b[i] = 0 then
 begin
 writeln('0');
 halt;
 end;
if b[i] = 100 then inc(time);
if b[i] in [1..100] then
 cheng(b[i]);
end;
if time = n then
begin
writeln('1');
halt;
end;
n:=2*n;
i:=500;
while f[i] = 0 do dec(i);
k:=1;
while f[k] = 0 do inc(k);
dec(k);
write('0.');
for j:= 1 to (n-k)-(i-k) do write('0');
for j:= i downto k+1 do write(f[j]);
writeln;
end.