var n:longint;
    a:array[1..100] of boolean;
function ok:boolean;
var i:longint;
begin
for i:= 1 to n do
 if not a[i] then exit(false);
exit(true);
end;

procedure done(n:longint);
var m,i,time:longint;
begin
fillchar(a,sizeof(a),true);
m:=0;
repeat
inc(m);
i:=1;
time:=0;
repeat
inc(time);
a[i]:=not a[i];
inc(i);
if i > n then i:=1;
until time = m ;
until ok;
writeln(m);
end;

begin
for n:= 1 to 100 do done(n);
end.