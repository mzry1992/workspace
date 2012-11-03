var i:byte;
a,b:char;
s:ansistring;
begin
for i:=1 to 10 do begin
readln(s);
a:=s[pos(' ',s)-1];
b:=s[length(s)];
if((a='2')or(a='3')or(a='7')or(a='8'))and
((b='2')or(b='3')or(b='7')or(b='8')) then
writeln('Shadow') else writeln('Matrix67');
end;
end. 