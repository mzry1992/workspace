var a,d:array[1..500,1..500] of integer;
    i,j,k,xx,yy,m,n,x,y:integer;
    ch:char;
procedure fill(x,y:integer);
var i,j:integer;
begin
d[x,y]:=43;
d[x,y+4]:=43;
d[x-3,y]:=43;
d[x-3,y+4]:=43;
d[x-2,y+6]:=43;
d[x-5,y+2]:=43;
d[x-5,y+6]:=43;     {+}
for i:= 1 to 3 do
begin
d[x,y+i]:=45;
d[x-5,y+i+2]:=45;
d[x-3,y+i]:=45;       {-}
end;
d[x-1,y]:=124;
d[x-2,y]:=124;
d[x-1,y+4]:=124;
d[x-2,y+4]:=124;
d[x-3,y+6]:=124;
d[x-4,y+6]:=124;        {|}
d[x-1,y+5]:=47;
d[x-4,y+1]:=47;
d[x-4,y+5]:=47;         {/}
for i:= 1 to 3 do
for j:= 1 to 2 do
begin
  d[x-j,y+i]:=32;
  d[x-4,y+1+i]:=32;
  d[x-1-j,y+5]:=32;
end;                   { }
end;
procedure init;
var x,y:integer;
begin
readln(m,n);
for x:= 1 to m do
 begin
  for y:= 1 to n do
   read(a[m-x+1,y]);
 readln
 end;
for x:= 1 to 500 do
 for y:= 1 to 500 do
  d[x,y]:=46;
end;
begin
init;
x:=500;
y:=0;
for i:= m downto 1 do
 for j:= 1 to n do
  for k:= 1 to a[i,j] do
   begin
   xx:= 500 - ( i-1 ) * 2 - (k-1) * 3 ;
   yy:= 1 + ( i-1 ) * 2 + ( j-1 ) * 4 ;
   if yy + 6 > y then y:= yy + 6 ;
   if xx - 5 < x then x:= xx - 5 ;
   fill(xx,yy);
   end;
for i:= x to 500 do
 begin
 for j:= 1 to y do
 begin
 ch:=chr(d[i,j]);
 write(ch);
 end;
 writeln
 end;
readln
end.