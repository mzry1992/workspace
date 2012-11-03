const fan:array[1..12,1..2] of longint = ((1,2),(2,3),(4,5),(5,6),(7,8),(8,9),(1,4),(2,5),(3,6),(4,7),(5,8),(6,9));
      ate:array[1..8] of string = ('276951438','294753618','438951276',
                                   '492357816','618753294','672159834',
                                   '816357492','834159672');

var st,ans,st2:string;
    jiechen:array[0..8] of longint;
    f:array[1..362880] of boolean;
    sp:array[1..400000] of longint;
    s:array[1..400000] of string;
    top,di,now,zero,x,y,temp,four,xx,yy,hans,tans,abcd,i:longint;
    flg:boolean;
    canans:array[1..8] of longint ;
    ch:char;

function hash(str:string):longint;
var temp:array[1..9] of longint;
    use:array[1..9] of boolean;
    i,j,t,en:longint;
begin
fillchar(use,sizeof(use),true);
en:=1;
for i:= 1 to 9 do
 temp[i]:=ord(str[i])-ord('0')+1;
for i:= 1 to 9 do
begin
use[temp[i]]:=false;
t:=0;
 for j:= 1 to 9 do
  if ( use[j] ) and ( j < temp[i] ) then
   inc(t);
en:=en+t*jiechen[9-i];
end;
en:=en mod 3214567;
exit(en);
end;

begin
fillchar(f,sizeof(f),true);
fillchar(sp,sizeof(sp),0);
fillchar(jiechen,sizeof(jiechen),0);
jiechen[0]:=1;
for x:= 1 to 8 do
 jiechen[x]:= jiechen[x-1]*x;
for abcd:= 1 to 1 do
begin
st:='';
for x:= 1 to 3 do
begin
 for y:= 1 to 3 do
 begin
 read(temp);
 st:=st+chr(temp+ord('0'));
 end;
readln;
end;
flg:=false;
hans:=hash(st);
f[hans]:=false;
s[1]:=st;
sp[1]:=0;
for top:= 1 to 8 do
begin
st:=ate[top];
temp:=hash(st);
if temp = hans then
 begin
 flg:=true;
 tans:=0;
 end;
canans[top]:=temp;
end;
top:=1;
di:=1;
while di <= top  do
begin
now:=di;
st:=s[now];
for zero:= 1 to 12 do
 begin
 x:=fan[zero,1];
 y:=fan[zero,2];
 st2:=st;
 ch:=st2[x];
 st2[x]:=st2[y];
 st2[y]:=ch;
 temp:=hash(st2);
 if f[temp] then
  begin
  for xx:= 1 to 8 do
   if canans[xx] = temp then
    begin
    top:=1;
    tans:=sp[now]+1;
    end;
  inc(top);
  s[top]:=st2;
  sp[top]:=sp[now]+1;
  f[temp]:=false;
  end;
 end;
inc(di);
end;
writeln(tans);
end;
end.
