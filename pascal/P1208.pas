var t,n,m,c,i:longint;
    p:double;
begin
readln(c);
p:=(sqrt(5)+3)/2;
for i:= 1 to c do
begin
readln(n,m);
t:=trunc(n/p);
if (( m >= n-t ) and ( m <= n-1 )) or (( m >= n+1 ) and ( m <= 2*n-t-1)) then
 writeln('Ollie wins')
 else writeln('Stan wins');
end;
end.
