var n,i,j,tt:longint;
    s,fs:array[1..3] of ansistring;
    sk1,sk2:array[1..3,0..6] of ansistring;
procedure done(st:ansistring;now:longint);
var i,j,k,m:longint;
    temp1,temp2,temp:ansistring;
begin
temp:=st;
for i:= 1 to n div 2 do
begin
temp[i]:=st[n+1-i]; temp[n+1-i]:=st[i];
end;
fs[now]:=temp;
for k:= 1 to 6 do
begin
temp1:=st;
temp2:=st;
for j:= 1 to n do
 begin
 m:=ord(st[j])+k;
 if m > ord('z') then m:= m-ord('z')+ord('a')-1;
 temp1[j]:=chr(m);
 m:=ord(st[j])-k;
 if m < ord('a') then m:= m-ord('a')+ord('z')+1;
 temp2[j]:=chr(m);
 end;
sk1[now,k]:=temp1;
sk2[now,k]:=temp2;
end;
end;
procedure check(a1,a2,a3:ansistring);
begin
if a1 = a2 then
 if a2 = a3 then
  begin
  writeln(a1);
  halt;
  end;
end;
begin
readln(n);
readln(s[1]); readln(s[2]); readln(s[3]);
sk1[1,0]:=s[1]; sk1[2,0]:=s[2]; sk1[3,0]:=s[3];
sk2[1,0]:=s[1]; sk2[2,0]:=s[2]; sk2[3,0]:=s[3];
done(s[1],1); done(s[2],2); done(s[3],3);
for j:= 0 to 6 do
begin
check(fs[1],sk1[2,j],sk2[3,j]);
check(fs[1],sk1[3,j],sk2[2,j]);
check(fs[2],sk1[1,j],sk2[3,j]);
check(fs[2],sk1[3,j],sk2[1,j]);
check(fs[3],sk1[1,j],sk2[2,j]);
check(fs[3],sk1[2,j],sk2[1,j]);
end;
end.