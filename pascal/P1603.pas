type
        matrixtype = array[1..50,1..50] of longint;
var
        n,i,j:longint;
        m,s,f,p:longint;
        base,ans:matrixtype;
function matrix(a,b:matrixtype;n,p:longint):matrixtype;
var
        i,j,k:longint;
        temp:matrixtype;
begin
        fillchar(temp,sizeof(temp),0);
        for i := 1 to n do
        for j := 1 to n do
        for k := 1 to n do
                temp[i,j] := (temp[i,j]+a[i,k]*b[k,j]) mod p;
        exit(temp);
end;

procedure roll(x:longint);
begin
        if x = 1 then   ans := base
        else
        begin
                roll(x shr 1);
                ans := matrix(ans,ans,n,p);
                if (x and 1) = 1 then
                        ans := matrix(ans,base,n,p);
        end;
end;

begin
        readln(n);
        for i := 1 to n do
        begin
                for j := 1 to n do      read(base[i,j]);
                readln;
        end;
        readln(m,s,f,p);
        roll(m);
        writeln(ans[s,f]);
end.