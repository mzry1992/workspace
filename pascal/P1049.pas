var n:ansistring;
    a:array[1..2000] of longint;
    i,j,qian:longint;
begin
readln(n);
qian:=0;
j:=length(n);
for i:= 1 to j do
begin
 a[i]:=ord(n[j+1-i])-ord('0');
 a[i]:=a[i]*2+qian;
 qian:=a[i] div 10;
 a[i]:=a[i] mod 10;
end;
a[j+1]:=qian;
a[1]:=a[1]-1;
i:=1;
while a[i] < 0 do
 begin
 a[i]:=a[i]+10;
 a[i+1]:=a[i+1]-1;
 inc(i);
 end;
inc(j);
while a[j] = 0 do dec(j);
for i:= j downto 1 do write(a[i]);
writeln;
end.

