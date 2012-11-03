var
        n,i,j,k:longint;
        a:array[1..2000] of longint;
        f:array[0..2000,0..1] of longint;
function max(a,b:longint):longint;
begin
        if a > b then exit(a);
        exit(b);
end;
begin
        readln(n);
        for i := 1 to n do      read(a[i]);
        readln;