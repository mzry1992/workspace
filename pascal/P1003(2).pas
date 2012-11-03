type
ayy=array[0..50] of integer;
var
n,i,k,j:longint;
s:array[0..26] of string;
x,ans,t,p:extended;
z:array[0..26] of boolean;
y:array[0..26] of ayy;
l:array[0..26] of integer;
procedure jin(k:integer);
var
 i,base,jj:integer;
begin
 base:=0;
 jj:=10;
 fillchar(y[k],sizeof(y[k]),127);
 for i:=1 to l[k] do
  begin
case s[k][i] of
 '(':inc(base,15);
 ')':dec(base,15);
 '+','-':y[k][i]:=base+1;
 '*':y[k][i]:=base+2;
 '^':begin
  y[k][i]:=base+3+jj;
  dec(jj);
 end;
end;
  end;
end;
function find(k,l,r:integer):integer;
var
 i,min:integer;
begin
 find:=0;
 min:=32638;
 for i:=r downto l do
  if y[k][i]<min then
begin
 find:=i;
 min:=y[k][i];
end;
end;
function opt(i:integer;x,y:extended;k:integer):extended;
var
 j:integer;
begin
 case s[i][k] of
  '+':opt:=x+y;
  '-':opt:=x-y;
  '*':opt:=x*y;
  '^':begin
opt:=1;
for j:=1 to round(y) do
 opt:=opt*x;
   end;
 end;
end;
function danxiang(m,st,en:integer):extended;
var
 p:integer;
begin
 if pos('a',copy(s[m],st,en-st+1))<>0 then
  begin
val(copy(s[m],st,en-st),p);
if p=0 then
 danxiang:=x
 else
  danxiang:=p*x;
  end
  else
val(copy(s[m],st,en-st+1),danxiang);
end;
function judge(m,st,en:integer):boolean;
var
 i,qian:integer;
begin
 qian:=0;
 judge:=false;
 for i:=st+1 to en-1 do
  begin
if s[m][i]='(' then
 inc(qian);
if s[m][i]=')' then
 dec(qian);
if qian<0 then
 exit;
  end;
 if (s[m][st]='(')and(s[m][en]=')') then
  judge:=true;
end;
function suan(m,st,en:integer):extended;
var
 k:integer;
 p:extended;
begin
 while judge(m,st,en) do
  begin
inc(st);
dec(en);
  end;
 k:=find(m,st,en);
 if k=0 then
  begin
p:=danxiang(m,st,en);
exit(p);
  end;
 suan:=opt(m,suan(m,st,k-1),suan(m,k+1,en),k);
end;
procedure zhengli(m,st,en:integer);
var
 top,k,i:integer;
 zhan:array[0..50] of char;
begin
 top:=0;
 i:=1;
 while i<=length(s[m]) do
  begin
if s[m][i]='(' then
 begin
  inc(top);
  zhan[top]:='(';
 end;
if s[m][i]=')' then
 begin
  if zhan[top]='(' then
   dec(top)
   else
begin
 delete(s[m],i,1);
 dec(i);
end;
 end;
inc(i);
  end;
 for i:=1 to top do
  begin
k:=pos('(',s[m]);
delete(s[m],k,1);
  end;
end;
begin
readln(s[0]);
i:=1;
while i<=length(s[0]) do
 if s[0][i]=' ' then
  delete(s[0],i,1)
  else
inc(i);
zhengli(0,1,length(s[0]));
l[0]:=length(s[0]);
jin(0);
readln(n);
for i:=1 to n do
 begin
  readln(s[i]);
  j:=1;
  while j<=length(s[i]) do
if s[i][j]=' ' then
 delete(s[i],j,1)
 else
  inc(j);
  zhengli(i,1,length(s[0]));
  l[i]:=length(s[i]);
  jin(i);
 end;
fillchar(z,sizeof(z),true);
for k:=1 to 10 do
 begin
  randomize;
  x:=random(100)/10;
  ans:=suan(0,1,l[0]);
  p:=1;
  while p<=ans do
 p:=p*10;
  p:=p/10;
  for i:=1 to n do
if z[i] then
 begin
  t:=suan(i,1,l[i]);
  if (abs(ans/p-t/p)>1e-5) then
   z[i]:=false;
 end;
 end;
for i:=1 to n do
 if z[i] then
  write(chr(i+64));
writeln;
end.
