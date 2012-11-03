var st,min,temp,temp2:ansistring;
    i,j,l:longint;
    flg:boolean;

function small(a,b:ansistring):boolean;
var i,j:longint;
begin
j:=1;
while a[j] = b[j] do inc(j);
if a[j] < b[j] then
exit(true);
exit(false);
end;

begin
begin
readln(st);
l:=length(st);
min:=st;
for i:= 1 to l do
if st[i] <= min[1] then
 begin
 temp:=copy(st,i,l+1-i)+copy(st,1,i-1);
 if small(temp,min) then min:=temp;
 end;
temp2:=st;
for i:= 1 to l do
temp2[l+1-i]:=st[i];
st:=temp2;
for i:= 1 to l do
if st[i] <= min[1] then
 begin
 temp:=copy(st,i,l+1-i)+copy(st,1,i-1);
 if small(temp,min) then min:=temp;
 end;
writeln(min);
end;
end.
