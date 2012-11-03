var st:string;
    i,j,a1,a2,a3,a4,a5,b1,b2,b3,b4,b5:longint;

procedure calculate(st:string;var a1,a2,a3,a4,a5 : longint);
var sp:array[1..100] of char;
    sn:array[1..5,1..100] of longint;
    tn:array[1..5] of longint;
    t,tp,n:integer;
    number,op:set of char;

function mc(a,b:integer):longint;
var temp,cc:longint;
begin
temp := 1 ;
for cc:= 1 to b do temp:=temp*a;
exit(temp);
end;

function cancal(ch:char):boolean;
begin
if (ch = '#' ) or ( ch = ')' ) then exit(true);
if ( sp[tp] = '*' ) and ( ch in ['+','-'] ) then exit(true);
if ( sp[tp] = '^' ) and ( ch in ['+','-','*'] ) then exit(true);
exit(false);
end;

procedure cal;
begin
case sp[tp] of
 '+' :
 begin
 sn[1,tn[1]-1] := sn[1,tn[1]-1] + sn[1,tn[1]] ;
 sn[2,tn[2]-1] := sn[2,tn[2]-1] + sn[2,tn[2]] ;
 sn[3,tn[3]-1] := sn[3,tn[3]-1] + sn[3,tn[3]] ;
 sn[4,tn[4]-1] := sn[4,tn[4]-1] + sn[4,tn[4]] ;
 sn[5,tn[5]-1] := sn[5,tn[5]-1] + sn[5,tn[5]] ;
 end;
 '-' :
 begin
 sn[1,tn[1]-1] := sn[1,tn[1]-1] - sn[1,tn[1]] ;
 sn[2,tn[2]-1] := sn[2,tn[2]-1] - sn[2,tn[2]] ;
 sn[3,tn[3]-1] := sn[3,tn[3]-1] - sn[3,tn[3]] ;
 sn[4,tn[4]-1] := sn[4,tn[4]-1] - sn[4,tn[4]] ;
 sn[5,tn[5]-1] := sn[5,tn[5]-1] - sn[5,tn[5]] ;
 end;
 '*' :
 begin
 sn[1,tn[1]-1] := sn[1,tn[1]-1] * sn[1,tn[1]] ;
 sn[2,tn[2]-1] := sn[2,tn[2]-1] * sn[2,tn[2]] ;
 sn[3,tn[3]-1] := sn[3,tn[3]-1] * sn[3,tn[3]] ;
 sn[4,tn[4]-1] := sn[4,tn[4]-1] * sn[4,tn[4]] ;
 sn[5,tn[5]-1] := sn[5,tn[5]-1] * sn[5,tn[5]] ;
 end;
 '^' :
 begin
 sn[1,tn[1]-1] := mc(sn[1,tn[1]-1],sn[1,tn[1]]);
 sn[2,tn[2]-1] := mc(sn[2,tn[2]-1],sn[1,tn[2]]);
 sn[3,tn[3]-1] := mc(sn[3,tn[3]-1],sn[1,tn[3]]);
 sn[4,tn[4]-1] := mc(sn[4,tn[4]-1],sn[1,tn[4]]);
 sn[5,tn[5]-1] := mc(sn[5,tn[5]-1],sn[1,tn[5]]);
 end;
end;
dec(tn[1]);
dec(tn[2]);
dec(tn[3]);
dec(tn[4]);
dec(tn[5]);
dec(tp);
end;

begin
number:=['0'..'9'];
op:=['+','-','*','^','(',')'];
st:=st+'#';
tn[1]:=0;
tn[2]:=0;
tn[3]:=0;
tn[4]:=0;
tn[5]:=0;
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
inc(tn[1]);
sn[1,tn[1]]:=n;
inc(tn[2]);
sn[2,tn[2]]:=n;
inc(tn[3]);
sn[3,tn[3]]:=n;
inc(tn[4]);
sn[4,tn[4]]:=n;
inc(tn[5]);
sn[5,tn[5]]:=n;
end
else
begin
if st[t] = 'a' then
begin
inc(tn[1]);
sn[1,tn[1]]:=-2;
inc(tn[2]);
sn[2,tn[2]]:=-1;
inc(tn[3]);
sn[3,tn[3]]:=0;
inc(tn[4]);
sn[4,tn[4]]:=1;
inc(tn[5]);
sn[5,tn[5]]:=2;
inc(t);
end;
if st[t] = ' ' then inc(t);
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
a1:=sn[1,1];
a2:=sn[2,1];
a3:=sn[3,1];
a4:=sn[4,1];
a5:=sn[5,1];
end;

begin
readln(st);
calculate(st,a1,a2,a3,a4,a5);
writeln(a1,' ',a2,' ',a3,' ',a4,' ',a5);
readln(i);
for j:= 1 to i do
begin
readln(st);
calculate(st,b1,b2,b3,b4,b5);
writeln(b1,' ',b2,' ',b3,' ',b4,' ',b5);
if ((a1=b1) and (a2=b2) and (a3=b3) and (a4=b4) and (a5=b5)) then write(chr(ord('A')-1+j));
end;
writeln;
end.
