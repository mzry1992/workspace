var n,i,j,total:longint;
    a:array[1..10000] of longint;
    h:boolean;

begin
readln(n);
total:=0;
fillchar(a,sizeof(a),0);
h:=false;
for i:= 1 to n do
 begin
 read(j);
 inc(a[j]);
 if a[j] = 2 then
  begin
  if h then
   begin
   h:=false;
   inc(total);
   fillchar(a,sizeof(a),0);
   end
  else
   h:=true;
  end
 else
  if a[j] = 4 then
   begin
   h:=false;
   inc(total);
   fillchar(a,sizeof(a),0);
   end;
 end;
writeln(total);
end.