type
        tpoint = record
                val,max,l,r:longint;
        end;
var
        n,m,i,temp,k,l,r,c:longint;
        t:array[1..200001] of tpoint;
function tmax(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
procedure createtree(l,r,root:longint);
var
        mid:longint;
begin
        if l = r then
        begin
                t[root].l := l;
                t[root].r := r;
                exit;
        end;
        mid := (l+r) shr 1;
        t[root].l := l;
        t[root].r := r;
        createtree(l,mid,root*2);
        createtree(mid+1,r,root*2+1);
end;
procedure updata(l,r,root,val,max:longint);
var
        mid:longint;
begin
        if l = r then
        begin
                t[root].val := val;
                t[root].max := max;
                exit;
        end;
        mid := (l+r) shr 1;
        if t[root].max < max then
                t[root].max := max;
        updata(l,mid,root*2,val,max);
        updata(mid+1,r,root*2+1,val,max);
        t[root].max := tmax(t[root].max,t[root*2].max);
        t[root].max := tmax(t[root].max,t[root*2+1].max);
end;
procedure add(l,r,root,c:longint);
begin
        if l = r then
        begin
                t[root].val := t[root].val+c;
                t[root].max := t[root].max+c;
                exit;
        end;
        if t[root].l > r then exit;
        if t[root].r < l then exit;
        add(l,r,root*2,c);
        add(l,r,root*2+1,c);
        t[root].max := tmax(t[root].max,t[root*2].max);
        t[root].max := tmax(t[root].max,t[root*2+1].max);
end;
begin
        readln(n);
        createtree(1,n,1);
        for i := 1 to n do
        begin
                readln(temp);
                updata(i,i,1,temp,temp);
        end;
        readln(m);
        for i := 1 to m do
        begin
                read(k);
                if k = 1 then
                begin
                        readln(l,r,c);
                        add(l,r,1,c);
                end;
        end;
        for i := 1 to 2*n+1 do
                writeln(t[i].l,' ',t[i].r,' ',t[i].val,' ',t[i].max);
end.
