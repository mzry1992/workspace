uses crt;
var st:string;
    sp:array[1..100] of char;
    sn:array[1..100] of real;
    t,tp,n,tn
    :integer;
    number,op:set of char;

function cancal(ch:char):boolean;
begin
if (ch = '#' ) or ( ch = ')' ) then exit(true);
if ( sp[tp] = '*' ) and ( ch in ['+','-','*'] ) then exit(true);
if ( sp[tp] = '/' ) and ( ch in ['+','-','/'] ) then exit(true);
if ( sp[tp] = '^' ) and ( ch in ['+','-','*','/','^'] ) then exit(true);
if ( sp[tp] in ['+','-'] ) and ( ch in ['+','-'] ) then exit(true);
exit(false);
end;

procedure cal;
begin
case sp[tp] of
 '+' : sn[tn-1] := sn[tn-1] + sn[tn] ;
 '-' : sn[tn-1] := sn[tn-1] - sn[tn] ;
 '*' : sn[tn-1] := sn[tn-1] * sn[tn] ;
 '^' : sn[tn-1] := exp(sn[tn]*ln(sn[tn-1]));
 '/' : if sn[tn] = 0 then
       begin
       writeln('Division by zero');
       readln;
       halt;
       end
       else sn[tn-1] := sn[tn-1] / sn[tn] ;
end;

dec(tn);
dec(tp);
end;

procedure check(st:string);
var i,j:integer;
    q:array[1..100] of 0..1;
begin
for i:= 2 to length(st) do
 if ( st[i] in op ) and ( st[i-1] in op ) then
  begin
  writeln('Illegal error');
  readln;
  halt;
  end;
j:=0;
for i:= 1 to length(st) do
begin
 if st[i] = '(' then
  begin
  inc(j);
  q[j]:=0;
  if ( j > 1 ) and ( q[j-1] = 1 ) then j:=j-2 ;
  end;
 if st[i] = ')' then
  begin
  inc(j);
  q[j]:=1;
  if ( j > 1 ) and ( q[j-1] = 0 ) then j:=j-2 ;
  end;
end;
if j <> 0 then
 begin
 writeln('"(" or ")" Expected');
 readln;
 halt;
 end;
end;
begin
clrscr;
number:=['0'..'9'];
op:=['+','-','*','/','^','(',')'];
readln(st);
check(st);
st:=st+'#';
tn:=0;
tp:=1;
sp[1]:='#';
t:=1;
repeat
if st[t] in number then
begin
n:=0;
repeat
n:=n*10+ord(st[t])-48;
inc(t);
until not (st[t] in number);
inc(tn);
sn[tn]:=n;
end
else
begin
if (st[t] = '(') or not cancal(st[t]) then
 begin
 inc(tp);
 sp[tp]:=st[t];
 inc(t);
 end
else
 begin
 if st[t] = ')' then
  begin
  while sp[tp] <> '(' do cal;
  dec(tp);
  inc(t);
  end
 else cal;
 end;
end;
until ( st[t] = '#')  and ( sp[tp] = '#' ) ;
writeln(sn[1]:0:10);
repeat until keypressed;
end.
