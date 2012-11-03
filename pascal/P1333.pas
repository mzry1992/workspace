var i,j,m,bak,k:longint;
begin
readln(m);
bak:=m;
i:=1;
j:=0;
repeat
j:=j+i;
i:=i+4;
until j >= m ;
i:=i-4;
j:=j-i;
m:=m-j;
writeln(i,' ',j,' ',m);
if m <= ( i + 1 ) div 2 then
 write(m)
else
 write(i+1-m);
write('/');
m:=bak;
i:=3;
j:=0;
repeat
j:=j+i;
i:=i+4;
until j > m ;
i:=i-4;
j:=j-i;
m:=m-j;
if m <= ( i + 1 ) div 2 then
 writeln(m)
else
 writeln(i+1-m);
end.