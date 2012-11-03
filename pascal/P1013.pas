var n,k,i,j,q:integer;
    a,b,c,d,e,f,min:double;
    x:array[0..21] of double;
    y:array[0..21,1..4] of double;
    g:array[1..20,1..4] of double;
    flg:boolean;

function cross(a,b,c,d,e,f:double):integer;
var x,y,xx,yy:double;
begin
x:=c-a;
y:=d-b;
xx:=e-a;
yy:=f-b;
if x*yy-xx*y > 0 then exit(1) else exit(-1);
end;

function cancross(x1,y1,x2,y2,x3,y3,x4,y4:double):boolean;
begin
if cross(x1,y1,x2,y2,x3,y3)*cross(x1,y1,x2,y2,x4,y4) < 0 then
if cross(x3,y3,x4,y4,x1,y1)*cross(x3,y3,x4,y4,x2,y2) < 0 then
 exit(false);
exit(true);
end;

function dis(x1,y1,x2,y2:double):double;
begin
dis:=sqrt(sqr(x2-x1)+sqr(y2-y1));
end;

function cango(k1,i1,k2,i2:integer):boolean;
var i,q:integer;
    a,b,c,d:double;
    flg:boolean;
begin
if k1 + 1 = k2 then exit(true);
a:=x[k1]; b:=y[k1,i1] ; c:=x[k2] ; d:=y[k2,i2] ; flg:=true;
for q:= k1 + 1 to k2 - 1 do
   begin
   if not cancross(a,b,c,d,x[q],0,x[q],y[q,1]) then begin flg:=false ; break; end;
   if not cancross(a,b,c,d,x[q],y[q,2],x[q],y[q,3]) then begin flg:=false ; break ; end;
   if not cancross(a,b,c,d,x[q],y[q,4],x[q],10) then begin flg:=false ; break ; end;
   end;
if flg then exit(true);
exit(false);
end;

begin
readln(n);
x[0]:=0;
x[n+1]:=10;
for i:= 1 to 4 do
begin
y[0,i]:=5;
y[n+1,i]:=5;
g[0,i]:=0;
end;
for i:= 1 to n+1 do
 for j:= 1 to 4 do
  g[i,j]:=1E38;
min:=1E38;
for i:= 1 to n do readln(x[i],y[i,1],y[i,2],y[i,3],y[i,4]);
for i:= 0 to n do
 for j:= i+1 to n+1 do
  for k:= 1 to 4 do
   for q:= 1 to 4 do
    if cango(i,k,j,q) then
     if g[j,q] > g[i,k] + dis(x[i],y[i,k],x[j],y[j,q]) then
      g[j,q]:=g[i,k] + dis(x[i],y[i,k],x[j],y[j,q]);
writeln(g[n+1,1]:0:2);
end.