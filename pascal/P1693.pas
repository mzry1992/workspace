const
        maxn = 200;
var
        n,m,i,j,tot:longint;
        a,b:array[1..maxn] of longint;
        map:array[1..2*maxn,1..2*maxn] of boolean;
        cover:array[1..2*maxn] of boolean;
        link:array[1..2*maxn] of integer;
function        max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
function        check(i,j:longint):boolean;
var
        a,b:array[1..32] of 0..1;
        x,y,la,lb:longint;
begin
        for x := 1 to 32 do
        begin
                a[x] := i shr (x-1) and 1;
                b[x] := j shr (x-1) and 1;
        end;
        la := 32;
        while a[la] = 0 do          dec(la);
        lb := 32;
        while b[lb] = 0 do          dec(lb);
        for x := 1 to max(la,lb) do
        if a[x] = b[x] then exit(false);
        exit(true);
end;
function        find(i:integer):boolean;
var
        k,q:integer;
begin
        for k := 1 to n do
        if map[i,k] and not cover[k] then
        begin
                q := link[k];
                link[k] := i;
                cover[k] := true;
                if ( q = 0) or find(q) then     exit(true);
                link[k] := q;
        end;
        exit(false);
end;
function        KM:longint;
var
        i,tot:integer;
begin
        fillchar(link,sizeof(link),0);
        for i := 1 to n do
        begin
                fillchar(cover,sizeof(cover),false);
                find(i);
        end;
        tot := 0;
        for i := 1 to n-m do
        if link[i] <> 0 then inc(tot);
        exit(tot);
end;
begin
        readln(n,m);
        for i := 1 to n do      read(a[i]);
        readln;
        for i := 1 to m do      read(b[i]);
        readln;
        fillchar(map,sizeof(map),false);
        for i := 1 to n do
        for j := 1 to m do
        if check(a[i],b[j]) then
        begin
                map[i,n+j] := true;
                map[n+j,i] := true;
        end;
        n := n+m;
        tot := KM;
        if tot = 0 then         writeln('I want nobody nobody but you')
        else                    writeln(tot);
end.
