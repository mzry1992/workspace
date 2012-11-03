var n:string;
    m,k:int64;
begin
readln(n);
readln(m);
val(copy(n,length(n)-m+1,m),k);
k:=3*k+1;
writeln(k mod (1 shl m));
end.