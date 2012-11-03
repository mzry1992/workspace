const op : set of char = ['+','-','*','/'];
      nu : set of char = ['A'..'Z'];
var   st : string;
      sn : array[1..200] of string;
      sp : array[1..200] of char;
      l,i,tn,tp : longint;

function check(st:string):boolean;
var l,i,ap : longint;
    flg : boolean;
begin
flg:=true;
l:=length(st); i:=0; ap:=0;
repeat
inc(i);
if st[i] = '(' then flg:=false;
if st[i] = ')' then flg:=true;
if st[i] in op then
 if flg then
  if st[i] in ['+','-'] then exit(false);
until i = l ;
exit(true);
end;

function doop(s1,s2:string;top:char):string;
var f1,f2 : boolean;
begin
f1:=check(s1);
f2:=check(s2);
if top = '/' then
if length(s2) > 1 then
f2:=false;
if top in ['-','*','/'] then
begin
if not f1 then s1:='('+s1+')';
if not f2 then s2:='('+s2+')';
end;
exit(s1+top+s2);
end;

procedure cal;
var top : char;
    flg,flg2 : boolean;
    i,j : longint;
begin
top:=sp[tp];
sn[tn-1]:=doop(sn[tn-1],sn[tn],top);
dec(tn); dec(tp);
end;

begin
readln(st);
l:=length(st);
i:=0; tn:=0; tp:=0;
repeat
inc(i);
if st[i] in nu then
 begin
 inc(tn);
 sn[tn]:=st[i];
 end;
if st[i] in op then
 begin
 inc(tp);
 sp[tp]:=st[i];
 cal;
 end;
until i = l;
writeln(sn[1]);
end.