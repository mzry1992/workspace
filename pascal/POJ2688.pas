var st:string;
    a,e,i,o,u,k:integer;
begin
readln(st);
a:=0;
e:=0;
i:=0;
o:=0;
u:=0;
for k:= 1 to length(st) do
 begin
 if st[k] = 'a' then inc(a);
 if st[k] = 'e' then inc(e);
 if st[k] = 'i' then inc(i);
 if st[k] = 'o' then inc(o);
 if st[k] = 'u' then inc(u);
 end;
writeln(a,' ',e,' ',i,' ',o,' ',u);
end.