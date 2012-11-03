type str = array[1..10] of 0..3 ;
var a,b,temp:str;
    h:array[1..500000] of boolean;
    s:array[1..10000] of str;
    f:array[1..10000] of longint;
    pos:array[1..10000] of integer;
    ans,top,now,last,i,j,x,y:longint;
    flg:boolean;

function hash(st:str):longint;
var i,j,k,x,y:longint;
begin
j:=0;
for i:= 1 to 10 do
 begin
 k:=st(i);
 x:=1;
 for y:= 1 to 10 - i do x:=x*3;
 j:=j + k * x;
 end;
exit(j);
end;

procedure output(i:longint);
begin
if i <> 0 then
begin
 output(f[i]);
 writeln(s[i]);
end;
end;

begin

fillchar(h,sizeof(h),false);
a:=(1,0,0,1,2,2,1,0,1,0);
b:='1111000022';
ans:=hash(b);
top:=1;
last:=1;
s[top]:=a;
f[top]:=0;
h[hash(s[top])]:=true;
pos[top]:=5;
flg:=false;

while ( last <= top ) or flg do
begin
now:=last;
a:=s[now];
for i:= 1 to 9 do
 if abs (pos[now] - i ) >= 2 then
  begin
  if not h[x] then
   begin
   inc(top);
   s[top]:=temp;
   f[top]:=now;
   h[x]:=true;
   pos[top]:=i;
   if x = ans then flg:=true;
   end;
  end;

inc(last);
end;

if flg then
output(top);

end.
