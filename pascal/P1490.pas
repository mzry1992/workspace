var st:string;
    l,i,j:longint;
begin
readln(st);
l:=length(st);
if st[l] in ['0','2','4','6','8'] then writeln(1) else writeln(0);
j:=0;
for i:= 1 to l do
 j:=j+ord(st[i])-ord('0');
if j mod 3 = 0 then writeln(1) else writeln(0);
j:=ord(st[l])-ord('0')+10*(ord(st[l-1])-ord('0'));
if j mod 4 = 0 then writeln(1) else writeln(0);
j:=ord(st[l])-ord('0')+10*(ord(st[l-1])-ord('0'))+100*(ord(st[l-2])-ord('0'));
if j mod 8 = 0 then writeln(1) else writeln(0);
if st[l] in ['2','3','7','8'] then writeln(0) else writeln(1);
end.