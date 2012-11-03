var x,y:longint;
begin
write('(');
for x:= 1 to 9 do
begin
 for y:= 1 to 9 do write('(',x,',',y,'),');
writeln;
end;
end.