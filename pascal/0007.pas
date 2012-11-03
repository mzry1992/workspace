VAR N,i:longint;
    g:array[0..1000] of longint;
begin
assign(output,'table.txt');
rewrite(output);
g[0]:=0;
i:=0;
for n:= 1 to 200 do
begin
g[n]:=n-g[g[n-1]];
if n >= 4 then
begin
inc(i);
write(g[n]/n:0:5,' ');
if i mod 12 = 0 then writeln;
end;
end;
close(output);
end.