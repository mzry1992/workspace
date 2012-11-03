const
  aaa:array[1..13] of string
   = ('','W','Y','WY','YY','WYY','YYY','WYYY','YYYY','WYYYY','YYYYY','WYYYYY','YYYYYY');
var st,zs,xs:string;
    a:array[0..50] of char;
    b:array[1..50,1..4] of char;
    l,i,j,x,y,z:longint;
    flg,xsflg,flg2,flg3:boolean;
begin
readln(st);
l:=length(st);
if st[1] = '-' then begin write('F') ; st:=copy(st,2,l-1); end;
if st[1] = '+' then begin st:=copy(st,2,l-1); end;
if st[1] = '.' then
 begin
 writeln('0D',copy(st,2,l-1));
 halt;
 end;
l:=length(st);

while ( st[1] = '0' ) and ( 1 <= l ) do
begin
 st:=copy(st,2,l-1);
 l:=length(st);
end;
if 1 > l then begin writeln('0') ; halt; end;

if st[length(st)] = '.' then st:=copy(st,1,length(st)-1);
l:=length(st);
xsflg:=false;
for i:= 1 to l do
 if st[i] = '.' then
  begin
  zs:=copy(st,1,i-1);
  xsflg:=true;
  break;
  end;
if zs= '' then zs:=st;
xs:=copy(st,i+1,l-i);

l:=length(zs);
i:=4;
j:=1;
while l > 0 do
 begin
 b[j,i]:=st[l];
 dec(l);
 dec(i);
 if i = 0 then
  begin
  i:=4;
  inc(j);
  end;
 end;
if not ( b[j,4] in ['0'..'9'] ) then dec(j);
for x:= j downto 1 do
begin
flg:=true;
 for y:= 1 to 4 do
  begin
  if  b[x,y] in ['1'..'9'] then
   begin
   write(b[x,y]);
   case y of
   1 : write('Q');
   2 : write('B');
   3 : write('S');
   end;
   flg:=true;
   end;
   flg2:=true;
   for z:= y to 4 do if b[x,z] in ['1'..'9'] then flg2:=false;
  if not flg2 then
  if b[x,y] = '0' then
   if flg then
    begin
    write('0');
    flg:=false;
    end;
  end;
flg2:=true;
for y:= 1 to 4 do
 if b[x,y] in ['1'..'9'] then flg2:=false;
if not flg2 then
write(aaa[x]);
end;
if xsflg then
 begin
 write('D');
 writeln(xs);
 end
else
writeln;
end.
