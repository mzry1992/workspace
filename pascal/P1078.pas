var n,m,time,step,now,temp,temp2:integer;
    a:array[1..1000] of boolean;
begin
fillchar(a,sizeof(a),true);
readln(n);
readln(m);
time:=0;
now:=1;
repeat
inc(time);
step:=(time*time*time) mod 5 + 1 ;

temp:=now;
temp2:=0;
repeat
inc(temp);
if a[temp] then inc(temp2);
until temp2 = step;
now:=temp;
if now <= n then
 begin
 a[now]:=false;
 inc(now);
 end;
if now > n then
 begin
 now:=1;
 while not a[now] do inc(now);
 dec(time);
 end;
until time=m;

writeln(now-1);
end.