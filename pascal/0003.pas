const    ch:array[1..12,1..2] of integer = ((1,4),(2,5),(3,6),(4,7),(5,8),(6,9),(1,2),(2,3),(4,5),(5,6),(7,8),(8,9));
var w,q,top,x,now,a1,a2:longint;
    s:array[1..13,1..9] of longint;
begin
top:=1;
now:=1;
for q:= 1 to 9 do s[1,q]:=q;

   for q:= 1 to 12 do
    begin
    inc(top);
    for x:= 1 to 9 do
     s[top,x]:=s[1,x];
    a1:=ch[q,1];
    a2:=ch[q,2];
    w:=s[top,a1];
    s[top,a1]:=s[top,a2];
    s[top,a2]:=w;

    end;

for q:= 1 to 13 do
begin
 for x:= 1 to 9 do write(s[q,x],' ');
 writeln;
end;
end.