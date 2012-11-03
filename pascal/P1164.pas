var a,b:array[1..10] of longint;
    n,i:longint;
    c,d:int64;
begin
readln(n);
for i:= 1 to n do
 readln(a[i],b[i]);
c:=b[1];
d:=a[1];
for i:= 2 to n do
begin
while c mod a[i] <> b[i] do
 inc(c,d);
d:=d*a[i];
end;
writeln(c);
end.