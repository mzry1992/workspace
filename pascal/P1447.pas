type arr = array[1..200] of integer;
var n,a,b:arr;
    st:string;
    i,l:integer;
begin
readln(st);
l:=length(st);
for i:= 1 to l do
 n[l+1-i]:=ord(st[i])-ord('0');
end.
