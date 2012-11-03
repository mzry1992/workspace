var fn:string;
    top,n:longint;
    s:array[1..3000] of string;

procedure shit;
var st,temp:string;
    j,i:longint;
begin
if not eof then
begin
 readln(st);
 if pos(' ',st) <> 0 then
  begin
  temp:=copy(st,1,pos(' ',st)-1);
  val(copy(st,pos(' ',st)+1,length(st)-pos(' ',st)),j);
  if j > 0 then
  begin
  inc(top);
  s[top]:=temp;
  for i:= 1 to j do shit;
  dec(top);
  end;
  end
 else
  begin
  if st = fn then
  begin
  for i:= 1 to top do write(s[i],'\');
  writeln(st);
  end;
  end;
end;
end;

begin
assign(input,'P1622.in');
assign(output,'P1622.txt');
reset(input);
rewrite(output);
readln(fn);
top:=0;
while not eof do
shit;
close(input);
close(output);
end.
