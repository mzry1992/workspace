var k,L:longint;
    a,b,c,d,e,f,g,h,i,j:longint;
    sum:real;
begin
readln(k);
for l:= 1 to k do
 begin
 readln(a,b,c,d,e,f,g,h,i,j);
 sum:=28.9*a+32.7*b+45.6*c+78*d+35*e+86.2*f+27.8*g+43*h+56*i+65*j;
 writeln(sum:0:2);
 end;
end.