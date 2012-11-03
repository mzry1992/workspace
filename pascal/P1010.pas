type arr = array[0..2000] of integer;
var st,s1,s2:ansistring;
    a,b:arr;
    i,j,n,m,l:integer;

function long(a:arr):integer;
var i:integer;
begin
i:=2000;
while a[i] = 0 do dec(i);
exit(i);
end;

function chen(a,b:arr):arr;
var i,j:integer;
    temp:arr;
begin
fillchar(temp,sizeof(temp),0);
for i:= 1 to a[0] do
 for j:= 1 to b[0] do
  begin
  temp[i+j-1]:=temp[i+j-1]+a[i]*b[j];
  temp[i+j]:=temp[i+j]+temp[i+j-1] div 10;
  temp[i+j-1]:=temp[i+j-1] mod 10;
  end;
temp[0]:=long(temp);
exit(temp);
end;

begin
while not eof do
begin
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
readln(st);
s1:=copy(st,1,pos(' ',st)-1);
i:=pos(' ',st);
while st[i] = ' ' do inc(i);
s2:=copy(st,i,length(st)+1-i);
i:=length(s1);
l:=pos('.',s1);
if l > 0 then
while s1[i] = '0' do dec(i);
if s1[i] = '.' then begin l := 0 ; dec(i); end;
s1:=copy(s1,1,i);
if l > 0 then l:= length(s1) - l;
val(s2,n);  l:=l*n;
i:=1; m:=length(s1);
if pos('.',s1) = 0 then inc(m);
a[0]:=m-1;
while i <= length(s1) do
 begin
 if st[i] <> '.' then
  begin
  dec(m); a[m]:=ord(st[i])-ord('0');
  end;
 inc(i);
 end;
b:=a;
for i:= 2 to n do
 b:=chen(a,b);
a[0]:=m;
if b[0] <= l then
begin
write('.');
for i:= 1 to l-b[0] do write('0');
for i:= b[0] downto 1 do write(b[i]);
writeln;
end
else
 begin
 for i:= b[0] downto l+1 do write(b[i]);
 if l > 0 then
 write('.');
 for i:= l downto 1 do write(b[i]);
 writeln;
 end;
end;
end.


