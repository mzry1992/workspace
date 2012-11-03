type
        treenode = record
                val,max,a,b,left,right:longint;
        end;
var
        tree:array[1..200000] of treenode;
        n,m,k,l,r,c,i,tot,temp,kmax,count:longint;
procedure maketree(l,r:longint);
var
        now:longint;
begin
        inc(tot);
        now := tot;
        tree[now].a := l;
        tree[now].b := r;
        if l <> r then
        begin
                tree[now].left := tot+1;
                maketree(l,(l+r) shr 1);
                tree[now].right := tot+1;
                maketree((l+r) shr 1 +1,r);
        end;
end;
procedure insert(pos,val,now:longint);
begin
        if tree[now].max < val then
                tree[now].max := val;
        if tree[now].a = tree[now].b then
        begin
                tree[now].val := val;
                exit;
        end;
        if pos > (tree[now].a+tree[now].b) shr 1 then
                insert(pos,val,tree[now].right)
        else
                insert(pos,val,tree[now].left);
end;
procedure updata(l,r,c,now:longint);
var
        mid:longint;
begin
        if tree[now].a = tree[now].b then
        begin
                tree[now].val := tree[now].val+c;
                tree[now].max := tree[now].val;
                exit;
        end;
        mid := (tree[now].a+tree[now].b) shr 1;
        if r < tree[now].a then exit;
        if l > tree[now].b then exit;
        if l <= mid then         updata(l,r,c,tree[now].left);
        if r >= mid+1 then        updata(l,r,c,tree[now].right);
        if tree[now].max < tree[tree[now].right].max then
                tree[now].max  := tree[tree[now].right].max;
        if tree[now].max < tree[tree[now].left].max then
                tree[now].max  := tree[tree[now].left].max;
end;
procedure findmax(l,r,now:longint);
var
        mid:longint;
begin
        if tree[now].a = tree[now].b then
        begin
                if kmax < tree[now].val then
                        kmax := tree[now].val;
                exit;
        end;
        mid := (tree[now].a+tree[now].b) shr 1;
        if r < tree[now].a then exit;
        if l > tree[now].b then exit;
        if (l <= tree[now].a) and (r >= tree[now].b) then
                if kmax < tree[now].max then
                        kmax := tree[now].max;
        if l <= mid then        findmax(l,r,tree[now].left);
        if r >= mid+1 then        findmax(l,r,tree[now].right);
end;
begin
        count := 0;
        readln(n);
        tot := 0;
        maketree(1,n);
        for i := 1 to n do
        begin
                readln(temp);
                insert(i,temp,1);
        end;
        readln(m);
        for i := 1 to m do
        begin
                read(k);
                if k = 1 then
                begin
                        readln(l,r,c);
                        updata(l,r,c,1);
                end;
                if k = 2 then
                begin
                        readln(l,r);
                        kmax := 0;
                        findmax(l,r,1);
                        inc(count);
                        write(kmax,' ');
                        if count mod 10000 = 0 then writeln;
                end;
        end;
end.