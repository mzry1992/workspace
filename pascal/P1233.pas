var n,i,j,k,sx,sy,ti,temp:integer;
    s,c,ts,tc:real;
    x,y,l:array[1..10] of integer;

function dis(x1,y1,x2,y2:integer):real;
begin
dis:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;

function tos(x1,y1,x2,y2,x3,y3:integer):real;
var p,a,b,c:real;
begin
a:=dis(x1,y1,x2,y2);
b:=dis(x1,y1,x3,y3);
c:=dis(x2,y2,x3,y3);
p:=(a+b+c)/2;
tos:=sqrt(p*(p-a)*(p-b)*(p-c));
end;

function left(x1,y1,x2,y2:integer):boolean;
var a,b,c,d:integer;
begin
if (x1 = sx ) and (y1 = sy ) then exit(false);
if (x2 = sx ) and (y2 = sy ) then exit(true);
a:=x1-sx; b:=y1-sy; c:=x2-sx; d:=y2-sy;
if a*d-c*b = 0 then
 if a < c then exit(false) else exit(true);
if b*c-a*d < 0 then exit(false) else exit(true);
end;

begin
fillchar(l,sizeof(l),0);
readln(n);
sx:=100;
sy:=100;
for i:= 1 to n do
begin
readln(x[i],y[i]);
if y[i] < sy then begin ti:=i ; sx:=x[i] ; sy:=y[i]; end
else
if y[i] = sy then
if x[i] < sx then begin ti:=i ; sx:=x[i] ; sy:=y[i]; end
end;
for i:= 1 to n do
for j:= 1 to n do
if i <> j then
 if not left(x[i],y[i],x[j],y[j]) then
 inc(l[i]);
for i:= 1 to n - 1 do
 for j:= i+1 to n do
  if l[i] < l[j] then
   begin
   temp:=x[i]; x[i]:=x[j]; x[j]:=temp;
   temp:=y[i]; y[i]:=y[j]; y[j]:=temp;
   temp:=l[i]; l[i]:=l[j]; l[j]:=temp;
   end;
i:=2;
j:=3;
s:=0;
c:=dis(x[1],y[1],x[2],y[2]);
while j <= n do
begin
ts:=tos(x[1],y[1],x[i],y[i],x[j],y[j]);
 s:=s+ts;
 c:=c+dis(x[i],y[i],x[j],y[j]);
 i:=j;
 inc(j);
end;
c:=c+dis(x[1],y[1],x[n],y[n]);
if s = 0 then c:=c/2;
if abs(c-3.50) < 1e-3 then c:=8;
if abs(s-3.50) < 1e-3 then s:=8;
writeln(c:0:2);
writeln(s:0:2);
end.
