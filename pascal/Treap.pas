Program         TreapByMyself;
var
        l,r,num,key,size:array[1..20000] of longint;
        tot,k,n,fn,root:longint;
        order:char;
procedure       Init;
begin
        fillchar(l,sizeof(l),0);
        fillchar(r,sizeof(r),0);
        fillchar(num,sizeof(num),0);
        fillchar(key,sizeof(key),0);
        fillchar(size,sizeof(size),0);
        tot := 0;
        root := 0;
        randomize;
end;
procedure       LeftRotate(var  root:longint);
var
        t:longint;
begin
        t := r[root];
        r[root] := l[t];
        if t <> 0 then
                l[t] := root;
        size[root] := size[l[root]]+size[r[root]]+1;
        if t <> 0 then
        size[t] := size[l[t]]+size[r[t]]+1;
        root := t;
end;
procedure       RightRotate(var root:longint);
var
        t:longint;
begin
        t := l[root];
        l[root] := r[t];
        if t <> 0 then
                r[t] := root;
        size[root] := size[l[root]]+size[r[root]]+1;
        if t <> 0 then
        size[t] := size[l[t]]+size[r[t]]+1;
        root := t;
end;
procedure       insert(var root:longint;k:longint);
begin
        if num[root] = 0 then
        begin
                num[root] := k;
                key[root] := random(19921005);
                size[root] := 1;
                exit;
        end;
        if num[root] >= k then
        begin
                if l[root] = 0 then
                begin
                        inc(tot);
                        l[root] := tot;
                end;
                insert(l[root],k);
                if key[l[root]] < key[root] then        RightRotate(root);
                size[root] := size[l[root]]+size[r[root]]+1;
        end
        else
        begin
                if r[root] = 0 then
                begin
                        inc(tot);
                        r[root] := tot;
                end;
                insert(r[root],k);
                if key[r[root]] < key[root] then        LeftRotate(root);
                size[root] := size[l[root]]+size[r[root]]+1;
        end;
end;
procedure       doI(k:longint);
begin
        if root = 0 then
        begin
                inc(tot);
                root := tot;
                key[root] := random(19921005);
                num[root] := k;
                exit;
        end;
        insert(root,k);
end;
procedure       doD(k:longint);
begin
end;
function        findkth(root,k:longint):longint;
begin
        if size[l[root]] = k-1 then     exit(root);
        if size[l[root]] < k-1 then     exit(findkth(r[root],k-size[l[root]]-1));
        exit(findkth(l[root],k));
end;
procedure       doF(k:longint);
begin
        writeln(num[findkth(root,k)]);
end;
begin
        readln(n);
        for fn := 1 to n do
        begin
                readln(order,k);
                case    order   of
                        'I'     :       doI(k);
                        'D'     :       doD(k);
                        'F'     :       doF(k);
                end;
        end;
end.
