var i,j,k,l,m,n,min,ans,num1,num2:longint;
    a,b:array[1..10] of 0..9;
begin
read(n);
for i:=1 to n do
 begin
  read(m);
  for j:=1 to m do read(a[j]);
  if m=2 then writeln(abs(a[1]-a[2]))
    else
     begin
      for j:=1 to m-1 do
       for k:=j+1 to m do
        if a[j]>a[k] then
         begin
          l:=a[j];
          a[j]:=a[k];
          a[k]:=l;
         end;
      if m mod 2=0 then
       begin
        min:=10;
        for j:=1 to m-1 do
         if a[j]<>0 then if a[j+1]-a[j]<min then min:=a[j+1]-a[j];
        ans:=2000000000;
        for j:=1 to m-1 do if a[j]<>0 then
         if a[j+1]-a[j]=min then
          begin
           num1:=a[j+1];
           num2:=a[j];
           b:=a;
           for k:=j+2 to m do
            b[k-2]:=b[k];
           for k:=1 to (m-2) div 2 do
            num1:=num1*10+b[k];
           for k:=m-2 downto (m-2) div 2+1 do
            num2:=num2*10+b[k];
           if num1-num2<ans then ans:=num1-num2;
          end;
       end;
       if m mod 2=1 then
        begin
         ans:=2000000000;
         if a[1]=0 then
          begin
           num1:=a[2];num2:=0;
           b[1]:=a[1];
           for k:=3 to m do
            b[k-1]:=a[k];
          end else
          begin
           num1:=a[1];num2:=0;
           for k:=2 to m do
            b[k-1]:=a[k];
          end;
          for k:=1 to (m-1) div 2 do num1:=num1*10+b[k];
           for k:=m-1 downto (m-1) div 2+1 do num2:=num2*10+b[k];
           if num1-num2<ans then ans:=num1-num2;
        end;
      writeln(ans);
     end;
 end;
end.