var st:ansistring;
    zf:boolean;
    i:integer;
begin
readln(st);
zf:=true;
i:=0;
repeat
inc(i);
if st[i] = '-' then
 if i = 1 then zf:=false
 else
  if st[i-1] in ['+','-'] then zf:=not zf;
until i = length(st);
writeln(zf);
end.