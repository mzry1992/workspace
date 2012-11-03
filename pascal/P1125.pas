var h,s,v,l,k,t1,t2,tmin,tmax:real;
    n,t,total:longint;
begin
readln(h,s,v,l,k,n);
total:=0;
tmax:=sqrt(h/5);
tmin:=sqrt((h-k)/5);
for t:= 0 to n-1 do
 begin
 t1:=(s-t)/v;
 t2:=(s+l-t)/v;
 if ( tmax >= t1 -0.00001 ) and ( tmin <= t2 - 0.00001 ) then inc(total);
 end;
writeln(total);
end.