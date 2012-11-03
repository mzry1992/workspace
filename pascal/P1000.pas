uses
	crt;
var
	a,b,c:longint;
begin
	repeat
	readln(a,b);
	c := a+b;
	writeln(c);
	until	a+b=0;
end.