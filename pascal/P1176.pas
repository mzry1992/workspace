var x,y,i,j:longint;
begin
readln(x);
for i:= 30 downto 0 do
begin
y:=(x and (1 shl i )) xor (( x and (1 shl(i+1))) shr 1);
x:=x and not (1 shl i ) or y;
end;
writeln(x);
end.