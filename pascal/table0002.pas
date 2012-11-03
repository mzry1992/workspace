var z,x,y:longint;
begin
assign(output,'table0002.txt');
rewrite(output);
for x:= 1 to 3 do
 for z:= 1 to 3 do
  for y:= 1 to 3 do write(z,',');
writeln;
for x:= 1 to 3 do
 for z:= 4 to 6 do
  for y:= 1 to 3 do write(z,',');
writeln;
for x:= 1 to 3 do
 for z:= 7 to 9 do
  for y:= 1 to 3 do write(z,',');
writeln;
close(output);
end.