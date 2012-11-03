uses crt;
begin
clrscr;
textmode(c40);
textbackground(blue);
textcolor(red);
writeln('text mode test');
textbackground(green);
textcolor(blink+yellow);
writeln('blink test');
repeat until keypressed;
end.