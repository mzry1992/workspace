var x,y,t:longint;
begin
assign(output,'table0003.txt');
rewrite(output);
t:=0;
for x:= 1 to 9 do
begin
for y:= 1 to 9 do begin inc(t); write(t,',');  end;
writeln;
end;
close(output);
end.