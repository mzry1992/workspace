const max = 9 ;
var a:array[1..max] of longint;
    use:array[1..max] of boolean;
    total,i,j,ans,k:longint;
begin
fillchar(use,sizeof(use),true);
for i:= 1 to max do readln(a[i]);
ans:=0;
for i:= 1 to max do
 begin
 use[a[i]]:=false;
 total:=0;
 for j:= 1 to a[i] - 1  do
  if use[j] then inc(total);
 k:=1;
 for j:= 1 to a[i] - 1 do k:=k*j;
 ans:=ans+k*total;
 end;
writeln(ans+1);
end.
