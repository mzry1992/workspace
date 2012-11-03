var c2:char;
    st:string;
    i:integer;
begin
readln(st);
for i:= 1 to length(st) do
 begin
 c2:=st[i];
 if c2 in ['a'..'z'] then c2:=chr(ord(c2)+ord('A')-ord('a'))
 else
 if c2 in ['A'..'Z'] then c2:=chr(ord(c2)+ord('a')-ord('A'));
 write(c2);
 end;
writeln;
end.