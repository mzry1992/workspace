var n:longint;
    g:array[0..1000] of longint;
begin
g[0]:=0;
for n:= 1 to 100 do
begin
 g[n]:=n-g[g[n-1]];
 write('g[',n,']=',g[n]);
if n mod 5 = 0 then writeln;
end;
end.