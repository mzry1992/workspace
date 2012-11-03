var c1,c2:char;
    st:string;
    i:integer;
begin
c1:=' ';
readln(st);
for i:= 1 to length(st) do
 begin
 c2:=st[i];
 if c2 in ['a'..'z'] then
  if not ( c1 in  ( ['a'..'z'] + ['A'..'Z'] )) then c2:=chr(ord(c2)+ord('A')-ord('a'));
 if c2 in ['A'..'Z'] then
  if c1 in ( ['a'..'z'] + ['A'..'Z'] ) then c2:=chr(ord(c2)+ord('a')-ord('A'));
 write(c2);
 c1:=c2;
 end;
end.