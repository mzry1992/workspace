var a:array[0..100,0..100]of char; p:array['A'..'Z']of boolean; t:array['A'..'Z']of longint;
     f:array[0..100,0..100,0..10]of longint; n,i,j,k,s:longint; c:char;
function min1(a,b:longint):longint;
  begin if a<b then min1:=a else min1:=b; end;
function min2(a,b,c:longint):longint;
  var t:longint;
  begin
     if a<b then t:=a else t:=b;if t<c then min2:=t else min2:=c;
  end;
begin
  readln(n);fillchar(a,sizeof(a),' ');
  for i:=1 to n do
     begin
       for j:=1 to n do read(a[i,j]);readln;
     end;
  for i:=n downto 1 do
     for j:=n downto 1 do
       begin
         if (a[i,j+1]=a[i,j])and(a[i+1,j]=a[i,j]) then
           f[i,j,1]:=min1(f[i,j+1,1],f[i+1,j,1])+1;
         if (a[i,j+1]=a[i,j])and(a[i+1,j+1]=a[i,j]) then
           f[i,j,2]:=min1(f[i,j+1,2],f[i+1,j+1,2])+1;
         if (a[i+1,j]=a[i,j])and(a[i+1,j+1]=a[i,j]) then
           f[i,j,3]:=min1(f[i+1,j,3],f[i+1,j+1,3])+1;
         if (a[i+1,j]=a[i,j])and(a[i+1,j-1]=a[i,j]) then
           f[i,j,4]:=min1(f[i+1,j,4],f[i+1,j-1,4])+1;
         if (a[i+1,j-1]=a[i,j])and(a[i+1,j]=a[i,j])and(a[i+1,j+1]=a[i,j]) then
           f[i,j,5]:=min2(f[i+1,j-1,5],f[i+1,j,5],f[i+1,j+1,5])+1;
         if (a[n-i+1-1,n-j+1-1]=a[n-i+1,n-j+1])and(a[n-i+1-1,n-j+1]=a[n-i+1,n-j+1])and(a[n-i+1-1,n-j+1+1]=a[n-i+1,n-j+1]) then
           f[n-i+1,n-j+1,6]:=min2(f[n-i+1-1,n-j+1-1,6],f[n-i+1-1,n-j+1,6],f[n-i+1-1,n-j+1+1,6])+1;
         if (a[j-1,i+1]=a[j,i])and(a[j,i+1]=a[j,i])and(a[j+1,i+1]=a[j,i]) then
           f[j,i,7]:=min2(f[j-1,i+1,7],f[j,i+1,7],f[j+1,i+1,7])+1;
         if (a[n-j+1-1,n-i+1-1]=a[n-j+1,n-i+1])and(a[n-j+1,n-i+1-1]=a[n-j+1,n-i+1])and(a[n-j+1+1,n-i+1-1]=a[n-j+1,n-i+1]) then
           f[n-j+1,n-i+1,8]:=min2(f[n-j+1-1,n-i+1-1,8],f[n-j+1,n-i+1-1,8],f[n-j+1+1,n-i+1-1,8])+1;
       end;
  fillchar(p,sizeof(p),false);
  for i:=1 to n do
     for j:=1 to n do
       for k:=1 to 8 do
         begin
           p[a[i,j]]:=true;
           inc(t[a[i,j]],f[i,j,k]);inc(s,f[i,j,k]);inc(f[i,j,0],f[i,j,k]);
         end;
  writeln(s);
  for c:='A' to 'Z' do if p[c] then writeln(c,' ',t[c]);
end.
