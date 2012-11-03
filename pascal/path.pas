program path;
procedure       setinput;
begin
        assign(input,'path.in');
        assign(output,'path.out');
        reset(input);
        rewrite(output);
end;
procedure       setoutput;
begin
        close(input);
        close(output);
end;
var
        n,m,i,j,k,q,u,v,w:longint;
        mp:array[1..50,1..50] of longint;
        f:array[0..50,0..50,0..50] of longint;
        ans:double;
procedure       main;
begin
        readln(n,m);
        fillchar(mp,sizeof(mp),0);
        for i := 1 to m do
        begin
                readln(u,v,w);
                if (mp[u,v] = 0 ) or (mp[u,v] > w) then
                         mp[u,v] := w;
        end;
        for i := 0 to n do
        for j := 0 to n do
        for k := 0 to n do
                f[i,j,k] := -1;
        for i := 0 to n do
                f[0,i,i] := 0;
        for q := 1 to n do
        for k := 1 to n do
        for i := 1 to n do
        for j := 1 to n do
        if (f[q-1,i,k] <> -1) and (mp[k,j] <> 0) then
        if (f[q,i,j] = -1) or (f[q,i,j] > f[q-1,i,k]+mp[k,j]) then
                f[q,i,j] := f[q-1,i,k]+mp[k,j];
        readln(q);
        for i := 1 to q do
        begin
                readln(u,v);
                ans := 1e18;
                for j := 1 to n do
                if f[j,u,v] <> -1 then
                if ans > f[j,u,v]/j then
                        ans := f[j,u,v]/j;
                if ans = 1e18 then      writeln('OMG!')
                else                    writeln(ans:0:3);
        end;
end;
begin
        setinput;
        main;
        setoutput;
end.