var k,s1,s2,s3,i,j:longint;
begin
readln(k);
s1:=0;
s2:=0;
s3:=0;
for i:= 1 to k do
 begin
 read(j);
 if j = 1 then inc(s1);
 if j = 5 then inc(s2);
 if j = 10 then inc(s3);
 end;
writeln(s1);
writeln(s2);
writeln(s3);
end.