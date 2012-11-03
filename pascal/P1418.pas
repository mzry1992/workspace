var
        n,m,i,t:longint;
        tree:array[1..1024,1..2] of longint;
        c,e:array[0..1024] of longint;
        f:array[0..1024,0..109] of longint;
        vv:array[0..1024,0..109] of boolean;
function        max(a,b:longint):longint;
begin
        if a > b then   exit(a);
        exit(b);
end;
procedure       dp(root,mon:longint);
var
        i:longint;
begin
        if root = 0 then exit;
        if vv[root,mon] then exit;
        f[root,mon] := 0;
        if (mon >= c[root]) and (e[root] > 0) then
        begin
                dp(tree[root,2],mon-c[root]);
                f[root,mon] := f[tree[root,2],mon-c[root]]+e[root];
        end;
        for i := 0 to mon do
        begin
                dp(tree[root,1],i);
                dp(tree[root,2],mon-i);
                f[root,mon] := max(f[root,mon],f[tree[root,1],i]+f[tree[root,2],mon-i]);
        end;
        vv[root,mon] := true;
end;
procedure       addnode(root,now,mode:longint);
begin
        if mode = 1 then
        begin
                if tree[root,1] = 0 then
                begin
                        tree[root,1] := now;
                        exit;
                end;
                addnode(tree[root,1],now,2);
        end
        else
        begin
                if tree[root,2] = 0 then
                begin
                        tree[root,2] := now;
                        exit;
                end;
                addnode(tree[root,2],now,2);
        end;
end;
begin
        readln(n,m);
        fillchar(tree,sizeof(tree),0);
        for i := 2 to n do
        begin
                read(t);
                addnode(t,i,1);
        end;
        readln;
        for i := 1 to n do      read(c[i]);
        readln;
        for i := 1 to n do      read(e[i]);
        readln;
        fillchar(vv,sizeof(vv),false);
        dp(1,m);
        writeln(f[1,m]);
end.
{
编译通过...
├ 测试数据 01：答案正确... 0ms
├ 测试数据 02：答案正确... 0ms
├ 测试数据 03：答案正确... 0ms
├ 测试数据 04：答案正确... 0ms
├ 测试数据 05：答案正确... 0ms
├ 测试数据 06：答案正确... 56ms
├ 测试数据 07：答案正确... 72ms
├ 测试数据 08：答案正确... 88ms
├ 测试数据 09：答案正确... 103ms
├ 测试数据 10：答案正确... 103ms
-------------------------
Accepted 有效得分：100 有效耗时：422ms

}