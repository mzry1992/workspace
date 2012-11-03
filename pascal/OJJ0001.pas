var     a,b:longint;
begin
assign(input,'plus.in');
assign(output,'plus.out');
reset(input);
rewrite(output);
readln(a);
readln(b);
writeln(a+b);
close(input);
close(output);
end.