type arr = array[0..1000] of longint;
var a,b,c,d,e:arr;
    st,s1,s2:string;
    i,l1,l2:integer;

function max(a,b:integer):integer;
begin
if a > b then exit(a);
exit(b);
end;

function long(a:arr):integer;
var i:integer;
begin
i:=1000;
while a[i] = 0 do dec(i);
exit(i);
end;

function big(a,b:arr):boolean;
var i,j:integer;
begin
i:=a[0]; j:=b[0];
if i > j then exit(true);
if i < j then exit(false);
for i:= j downto 1 do
 if a[i] < b[i] then exit(false);
exit(true);
end;

function jia(a,b:arr):arr;
var i,qian:integer;
    temp:arr;
begin
fillchar(temp,sizeof(temp),0);
qian:=0;
for i:= 1 to max(a[0],b[0]) do
 begin
 temp[i]:=a[i]+b[i]+qian;
 qian:=temp[i] div 10;
 temp[i]:=temp[i] mod 10;
 end;
if qian > 0 then
 temp[max(a[0],b[0])+1]:=qian;
temp[0]:=long(temp);
exit(temp);
end;

function jian(a,b:arr):arr;
var i:integer;
    temp:arr;
begin
fillchar(temp,sizeof(temp),0);
for i:= 1 to max(a[0],b[0]) do
 begin
 temp[i]:=a[i]-b[i];
 if temp[i] < 0 then
  begin
  temp[i]:=temp[i]+10;
  a[i+1]:=a[i+1]-1;
  end;
 end;
temp[0]:=long(temp);
exit(temp);
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

function cdiv(a,b:arr):arr;
var i,j:integer;
    temp,one:arr;
begin
fillchar(one,sizeof(one),0);
fillchar(temp,sizeof(temp),0);
one[0]:=1;
one[1]:=1;
i:=a[0]; j:=b[0];
while big(a,b) do
begin
 a:=jian(a,b);
 temp:=jia(temp,one);
end;
exit(temp);
end;

function s2v(st:string):arr;
var temp:arr;
    i,l:integer;
begin
fillchar(temp,sizeof(temp),0);
l:=length(st);
temp[0]:=l;
for i:= 1 to l do
 temp[l+1-i]:=ord(st[i])-ord('0');
exit(temp);
end;

function v2s(a:arr):string;
var i,l:integer;
    temp:string;
begin
l:=a[0];
temp:='';
for i:= 1 to l do temp:=temp+'0';
for i:= l downto 1 do
 temp[i]:=chr(a[l+1-i]+ord('0'));
exit(temp);
end;

begin
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
readln(st);
s1:=copy(st,1,pos(' ',st)-1);
s2:=copy(st,pos(' ',st)+1,length(st)-pos(' ',st));
a:=s2v(s1); b:=s2v(s2);
c:=jia(a,b);
st:=v2s(c);
writeln(st);
end.
