uses crt;
var c:char;
begin
repeat
c:=readkey;
c:=upcase(c);
case c of
'W':write('W');
'S':write('S');
end;
until 1=0;
end.

