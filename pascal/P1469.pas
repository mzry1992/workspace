var     a,n:array[1..65535] of longint;
        i,j,k:longint;

procedure       qsort(l,r:longint);
var     m,i,j,temp:longint;
begin
i:=l;   j:=r;   m:=n[(l+j) div 2];
repeat
while n[i] < m do inc(i);
while n[j] > m do dec(j);
if i <= j then
begin
temp:=n[i];     n[i]:=n[j];     n[j]:=temp;
inc(i);
dec(j);
end;
until i > j ;
if i < r then qsort(i,r);
if l < j then qsort(l,j);
end;

procedure       done(top,l,r:longint);
begin
a[top]:=n[l];
inc(l);
if 2 * top < k then
begin
        done(2*top,(l+r) div 2+1,r);
        done(2*top+1,l,(l+r) div 2);
end;
end;

begin
readln(k);
for i := 1 to k do read(n[i]);
readln;
qsort(1,k);
done(1,1,k);
for i := 1 to k do write(a[i],' ');
writeln;
end.