var a,b,m,k,ta,tb:int64;
    ttt:longint;
begin
for ttt:= 1 to 10 do
 begin
 readln(ta,tb);
 a:=ta;
 b:=tb;
 m:=ta mod tb;
 while m <> 0 do
  begin
  a:=b;
  b:=m;
  m:=a mod b;
  end;
 writeln(ta+tb-b);
 end;
end.

