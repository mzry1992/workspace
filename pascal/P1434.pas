var n,m,x,y,x1,x2,y1,y2,max:longint;
    mp:array[1..1000,1..1000] of 0..1;
    s:array[1..1000,1..1000] of longint;
    ch:char;
    flg:boolean;
procedure dfs(x,y,step:longint);
begin
s[x,y]:=step;
 if mp[x-1,y] = 0 then
  if ( x - 2 ) > 1  then
  if s[x-2,y] > step+1 then
   dfs(x-2,y,step+1);
 if mp[x+1,y] = 0 then
  if ( x + 2 ) < n then
  if s[x+2,y] > step+1 then
   dfs(x+2,y,step+1);
 if mp[x,y-1] = 0 then
  if ( y - 2 ) > 1  then
  if s[x,y-2] > step+1 then
   dfs(x,y-2,step+1);
 if mp[x,y+1] = 0 then
  if ( y + 2 ) < m then
  if s[x,y+2] > step+1 then
   dfs(x,y+2,step+1);
end;

begin
readln(m,n);
n:=2*n+1;
m:=2*m+1;
flg:=false;
for x:= 1 to n do
begin
 for y:= 1 to m do
   begin
   s[x,y]:=maxlongint;
   read(ch);
   if ch = ' ' then mp[x,y]:=0 else mp[x,y]:=1;
   if ( x in [1,n] ) or ( y in [1,m] ) then
    if mp[x,y] = 0 then
     begin
     if flg then begin x2:=x ; y2:=y ; end
     else begin x1:=x ; y1:= y ; flg:=true ; end;
     end;
   end;
readln;
end;
if x1 = 1 then x1:=2;
if x1 = n then x1:=n-1;
if x2 = 1 then x2:=2;
if x2 = n then x2:=n-1;
if y1 = 1 then y1:=2;
if y1 = m then y1:=m-1;
if y2 = 1 then y2:=2;
if y2 = m then y2:=m-1;
dfs(x1,y1,1);
dfs(x2,y2,1);
max:=0;
for x:= 1 to n do
for y:= 1 to m do
if x mod 2 = 0 then
if y mod 2 = 0 then
if max < s[x,y] then max:=s[x,y];
writeln(max);
end.