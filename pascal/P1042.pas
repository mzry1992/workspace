var i,n,m:longint;

function hw(i:longint):boolean;
var st:string;
    j:integer;
begin
str(i,st);
j:=length(st);
for i:= 1 to j div 2 do
 if st[i] <> st[j+1-i] then exit(false);
exit(true);
end;

function shu(i:longint):boolean;
var j:longint;
begin
for j:= 2 to trunc(sqrt(i)) do if i mod j = 0 then exit(false);
exit(true);
end;

function check(i:longint):boolean;
begin
if not hw(i) then exit(false);
if not shu(i) then exit(false);
exit(true);
end;

begin
readln(n,m);
i:=n;
repeat
 begin
 if i in [5,7,11] then writeln(i);
 if (( i > 100 ) and ( i < 999 )) then
  if check(i) then writeln(i);
 if (( i > 10000) and ( i < 99999 )) then
  if check(i) then writeln(i);
 if (( i > 1000000) and ( i < 9999999 )) then
  if check(i) then writeln(i);
 if (( i > 100000000) and ( i < 999999999 )) then
  if check(i) then writeln(i);
 if (( i > 11 ) and ( i < 99 )) then i:=99;
 if (( i > 1000 ) and ( i < 9999 )) then i:=9999;
 if (( i > 100000 ) and ( i < 999999 )) then i:=999999;
 if (( i > 10000000 ) and ( i < 99999999 )) then i:=99999999;
 end;
inc(i);
until i = m+1 ;
end.