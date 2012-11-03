var np,i,j,num,k,sum,m,n:integer;
    na:array[1..10] of string;
    a,b:array[1..10] of longint;
    nam,tnam:string;
begin
readln(np);
for i:= 1 to np do readln(na[i]);
for i:= 1 to np do
 begin
 readln(nam);
 for j:= 1 to np do
  if na[j] = nam then num:=j;
 readln(sum,k);
 if k = 0 then a[num]:=0
  else a[num]:= sum - sum mod k ;
 for j:= 1 to k do
  begin
  readln(tnam);
  for m:= 1 to np do
   if na[m] = tnam then
    b[m]:= b[m] + sum div k ;
  end;
 end;
for i:= 1 to np do writeln(na[i],' ',b[i]-a[i]);
end.
