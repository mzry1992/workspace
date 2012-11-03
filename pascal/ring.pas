program ring;
procedure       setinput;
begin
        assign(input,'ring.in');
        assign(output,'ring.out');
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(input);
        close(output);
end;
var
        n,m,i,j,k,q,x,y,res,tot:longint;
        mp:longint;
        f:array[0..300,0..300,0..300] of longint;
        sum:array[0..300,0..300] of longint;
function        max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
procedure       main;
begin
        readln(n,m);
        fillchar(f,sizeof(f),0);
        for i := 1 to n do
        begin
                sum[i,0] := 0;
                for j := 1 to m do
                begin
                        read(mp);
                        sum[i,j] := sum[i,j-1]+mp;
                        f[i,i,j] := mp;
                end;
                readln;
        end;
        res := 0;
        for i := 1 to m do
        for j := i to m do
        for k := 1 to n do
        begin
                f[i,j,k] := max(f[i,j,k-1]+sum[k,j]-sum[k,i-1],sum[k,j]-sum[k,i-1]);
                if f[i,j,k] > res then  res := f[i,j,k];
        end;
        writeln(res);
end;
begin
        setinput;
        main;
        setoutput;
end.

