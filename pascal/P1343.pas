var x,y:longint;
begin
readln(x,y);
if x mod y = 0 then
begin
writeln(x div y ) ;
halt;
end;
write(x div y );
x:= x mod y ;
writeln(x,' ',y);
end.
