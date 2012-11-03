program jyh;
 var
    q1,q2,q3,s,l:real;
    n,i:integer;
    x,y:array [1..100] of real;
function  sjx(a,b,c:real):real;
 var
    p:real;
 begin
    p:=(a+b+c)/2;
    sjx:= sqrt( p*(p-a)*(p-b)*(p-c) );
 end;
begin
  readln(n);
  for i:=1 to n do
     readln(x[i],y[i]);
  s:=0;
  for i:=2 to n-1 do
     begin
       q1:=sqrt( (x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1]) );
       q2:=sqrt( (x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]) );
       q3:=sqrt( (x[i+1]-x[1])*(x[i+1]-x[1])+(y[i+1]-y[1])*(y[i+1]-y[1]) );
       s:=s+sjx(q1,q2,q3);
     end;
  for i:=1 to n-1 do
    begin
     q2:=sqrt( (x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]) );
     l:=l+q2;
    end;
  writeln(l:0:2);
  writeln(s:0:2);
end.
