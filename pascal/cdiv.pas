var b,i,l1,l2,k1,k2,t,x:longint;
    a1,a2,s:array[1..100] of longint;

function check:boolean;
var i:integer;
begin
for i:=100 downto 1 do if a1[i]<>0 then break;
if a1[i]<0 then begin exit(false);end;
if l1<l2 then begin inc(t);exit(false); end;
if l1=l2 then
for i:=l1 downto 1 do if a1[i]>a2[i] then exit(true) else if a1[i]<a2[i] then begin  t:=t+1;exit(false);end;
exit(true);
end;

begin
readln(l1);k1:=l1+1;
for i:=1 to l1 do
begin
dec(k1);
read(x);
a1[k1]:=x;
end;
readln(l2);k2:=l2+1;
for i:=1 to l2 do
begin
dec(k2);
read(x);
a2[k2]:=x;
end;
t:=0;
while true do
begin
inc(t);
fillchar(s,sizeof(s),0);
for i:=1 to l1 do
begin
s[i]:=s[i]+a1[i]-a2[i];
if (s[i]<0) then begin s[i]:=s[i]+10;s[i+1]:=s[i+1]-1;end;
end;
a1:=s;
for i:=l1 downto 1 do if a1[i]<>0 then break;
if a1[l1]<0 then break else l1:=i;
if check then continue else begin dec(t);break;end;
end;
writeln(t);
end.
