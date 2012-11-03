var a,b:array[1..100] of longint;
    i,n,m:longint;

procedure dfs(dep:longint);
var j:longint;
    temp:array[1..100] of boolean;
    flg:boolean;
begin
if dep > n then
begin
fillchar(temp,sizeof(temp),true);
for j:= 1 to n do temp[b[j]]:=false;
flg:=true;
for j:= 1 to m do
if temp[j] then begin flg:=false; break; end;
if flg then
begin
for j:= 1 to n do write(b[j],' ');
writeln;
end;
exit;
end;
for j:= 1 to m do
begin
b[dep]:=j;
dfs(dep+1);
end;
end;

begin
assign(output,'out.txt');
rewrite(output);
readln(n,m);
for i:= 1 to n do a[i]:=i;
dfs(1);
close(output);
end.