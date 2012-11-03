var st,st1:string;
    i,k,j,x,y,ty,ti:integer;
    a,b:array[0..9] of longint;
    ans:double;
    flg:boolean;
    c,d:array[1..15] of longint;

procedure dfs(i:integer);
var j:integer;
begin
inc(ty);
for j:= 1 to k do
 if c[j] = i then
  if d[j] <> ti then
  dfs(d[j]);
end;

procedure int;
begin
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
fillchar(c,sizeof(c),0);
fillchar(d,sizeof(d),0);
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
 readln(c[j],d[j]);
end;

begin
int;
for i:= 0 to 9 do begin ty:=0 ; ti:=i ; dfs(i); b[i]:=ty ; end;
ans:=1;
for i:= 0 to 9 do
for j:= 1 to a[i] do
 ans:=ans*b[i];
writeln(ans:0:0);
end.
