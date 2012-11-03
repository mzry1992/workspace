var k,i,j:longint;
begin
assign(input,'1.txt');
rewrite(input);
k:=1; i:=9; j:=0;
repeat
j:=k*i+j;
writeln(input,j);
inc(k); i:=i*10;
until k = 9;
close(input);
end.