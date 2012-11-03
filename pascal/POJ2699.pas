var n,i,x,y:longint;
begin
readln(n);
for i:= 10 to n do
 begin
 x:= i div 10 ;
 y:= i mod 10 ;
 if i mod (x+y) = 0 then writeln(i);
 end;
end.