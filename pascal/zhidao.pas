const step:array[1..8,1..2] of longint = ((-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1));
var n,m,x,y:longint;
    mp:array[1..1000,1..1000] of 0..1;
    s:array[1..10000,1..2] of longint;
    f:array[1..10000] of longint;
    top,di,now,xx,yy,k:longint;
    hash:array[1..1000,1..1000] of boolean;
    flg:boolean;

procedure output(i:longint);
begin
if f[i] > 0 then
output(f[i]);
write('(',s[i,1],',',s[i,2],')-');
end;

begin
readln(n,m);
for x:= 1 to n do
begin
for y:= 1 to m do read(mp[x,y]);
readln;
end;
fillchar(hash,sizeof(hash),true);
top:=1; di:=1; s[top,1]:=1; s[top,2]:=1; hash[1,1]:=false; f[1]:=0;
flg:=false;
while not flg do
begin
x:=s[di,1]; y:=s[di,2];
for k:= 1 to 8 do
 begin
 xx:=x+step[k,1]; yy:=y+step[k,2];
 if (( xx >= 1 ) and ( xx <= n )) and (( yy >= 1 ) and ( yy <= n )) then
 if hash[xx,yy] then
  begin
  inc(top);
  s[top,1]:=xx;
  s[top,2]:=yy;
  f[top]:=di;
  if (xx = n ) and (yy = m ) then
   begin
   flg:=true;
   now:=top;
   end;
  end;
 end;
inc(di);
end;
output(f[now]);
writeln('(',s[now,1],',',s[now,2],')');
end.