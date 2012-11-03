var
        f,p,l:array[1..30000] of longint;
        t,tt,i,j:longint;
        order:char;
        count:longint;

function findf(x:longint):longint;
var
        t:longint;
begin
        if f[x] = x then        exit(x);
        t := findf(f[x]);
        p[x] := p[x]+p[f[x]];
        f[x] := t;
        exit(f[x]);
end;

procedure       O(x:longint);
begin
        inc(count);
        write(x);
        if count mod 20000 = 0 then     writeln;
end;

procedure       M(i,j:longint);
var
        f1,f2:longint;
begin
        f1 := findf(i);
        f2 := findf(j);
        f[f1] := f2;
        p[f1] := l[f2];
        l[f2] := l[f2]+l[f1];
end;

procedure       C(i,j:longint);
var
        f1,f2:longint;
begin
        f1 := findf(i);
        f2 := findf(j);
        if f1 = f2 then
                O(abs(p[i]-p[j])-1)
        else
                O(-1);
end;

begin
        count := 0;
        for i := 1 to 30000 do
        begin
                f[i] := i;
                p[i] := 0;
                l[i] := 1;
        end;
        readln(t);
        for tt := 1 to t do
        begin
                readln(order,i,j);
                case    order   of
                        'M'     :       M(i,j);
                        'C'     :       C(i,j);
                end;
        end;
        writeln;
end.