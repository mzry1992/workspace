var
 a:array[1..10000000]of char;
 b:array[1..10000000]of longint;
 l,c,i,j,max,maxn:longint;
 ch:char;
begin
i:=0;
while not eof do
begin
  inc(i);
  read(a[i]);
  if (a[i] in ['a'..'z']) or (a[i] in ['A'..'Z']) then
  inc(b[ord(upcase(a[i]))-64]);
end;
l:=i;
for i:=1 to 26 do
if b[i]>max then begin max:=b[i];maxn:=i;end;
 c:=ord(maxn)+96-ord('e');
 for i:=1 to l do
 begin
    if a[i] in['a'..'z'] then
    begin
     write(chr((ord(a[i])-c-ord('a')+26) mod 26+ord('a')));
    end
    else
    begin
    if a[i] in['A'..'Z'] then
    begin
      write(chr((ord(a[i])-c-ord('A')+26) mod 26+ord('A')));
    end
    else write(a[i]);
    end;
 end;
end.

