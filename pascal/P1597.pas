var n,i,j,k,t:longint;
    ff:array[0..20001] of string;
    a,b:array[1..20000] of longint;
    st:ansistring;

function min(a,b:longint):longint;
begin
if a < b then exit(a);
exit(b);
end;

function f(n:longint):ansistring;
var str:ansistring;
begin
if ff[n] <> '' then exit(ff[n]);
str:='2('+f(b[n])+')';
if n - a[n] > 0 then str:=str+'+'+f(n-a[n]);
ff[n]:=str;
exit(str);
end;

begin
readln(n);
for i:= 0 to n do ff[i]:='';
ff[1]:='2(0)';
ff[2]:='2';
ff[3]:='2+2(0)';
ff[4]:='2(2)';
i:=1;
j:=2;
t:=0;
repeat
for k:= i to min(j-1,n) do begin a[k]:=i ; b[k]:=t ; end ;
i:=j;
j:=j*2;
inc(t);
until j div 2 > n ;
writeln(f(n));
end.