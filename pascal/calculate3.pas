var st:string;
    sp:array[1..100] of char;
    sn:array[1..100] of longint;
    t,tp,n,tn,l,i:integer;
    number,op:set of char;

function cancal(ch:char):boolean;
begin
if (ch = '#' ) or ( ch = ')' ) then exit(true);
if ( sp[tp] = '*' ) and ( ch in ['+','-'] ) then exit(true);
if ( sp[tp] = '/' ) and ( ch in ['+','-'] ) then exit(true);
exit(false);
end;

procedure cal;
begin
case sp[tp] of
 '+' : sn[tn-1] := sn[tn-1] + sn[tn] ;
 '-' : sn[tn-1] := sn[tn-1] - sn[tn] ;
 '*' : sn[tn-1] := sn[tn-1] * sn[tn] ;
 '/' : sn[tn-1] := sn[tn-1] div sn[tn] ;
end;

dec(tn);
dec(tp);
end;

begin
number:=['0'..'9'];
op:=['+','-','*','/','(',')'];
readln(st);
l:=length(st);
i:=0;
repeat
inc(i);
if st[i] = '-' then
begin
 if i = 1 then
  begin
  st:='0'+st;
  inc(i);
  inc(l);
  end
 else
  begin
  if st[i-1] = '(' then
   begin
   insert('0',st,i);
   inc(i);
   inc(l);
   end;
  end;
end;
until i = l ;
st:=st+'#';
writeln(st);
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
if st[t] in ['+','-'] then
 if sp[tp] in ['-','+'] then cal;
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
writeln(sn[1]);
end.
