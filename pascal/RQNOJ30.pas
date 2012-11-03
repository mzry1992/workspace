var
        n,m,i,x,y:longint;
        a:array[0..1000] of longint;
        tree:array[0..1000,1..2] of longint;
        f:array[0..1000,0..100] of longint;
procedure       addnode(root,node,code:longint);
begin
        if code = 1 then
        begin
                if tree[root,1] = -1 then
                begin
                        tree[root,1] := node;
                        exit;
                end
                else
                begin
                        addnode(tree[root,1],node,2);
                        exit;
                end;
        end
        else
        begin
                if tree[root,2] = -1 then
                begin
                        tree[root,2] := node;
                        exit;
                end
                else
                begin
                        addnode(tree[root,2],node,2);
                        exit;
                end;
        end;
end;
function        max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
function        treedp(root,num:longint):longint;
var
        k:longint;
begin
        if num = 0 then         exit(0);
        if root = -1 then       exit(0);
        if f[root,num] <> -1 then       exit(f[root,num]);
        f[root,num] := treedp(tree[root,2],num);
        for k := 0 to num-1 do
                f[root,num] := max(f[root,num],treedp(tree[root,1],k)+treedp(tree[root,2],num-k-1)+a[root]);
        exit(f[root,num]);
end;
begin
        readln(n,m);
        a[0] := 0;
        for i := 1 to n do      read(a[i]);
        readln;
        for i := 0 to n do
        begin
                tree[i,1] := -1;
                tree[i,2] := -1;
        end;
        for i := 1 to n do
        begin
                readln(x,y);
                addnode(x,y,1);
        end;
        for x := 0 to n do      for y := 0 to m+1 do      f[x,y] := -1;
        writeln(treedp(0,m+1));
end.


