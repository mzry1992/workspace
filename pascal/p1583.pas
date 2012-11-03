
var total,fortotal,l,ll,n,i,j,top,di,now,x1,y1,x2,y2:longint;
    x,y:array[1..50000] of longint;
    mp:array[0..100,0..100] of 0..2;
    s:array[1..100000,1..2] of longint;
    flg:boolean;

function chick(a,b:longint):longint;
begin
if b > 0 then exit(2);
if a = 1 then exit(1);
exit(0);
end;

procedure search(x1,x2,y1,y2:longint;var code:longint);
var t1,t2,i,j:longint;
begin
t1:=0; t2:=0;
for i:= x1 to x2 do
for j:= y1 to y2 do
begin
if mp[i,j] = 2 then inc(t2);
if mp[i,j] = 1 then inc(t1);
end;
code:=chick(t1,t2);
end;

function done(xx,yy:longint):longint;
var ll,lll,i,j,time,code:longint;
    flg:boolean;
begin
lll:=-1;
for ll:= 1 to l do
if xx+ll-1 <= l then
if yy+ll-1 <= l then
begin
search(xx,xx+ll-1,yy,yy+ll-1,code);

if ( code = 2 ) and (lll = -1 ) then exit(ll);
if code = 1 then lll:=ll;

end;

if lll <> -1 then
 begin
 for i:= xx to xx+lll-1 do
  for j:= yy to yy+lll-1 do
   mp[i,j]:=2;
 for i:= 1 to l do
 begin
 for j:= 1 to l do write(mp[i,j]);
 writeln;
 end;
 writeln('-------------');
 exit(lll);
 end;

exit(1);
end;

begin
readln(total);
for fortotal:= 1 to total do
begin
fillchar(mp,sizeof(mp),0);
readln(l,n);
for i:= 1 to n do
begin
readln(x[i],y[i]);
mp[x[i],y[i]]:=1;
end;
s[1,1]:=1; s[1,2]:=1;
top:=1; di:=1;
while di <= top do
begin
now:=di;
x1:=s[now,1]; y1:=s[now,2];
ll:=done(x1,y1);
x2:=x1; y2:=y1+ll;
if (( x2 >= 1 ) and ( x2 <= l )) and (( y2 >=1 ) and ( y2 <= l )) then
 begin
 inc(top);
 s[top,1]:=x2;
 s[top,2]:=y2;
 end;
x2:=x1+ll;  y2:=y1;
if (( x2 >= 1 ) and ( x2 <= l )) and (( y2 >=1 ) and ( y2 <= l )) then
 begin
 inc(top);
 s[top,1]:=x2;
 s[top,2]:=y2;
 end;
if ( s[di,1] = l ) and ( s[di,2] = l ) then di:=top+100;
inc(di);
end;
flg:=true;
for i:= 1 to l do
for j:= 1 to l do
if mp[i,j] <> 2 then flg:=false;
if flg then writeln('Yes') else writeln('No');
end;
end.
