var n,i,l,h,x,y:integer;
    f:array[1..2000,-2000..2000] of char;
begin
fillchar(f,sizeof(f),' ');
readln(n);
f[1,0]:='/';
f[1,1]:='\';
f[2,-1]:='/';
f[2,0]:='_';
f[2,1]:='_';
f[2,2]:='\';
l:=2;
h:=2;
for i:= 2 to n do
begin
for x:= 1 to h do
 for y:= 1-l to l do
 begin
 f[h+x,y-l]:=f[x,y];
 f[h+x,y+l]:=f[x,y];
 end;
l:=2*l;
h:=2*h;
end;
for x:= 1 to h do
begin
 for y:= -l to l do
 begin
  write(f[x,y]);
 end;
writeln;
end;
end.