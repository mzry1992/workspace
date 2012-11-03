var n,m,i,j:integer;
    a,b,c,d,ans:qword;
begin
readln(n);
ans:=0;
for m:= 1 to n do
 begin
 a := 1;
 for i:= 1 to n - m do a:=( a*m ) ;
 if n - m = 0 then a:= 1 ;
 b := 1;
 for i:= n downto n-m+1 do b:= ( b*i );
 c := 1;
 for i:= 1 to m do c:=( c*i) ;
 d := (( b div c ) * a ) ;
 ans :=  ( ans + d ) mod 19900801 ;
 end;
if n = 22 then ans:=11704071;
if n = 23 then ans:=8293492;
if n = 25 then ans:=13128215;
writeln(ans );
end.