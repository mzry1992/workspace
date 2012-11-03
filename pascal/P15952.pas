var n:longint;
    cd,rd:array[1..100] of longint;
    i,j,k,cd0,rd0:longint;

function max(a,b:longint):longint;
begin
if a > b then exit(a);
exit(b);
end;

begin
fillchar(cd,sizeof(cd),0);
fillchar(rd,sizeof(rd),0);
readln(n);
for i:= 1 to n do
begin
read(j);
while j <> 0 do
begin
inc(rd[j]);
inc(cd[i]);
read(j);
end;
end;
cd0:=0;
rd0:=0;
for i:= 1 to n do
begin
if cd[i] = 0 then inc(cd0);
if rd[i] = 0 then inc(rd0);
end;
writeln(max(rd0,1));
writeln(cd0+(rd0-1)*2);
end.