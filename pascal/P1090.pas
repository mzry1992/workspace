var n,k,i,j:longint;
    s:array[0..500000] of longint;
    b:array[0..100000] of longint;
    total:int64;
begin
readln(n,k);
s[0]:=0;
b[0]:=1;
for i:= 1 to n do
 begin
 readln(j);
 s[i]:=s[i-1]+j;
 inc(b[s[i] mod k ]);
 end;
total:=0;
for i:= 0 to k do
if b[i] >= 2 then
 total := total+ ( b[i] * (b[i]-1) ) div 2 ;
writeln(total mod 1234567);
end.
