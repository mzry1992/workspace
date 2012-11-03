var ans1,ans2:qword;
    n,a,b,i:integer;
begin
readln(n,a,b);
ans1:=1; ans2:=1;
for i:= n+1 to n+a do ans1:=trunc((ans1*i)/(i-n));
for i:= n+1 to n+b do ans2:=trunc((ans2*i)/(i-n));
writeln(ans1*ans2);
end.