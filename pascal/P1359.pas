var n:integer;
    a,b,st,en,i,j,time,top:longint;
    shu:array[1..1000000] of longint;

function su(i:longint):boolean;
var k,m:longint;
begin
for m:= 2 to trunc(sqrt(i)) do
  if i mod m = 0 then exit(false);
exit(true);
end;

begin
readln(n);
case n of
1 : a:= 10 ;
2 : a:= 100 ;
3 : a:= 1000 ;
4 : a:= 10000 ;
5 : a:= 100000 ;
6 : a:= 1000000 ;
7 : a:= 10000000 ;
8 : a:= 100000000 ;
end;
shu[1]:=2;
shu[2]:=3;
shu[3]:=5;
shu[4]:=7;
st:=1;
en:=4;
time:=10;
top:=4;
repeat
for i:= st to en do
 begin
 for j:= 1 to 9 do
 if su(shu[i]*10 + j) then
 begin
  inc(top);
  shu[top]:=shu[i]*10+j;
 end;
 end;
time:=time*10;
st:=en+1;
en:=top;
until time=a;
for i:= st to en do writeln(shu[i]);
end.