var i,j:longint;
begin
assign(output,'11.txt');
rewrite(output);
writeln(20);
for j:= 1 to 20 do
begin
writeln(500,' ',500);
for i:= 1 to 500 do
 writeln(i);
for i:= 1 to 500 do
 writeln(i+1);
end;
close(output);
end.