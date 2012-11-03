var n:longint;
    g:array[1..100,1..100] of boolean;
    cd,rd:array[1..100] of longint;
    i,j,k,cd0,rd0:longint;

function max(a,b:longint):longint;
begin
if a > b then exit(a);
exit(b);
end;

begin
readln(n);
for i:= 1 to n-1 do
begin
read(j);
while j <> 0 do
begin
g[i,j]:=true;
read(j);
end;
end;
fillchar(cd,sizeof(cd),0);
fillchar(rd,sizeof(rd),0);
for i:= 1 to n do
 for j:= 1 to n do
  if g[i,j] then begin inc(cd[i]); inc(rd[j]); end;
cd0:=0; rd0:=0;
for i:= 1 to n do
begin
if cd[i] = 0 then inc(cd0);
if rd[j] = 0 then inc(rd0);
end;
writeln(max(rd0,1));
writeln(max(rd0,cd0));
end.
