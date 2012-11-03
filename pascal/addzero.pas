var st:ansistring;
    i,l:integer;
begin
readln(st);
l:=length(st);
i:=0;
repeat
inc(i);
if st[i] = '-' then
begin
 if i = 1 then
  begin
  st:='0'+st;
  inc(i);
  inc(l);
  end
 else
  begin
  if st[i-1] = '(' then
   begin
   insert('0',st,i);
   inc(i);
   inc(l);
   end;
  end;
end;
until i = l ;
writeln(st);
end.