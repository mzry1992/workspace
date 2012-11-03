var i,j,n,m,k,l,o,p:longint;
    q,w,e:string;
    begin
      readln(q);
      readln(n);
      while n>0 do
        begin
          i:=1;
          while (q[i]<=q[i+1])and(i<length(q)) do i:=i+1;
          delete(q,i,1);
          n:=n-1;
        end;
      while (q[1]='0')and(length(q)>1) do delete(q,1,1);
      writeln(q);
    end.
