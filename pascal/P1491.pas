const fst:array[0..9,1..5,1..3] of integer=(((1,1,1),(1,0,1),(1,0,1),(1,0,1),(1,1,1))
                                           ,((0,0,1),(0,0,1),(0,0,1),(0,0,1),(0,0,1))
                                           ,((1,1,1),(0,0,1),(1,1,1),(1,0,0),(1,1,1))
                                           ,((1,1,1),(0,0,1),(1,1,1),(0,0,1),(1,1,1))
                                           ,((1,0,1),(1,0,1),(1,1,1),(0,0,1),(0,0,1))
                                           ,((1,1,1),(1,0,0),(1,1,1),(0,0,1),(1,1,1))
                                           ,((1,1,1),(1,0,0),(1,1,1),(1,0,1),(1,1,1))
                                           ,((1,1,1),(0,0,1),(0,0,1),(0,0,1),(0,0,1))
                                           ,((1,1,1),(1,0,1),(1,1,1),(1,0,1),(1,1,1))
                                           ,((1,1,1),(1,0,1),(1,1,1),(0,0,1),(1,1,1)));

var a:array[1..5,1..500] of integer;
    d:array[1..500,1..500] of integer;
    i,j,k,xx,yy,m,n,x,y,hi:integer;
    ch:char;
    num:string;

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

procedure fill2(x,y,n,hi:integer);
var i,j:integer;
begin
for i:= 1 to 5 do
 for j:= 1 to 3 do
  a[6-(x-1+i),y-1+j]:=fst[n,i,j]*hi;
end;

procedure init;
var x,y,l,i,j:integer;
begin
readln(hi);
readln(num);
if num = '' then
 begin
 writeln('......');
 writeln('......');
 writeln('......');
 writeln('......');
 writeln('......');
 writeln('......');
 halt;
 end;
l:=length(num);
x:=1;
y:=1;
for i:= 1 to l do
begin
 fill2(x,y,ord(num[i])-ord('0'),hi);
 y:=y+5;
end;
m:=5;
n:=y-3;
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
if hi = 0 then 
begin 
writeln('.......................');
writeln('.......................');
writeln('.......................');
writeln('.......................');
writeln('.......................');
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
