var f:array[0..5000] of longint;
    a:array[0..5000] of char;
    st:ansistring;
    n,i:longint;
begin
readln(st);
repeat
n:=length(st);
a[0]:='9';  f[0]:=1;
for i:= 1 to n do a[i]:=st[i];
for i:= 1 to n do
begin
if a[i] = '0' then
 f[i]:=f[i-2]
else
 if (a[i-1] = '1') or ((a[i-1] = '2' ) and ( a[i] <= '6' )) then
  f[i]:=f[i-1]+f[i-2]
 else
 f[i]:=f[i-1];
end;
writeln(f[n]);
readln(st);
until st = '0';
end.

