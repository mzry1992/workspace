var a:array[1..30000] of longint;
    boy:array[1..30000] of boolean;
    top,n,k,i,j:longint;
begin
readln(n);
fillchar(boy,sizeof(boy),true);
for k:= 1 to n do read(a[k]);
readln;
for k:= 1 to n do
 for i:= a[k]  downto 1 do
  if boy[i] then
  begin
  write(a[k] - i + 1,' ');
  boy[i]:=false;
  break;
  end;
end.



