var
        l,r,size,num,key:array[1..20000] of longint;
        use:array[1..20000] of boolean;
        tot,totl,n,min,fn,k,opoos,root:longint;
        ch:char;
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
procedure       insert(var      root:longint;k:longint);
begin
        if not use[root] then
        begin
                use[root] := true;
                num[root] := k;
                key[root] := random(19921005);
                size[root] := 1;
                exit;
        end;
        if num[root] <= k then
        begin
                if not use[r[root]] then
                begin
                        inc(tot);
                        r[root] := tot;
                end;
                insert(r[root],k);
                if key[r[root]] < key[root] then        LeftRotate(root);
                size[root] := size[l[root]]+size[r[root]]+1;
        end
        else
        begin
                if not use[l[root]] then
                begin
                        inc(tot);
                        l[root] := tot;
                end;
                insert(l[root],k);
                if key[l[root]] < key[root] then        RightRotate(root);
                size[root] := size[l[root]]+size[r[root]]+1;
        end;
end;
procedure       doI(k:longint);
begin
        if k < min then exit;
        if root = 0 then
        begin
                inc(tot);
                root := tot;
                use[root] := true;
                key[root] := random(19921005);
                size[root] := 1;
                num[root] := k;
                exit;
        end;
        insert(root,k);
end;
procedure       doA(k:longint);
begin
        opoos := opoos+k;
end;
function        find(root,k:longint):longint;
begin
        if num[root] > k then
        if ( num[l[root]] < k ) or ( not use[l[root]] ) then  exit(root);
        if num[root] < k then
        if ( num[r[root]] > k ) or ( not use[r[root]] ) then exit(root);
        if num[root] < k then exit(find(r[root],k));
        if num[root] > k then exit(find(l[root],k));
end;
procedure       doS(k:longint);
var
        t:longint;
begin
        opoos := opoos-k;
        t := find(root,min+opoos);
        writeln(num[t]+opoos);
end;
function        findkth(root,k:longint):longint;
begin
        if size[l[root]] = k-1 then exit(root);
        if size[l[root]] < k-1 then exit(findkth(r[root],k-size[l[root]]-1));
        exit(findkth(l[root],k));
end;
procedure       doF(k:longint);
begin
        if k > tot then writeln('-1')
        else
                writeln(num[findkth(root,tot+1-k)]+opoos);
end;
procedure       Init;
begin
        randomize;
        fillchar(l,sizeof(l),0);
        fillchar(r,sizeof(r),0);
        fillchar(num,sizeof(num),0);
        fillchar(size,sizeof(size),0);
        fillchar(key,sizeof(key),0);
        fillchar(use,sizeof(use),false);
        root := 0;
        tot := 0;
        totl := 0;
        opoos := 0;
end;
begin
        init;
        readln(n,min);
        for fn := 1 to n do
        begin
                readln(ch,k);
                case ch of
                        'I'     :       doI(k-opoos);
                        'A'     :       doA(k);
                        'S'     :       doS(k);
                        'F'     :       doF(k);
                end;
        end;
        writeln(totl);
end.

