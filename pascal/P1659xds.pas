type
        node = record
                l,r,lc,rc,val,max:longint;
        end;
var
        t:array[1..200000] of node;
        n,m,i,tot,k,l,r,c,tmax,count:longint;
function max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
procedure creat(l,r:longint);
var
        mid,now:longint;
begin
        inc(tot);
        now := tot;
        t[now].l := l;
        t[now].r := r;
        mid :=  (l+r) shr 1;
        if l < r then
        begin
                t[now].lc := tot+1;
                creat(l,mid);
                t[now].rc := tot+1;
                creat(mid+1,r);
        end;
end;
procedure add(root,l,r,c:longint);
begin
        if t[root].l = t[root].r then
        if t[root].l <= r then
        if t[root].l >= l then
        begin
                t[root].val := t[root].val+c;
                t[root].max := t[root].max+c;
                exit;
        end;
        if t[root].l > r then exit;
        if t[root].r < l then exit;
        add(t[root].lc,l,r,c);
        add(t[root].rc,l,r,c);
        t[root].max := max(t[t[root].lc].max,t[t[root].rc].max);
end;
procedure findmax(root,l,r:longint);
begin
        if (t[root].l >= l) and (t[root].r <= r ) then
        begin
                tmax := max(t[root].max,tmax);
                exit;
        end;
        if t[root].l > r then exit;
        if t[root].r < l then exit;
        findmax(t[root].lc,l,r);
        findmax(t[root].rc,l,r);
end;
begin
        fillchar(t,sizeof(t),0);
        readln(n);
        tot := 0;
        creat(1,n);
        for i := 1 to n do
        begin
                readln(c);
                add(1,i,i,c);
        end;
        readln(m);
        count := 0;
        for i := 1 to m do
        begin
                read(k);
                if k = 1 then
                begin
                        readln(l,r,c);
                        add(1,l,r,c);
                end;
                if k = 2 then
                begin
                        readln(l,r);
                        tmax := 0;
                        findmax(1,l,r);
                        inc(count);
                        write(tmax,' ');
                        if count mod 10000 = 0 then writeln;
                end;
        end;
        writeln;
end.