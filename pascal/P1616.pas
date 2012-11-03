var n,k,i:integer;
    st:ansistring;
    t:longint;

procedure del;
var a:longint;
begin
a:=pos('jz',st);
if a = 0 then exit;
if st[a-1]+st[a+2] = 'jz' then exit;
st[a]:= 'a';
st[a+1]:='a';
inc(t);
del;
end;

procedure done;
var a,b,c,d,e,f:longint;
begin
writeln(st);
del;
f:=pos('jjzz',st); a:=pos('zz',st); b:=pos('jj',st); c:=pos('j',st); d:=pos('z',st); e:=pos('zj',st);
if ( f > 0 ) then
begin
 st[f+1]:='z';
 st[f+2]:='j';
 exit;
end;
if ( a > 0 ) and ( b > 0 ) then
begin
 st[a]:='j';
 st[b+1]:='z';
 exit;
end;
if ( a > 0 ) and ( c > 0 ) then
begin
 st[a]:='j';
 st[c]:='z';
 exit;
end;
if ( d > 0 ) and ( b > 0 ) then
begin
 st[d]:='j';
 st[b+1]:='z';
 exit;
end;
if ( e > 0 ) then
begin
 st[e]:='j';
 st[e+1]:='z';
 exit;
end;
end;

begin
readln(n,k);
readln(st);
t:=0;
for i:= 1 to k do done;
del;
writeln(t);
end.
