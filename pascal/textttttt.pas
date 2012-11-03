var a,b,temp:string;

begin
a:='1001221010';


  b:=a;
  temp:=copy(b,1,2);
  delete(b,1,2);
  insert('22',b,1);
  delete(b,5,2);
  insert(temp,b,5);
  temp:=b;
writeln(temp);
writeln(5/0);
end.
