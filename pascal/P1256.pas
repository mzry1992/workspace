var ttt,tttt:integer;
    st,temp:ansistring;
    a:array[1..10] of string;
    b,ans:array[1..10] of longint;
    sp:array[1..100] of char;
    sn:array[1..100] of longint;
    t,tp,n,tn,l,i,nn,j:integer;
    number,op,word:set of char;
    zf:boolean;

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
number:=['0'..'9','&'];
op:=['+','-','*','/','(',')'];
word:=['a'..'z','A'..'Z'];
readln(ttt);
for tttt:= 1 to ttt do
 begin
 readln(st);
 readln(nn);
 for i:= 1 to nn do
  begin
  readln(temp);
  a[i]:=copy(temp,1,pos('=',temp)-2);
  val(copy(temp,pos('=',temp)+2,length(temp)-pos('=',temp)-1),b[i]);
  end;
 for i:= 1 to nn-1 do
  for j:= i+1 to nn do
   if length(a[i]) > length(a[j]) then
    begin
    temp:=a[i]; a[i]:=a[j]; a[j]:=temp;
    t:=b[i]; b[i]:=b[j]; b[j]:=t;
    end;
  l:=length(st);
  i:=1; if st[i] = '-' then st[i]:='&';
  repeat
   inc(i);
   if st[i] = '-' then
    if st[i-1] in op then
     st[i]:='&';
  until i = l ;
st:=st+'#';
tn:=0;
tp:=1;
sp[1]:='#';
t:=1;
repeat
if st[t] in word then
 begin
 for i:= 1 to nn do
  begin
  temp:=copy(st,t,length(a[i])+1-t);
  if temp = a[i] then
   n:=b[i];
  end;
 inc(tn);
 sn[tn]:=n;
 end;
if st[t] = '&' then begin zf:=false; inc(t); end;
if st[t] in number then
begin
n:=0;
repeat
n:=n*10+ord(st[t])-48;
inc(t);
until not (st[t] in number);
inc(tn);
if not zf then n:=-n;
sn[tn]:=n;
zf:=true;
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
ans[tttt]:=sn[1];
end;
for tttt:= 1 to ttt do
 begin
 writeln('Scenario #',tttt,':');
 writeln(ans[tttt]);
 end;
end.