const nu:array[1..24,1..4] of integer = ((1,2,3,4),(1,2,4,3),(1,3,2,4),(1,3,4,2),(1,4,2,3),(1,4,3,2),
                                         (2,1,3,4),(2,1,4,3),(2,3,1,4),(2,3,4,1),(2,4,1,3),(2,4,3,1),
                                         (3,1,2,4),(3,1,4,2),(3,2,1,4),(3,2,4,1),(3,4,1,2),(3,4,2,1),
                                         (4,1,2,3),(4,1,3,2),(4,2,1,3),(4,2,3,1),(4,3,1,2),(4,3,2,1));
var i,j,n,m,a,b,c,x:integer;
    num:array[1..4] of longint;
function cal(a,b:double;op:longint):double;
begin
case op of
1  : exit(a+b);
2  : exit(a-b);
3  : exit(a*b);
4  : if b <> 0 then exit(a/b) else exit(a*b);
end;
end;

procedure sql;
var ans:double;
begin
for i:= 1 to 24 do
 for a:= 1 to 4 do
  for b:= 1 to 4 do
   for c:= 1 to 4 do
   begin
    ans:=cal(cal(cal(num[nu[i,1]],num[nu[i,2]],a),num[nu[i,3]],b),num[nu[i,4]],c);
    if ( trunc(ans) div x > 0 ) and ( trunc(ans) div x < 10 ) then
    if  trunc(ans) mod 100 = m  then
     begin
     writeln(1);
     exit;
     end;
   end;
writeln(0);
end;

begin
readln(num[1],num[2],num[3],num[4]);
readln(n);
while n <> 1 do
 begin
 readln(m);
 x:=1;
 for i:= 1 to n-1 do
  x:=x*10;
 sql;
 readln(n);
 end;
end.