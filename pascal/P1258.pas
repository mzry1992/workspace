var a0,a1,a2,a3,a4,a5,a6,a7,a8:longint;
    flg:boolean;
procedure output(a,b:longint);
begin
if a <> 0 then
begin
if flg then
 begin
 if a > 0 then
  write(' + ')
 else write(' - ');
 if ( a <> 1 ) and ( a <> -1 ) then
  write(abs(a));
 if b > 1 then
 write('x^',b)
 else write('x');
 end
else
 begin
 flg:=true;
 if a = - 1 then write('-');
 if ( a <> 1 ) and ( a <> -1 ) then
  write(a);
 if b > 1 then
 write('x^',b)
 else write('x');
 end;
end;
end;

begin
readln(a8,a7,a6,a5,a4,a3,a2,a1,a0);
flg:=false;
output(a8,8);
output(a7,7);
output(a6,6);
output(a5,5);
output(a4,4);
output(a3,3);
output(a2,2);
output(a1,1);
if flg then
begin
if a0 > 0 then write(' + ',a0);
if a0 < 0 then write(' - ',abs(a0));
end
else write(a0);
writeln;
end.

