var x1,x2,x3,x4,y1,y2,y3,y4:double;
function cross(a,b,c,d,e,f:double):integer;
var x,y,xx,yy:double;
begin
x:=c-a;
y:=d-b;
xx:=e-a;
yy:=f-b;
if x*yy-xx*y > 0 then exit(1) ;
exit(-1);
end;
begin
readln(x1,y1,x2,y2);
readln(x3,y3,x4,y4);
if cross(x1,y1,x2,y2,x3,y3)*cross(x1,y1,x2,y2,x4,y4) < 0 then
if cross(x3,y3,x4,y4,x1,y1)*cross(x3,y3,x4,y4,x2,y2) < 0 then
 writeln('Cross')
else writeln('Not Cross')
else writeln('Not Cross2');
writeln(cross(0,5,10,5,7,4.5));
writeln(cross(0,5,10,5,7,6));
end.
