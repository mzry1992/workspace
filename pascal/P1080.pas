var f:array[-100..100,-100..100,-100..100] of qword;
    i,j,k,n,m,a,b,c:integer;
    v:array[-100..100,-100..100,-100..100] of boolean;
    flg:boolean;

function w(a,b,c:integer):qword;
var t:qword;
begin
if v[a,b,c] then exit(f[a,b,c]);
if (( a <= 0 ) or ( b <= 0 ) or ( c <= 0 )) then begin f[a,b,c]:= 1 ; v[a,b,c]:=true ; exit(1); end;
if (( a > 20 ) or ( b > 20 ) or ( c > 20 )) then begin f[a,b,c]:= f[20,20,20] ; v[a,b,c]:=true ; exit(f[20,20,20]); end;
if (( a < b ) and ( b < c )) then
 begin
 t:=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
 f[a,b,c]:=t;
 v[a,b,c]:=true;
 exit(t);
 end;
t:=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
f[a,b,c]:=t;
v[a,b,c]:=true;
exit(t);
end;

begin
fillchar(v,sizeof(v),false);
for a:= 1 to 20 do
 for b:= 1 to 20 do
  for c:= 1 to 20 do
   f[a,b,c]:=w(a,b,c);
readln(a,b,c);
while (( a <> -1 ) or ( b <> -1 ) or ( c <> -1 ))  do
begin
writeln('w(',a,',',b,',',c,') = ',w(a,b,c));
readln(a,b,c);
end;
end.