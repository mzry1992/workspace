var a,b,c,d,e,n:longint;
    sum:double;
begin
readln(n);
a:=1;
b:=2;
sum:=0;
for e:= 1 to n do
begin
sum := sum + b/a ;
c := b+a ;
a := b ;
b := c ;
end;
writeln(sum:0:4);
writeln(2/1+3/2+5/3+8/5+13/8+21/13);
end.