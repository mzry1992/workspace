var i,top,n,atop:longint;
    a,ans:array[1..10000] of longint;
procedure cheng(b:longint);
var i,qian:longint;
begin
qian:=0;
for i:= 1 to 1000 do
begin
ans[i]:=ans[i]*b+qian;
qian:=ans[i] div 10;
ans[i]:=ans[i] mod 10;
end;
end;
begin
fillchar(ans,sizeof(ans),0);
readln(n);
i:=1; top:=0;
repeat
inc(i);
inc(top);
a[top]:=i;
n:=n-i;
until n < 0 ;
n:=n+a[top]; dec(top);
i:=top;
if n  > 0 then
repeat
dec(n);
inc(a[i]);
dec(i);
if i = 0 then i:=top;
until n = 0 ;
ans[1]:=1;
for i:= 1 to top do
begin
write(a[i],' ');
cheng(a[i]);
end;
writeln;
atop:=1000;
while ans[atop] = 0 do dec(atop);
for i:= atop downto 1 do write(ans[i]);
writeln;
end.
