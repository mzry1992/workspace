var
        n,i,min,k1,k2,k3:longint;
        f:array[0..100,0..10,0..10,0..10] of longint;
        a:array[1..100] of char;

function tmin(a,b:longint):longint;
begin
        if a < b then exit(a);
        exit(b);
end;

function dfs(dep,time,numA,numB,numC:longint):longint;
var
        i,use,k1,k2,k3,temp:longint;
begin

        if f[time,numA,numB,numC] <> 0 then exit(f[time,numA,numB,numC]);

        if time = n then
        begin
                if dep < min then min := dep;
                exit(dep);
        end;

        use := time + numA + numB + numC;

        k1 := 0;        k2 := 0;        k3 := 0;
        for i := use + 1 to tmin(use+numA,n) do
        begin
                if a[i] = 'A' then inc(k1);
                if a[i] = 'B' then inc(k2);
                if a[i] = 'C' then inc(k3);
        end;
              temp := dfs(dep+1,time+numA,k1,numB+k2,numC+k3);

        k1 := 0;        k2 := 0;        k3 := 0;
        for i := use + 1 to tmin(use+numB,n) do
        begin
                if a[i] = 'A' then inc(k1);
                if a[i] = 'B' then inc(k2);
                if a[i] = 'C' then inc(k3);
        end;
              temp := tmin(temp,dfs(dep+1,time+numB,numA+k1,k2,numC+k3));

        k1 := 0;        k2 := 0;        k3 := 0;
        for i := use + 1 to tmin(use+numC,n) do
        begin
                if a[i] = 'A' then inc(k1);
                if a[i] = 'B' then inc(k2);
                if a[i] = 'C' then inc(k3);
        end;
              temp := tmin(temp,dfs(dep+1,time+numC,numA+k1,numB+k2,k3));

        f[time,numA,numB,numC] := temp;

end;

begin
        readln(n);
        for i := 1 to n do
                readln(a[i]);
        k1 := 0;        k2 := 0;        k3 := 0;
        for i := 1 to 10 do
        begin
                if a[i] = 'A' then inc(k1);
                if a[i] = 'B' then inc(k2);
                if a[i] = 'C' then inc(k3);
        end;
        fillchar(f,sizeof(f),0);
        min := maxlongint;
        dfs(0,0,k1,k2,k3);
        writeln(min);
end.

