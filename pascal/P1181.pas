const tt:array[1..8] of longint = (9
,189
,2889
,38889
,488889
,5888889
,68888889
,788888889);

var   n,i,k,j,m:longint;
      st:ansistring;
begin
readln(n);
if n < 10 then begin writeln(n) ;  halt; end;
m:=8;
while n <= tt[m] do dec(m);
k:=9; i:=0;
for j:= 1 to m do
begin
i:=i+k;
k:=k*10;
end;
k:=tt[m];
while true do
begin
inc(i);
str(i,st);
j:=length(st);
if j+k >= n then
 begin
 writeln(st[n-k]);
 halt;
 end;
k:=k+j;
end;
end.
