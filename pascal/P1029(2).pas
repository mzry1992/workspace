const fan:array[1..4,1..2] of longint = ((-1,0),(0,-1),(0,1),(1,0));
      zxy:array[1..9,1..2] of longint = ((1,1),(1,2),(1,3),(2,1),(2,2),(2,3),(3,1),(3,2),(3,3));
      xyz:array[1..3,1..3] of longint = ((1,2,3),(4,5,6),(7,8,9));

var st,ans,st2:string;
    jiechen:array[0..8] of longint;
    f:array[1..362880] of boolean;
    sp:array[1..100000] of longint;
    s:array[1..100000] of string;
    top,di,now,zero,x,y,temp,four,xx,yy,hans,tans,abcd:longint;
    flg:boolean;
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
exit(en);
end;

begin
fillchar(f,sizeof(f),true);
fillchar(sp,sizeof(sp),0);
fillchar(jiechen,sizeof(jiechen),0);
jiechen[0]:=1;
for x:= 1 to 8 do
 jiechen[x]:= jiechen[x-1]*x;
for abcd:= 1 to 3 do
begin
readln(st);
ans:=st;
hans:=hash(ans);
f[hans]:=false;
top:=1;
di:=1;
s[top]:=st;
f[hash(st)]:=false;
sp[top]:=0;
flg:=false;
while not flg do
begin
now:=di;
zero:=pos('0',s[now]);
x:=zxy[zero,1];
y:=zxy[zero,2];
for four := 1 to 4 do
 begin
 xx:=x+fan[four,1];
 yy:=y+fan[four,2];
 if (( xx >= 1 ) and ( xx <= 3 )) and (( yy >= 1 ) and ( yy <= 3 )) then
  begin
  temp:=xyz[xx,yy];
  st2:=s[now];
  ch:=st2[zero];
  st2[zero]:=st2[temp];
  st2[temp]:=ch;
  temp:=hash(st2);
  if f[temp] then
   begin
   f[temp]:=false;
   inc(top);
   s[top]:=st2;
   sp[top]:=sp[now]+1;
   end;
  if temp = hans then
  begin
  inc(top);
  s[top]:=st2;
  sp[top]:=sp[now]+1;
  tans:=top;
  flg:=true;
  end;
  end;
 end;
inc(di);
end;
writeln(sp[tans]);
end;
end.
