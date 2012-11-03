var
        n,m,i,j,k,q,tmax,tmin:longint;
        temp,a:array[1..50] of longint;
        fb,fs:array[0..50,1..9] of longint;
        sum:array[0..50,1..50] of longint;
function        max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;
function        min(a,b:longint):longint;
begin
        if a < b then exit(a);
        exit(b);
end;
begin
        tmin := 19930713;
        tmax := 0;
        readln(n,m);
        for i := 1 to n do      readln(temp[i]);
        for q := 1 to n do
        begin
                for i := q to n do      a[i+1-q] := temp[i];
                for i := 1 to q-1 do    a[n-q+1+i] := temp[i];
                fillchar(sum,sizeof(sum),0);
                for i := 1 to n do
                for j := i to n do
                        sum[i,j] := ((sum[i,j-1]+a[j]) mod 10 + 10) mod 10;
                for i := 0 to n do
                for j := 0 to m do
                begin
                        fb[i,j] := 0;
                        fs[i,j] := 19930713;
                end;
                for i := 1 to n do
                begin
                        fb[i,1] := sum[1,i];
                        fs[i,1] := sum[1,i];
                end;
                for k := 2 to m do
                for i := k to n do
                for j := 1 to i-1 do
                begin
                        fb[i,k] := max(fb[i,k],fb[j,k-1] * sum[j+1,i]);
                        fs[i,k] := min(fs[i,k],fs[j,k-1] * sum[j+1,i]);
                end;
                tmax := max(tmax,fb[n,m]);
                tmin := min(tmin,fs[n,m]);
        end;
        writeln(tmin);
        writeln(tmax);
end.
