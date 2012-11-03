var a:array[1..8] of integer;
    total:longint;

function ok(j,i:integer):boolean;
var n:integer;
begin
for n:= 1 to i-1 do if a[n] = j then exit(false);
if i > 1 then
begin
if a[i-1] = j+1 then exit(false);
if a[i-1] = j-1 then exit(false);
end;
exit(true);
end;

procedure print;
var x,y:integer;
begin
inc(total);
writeln('No. ',total);
for x:= 1 to 8 do
begin
for y:= 1 to 8 do
 if a[x] = y then write('1 ') else write('0 ');
writeln;
end;
end;

procedure dfs(i:integer);
var j:integer;
begin
if i = 9 then print;
for j:= 1 to 8 do
 if ok(j,i) then
  begin
  a[i]:=j;
  dfs(i+1);
  end;
end;

begin
total:=0;
dfs(1);
end.
