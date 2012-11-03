var
 i,j,m,n,k:longint;
 a,f:array[1..100,1..500]of int64;
 b,c:array[1..100,1..500]of longint;
 t:array[0..50000]of longint;
procedure print(x,y:longint);
begin
 if x=1 then writeln(y)
 else
 begin
    if b[x,y]=1 then print(x-1,y)
    else if b[x,y]=2 then print(x,y-1)
    else print(x,y+1);
    writeln(y)
 end
end;

begin
 readln(m,n);
 for i:=1 to m do
 begin
    for j:=1 to n do read(a[i,j]);
    readln
 end;
 for i:=1 to n do
 begin
    f[1,i]:=a[1,i];
    c[1,i]:=1
 end;
 for i:=2 to m do
 begin
    for j:=1 to n do
    begin
      f[i,j]:=f[i-1,j]+a[i,j];
      c[i,j]:=c[i-1,j]+1;
      b[i,j]:=1;
    end;
    for j:=2 to n do if f[i,j-1]+a[i,j]<f[i,j]then
    begin
      f[i,j]:=f[i,j-1]+a[i,j];
      c[i,j]:=c[i,j-1]+1;
      b[i,j]:=2
    end
    else if f[i,j-1]+a[i,j]=f[i,j] then
    if c[i,j-1]+1<c[i,j] then
    begin
      c[i,j]:=c[i,j-1]+1;
      b[i,j]:=2
    end;
    for j:=n-1 downto 1 do if f[i,j+1]+a[i,j]<f[i,j] then
    begin
      f[i,j]:=f[i,j+1]+a[i,j];
      c[i,j]:=c[i,j+1]+1;
      b[i,j]:=3
    end
    else if f[i,j+1]+a[i,j]=f[i,j] then
    if c[i,j+1]+1<c[i,j] then
    begin
      c[i,j]:=c[i,j+1]+1;
      b[i,j]:=3
    end;
 end;
 k:=1;
 for i:=2 to n do if f[m,i]<f[m,k] then k:=i
 else if f[m,i]=f[m,k] then if c[m,i]<c[m,k] then k:=i;
 print(m,k)
end.
