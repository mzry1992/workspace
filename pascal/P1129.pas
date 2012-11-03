var st,st1:string;
    i,k,j,x,y,z:integer;
    a,b:array[0..9] of longint;
    ans:double;
    flg:boolean;
    mp:array[0..9,0..9] of 0..1;

procedure int;
begin
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
fillchar(mp,sizeof(mp),0);
readln(st);
i:=1;
while st[i] <> ' ' do
begin
inc(a[ord(st[i])-ord('0')]);
inc(i);
end;
inc(i);
st1:=copy(st,i,length(st)-i+1);
val(st1,i,j);
k:=i;
for j:= 1 to i do
begin
readln(x,y);
mp[x,y]:=1;
end;
end;

begin
int;
for x:= 0 to 9 do mp[x,x]:=1;
for i:= 1 to 2 do
for x:= 0 to 9 do
 for y:= 0 to 9 do
  for z:= 0 to 9 do
   if ((mp[x,z] = 1 ) and (mp[z,y] = 1 )) then mp[x,y]:=1;
for x:= 0 to 9 do
 for y:= 0 to 9 do
  if mp[x,y]= 1 then inc(b[x]);
ans:=1;
for i:= 0 to 9 do
for j:= 1 to a[i] do
 ans:=ans*b[i];
writeln(ans:0:0);
end.
