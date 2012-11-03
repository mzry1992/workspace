var i:longint;
    ch:char;
begin
i:=0;
while not eof do
 begin
 read(ch);
 inc(i);
 end;
writeln(i);
end.