var a:char;
begin
assign(output,'1.out');
rewrite(output);
for a:= '0' to '9' do write(a,',');
writeln;
for a:= 'a' to 'z' do write(a,',');
writeln;
for a:= 'A' to 'Z' do write(a,',');
writeln;
close(output);
end.