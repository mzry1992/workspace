var
        n:longint;
        a:array[1..100,1..100] of longint;
procedure outp;
var
        x,y:longint;
begin
        for x := 1 to n do
        begin
                for y := 1 to n do      write(a[x,y]:5);
                writeln;
        end;
end;
procedure dfs(dep,x,y,f:longint);
begin
        a[x,y] := dep;
        outp;
        if f = 1 then
        begin
                if x+1 <= n then
                if a[x+1,y] = 0 then
                        dfs(dep+1,x+1,y,1)
                else
                        dfs(dep+1,x,y-1,2);
        end;
        if f = 2 then
        begin
                if y-1 >= 1 then
                if a[x,y-1] = 0 then
                        dfs(dep+1,x,y-1,2)
                else
                        dfs(dep+1,x-1,y,3);
        end;
        if f = 3 then
        begin
                if x-1 >= 1 then
                if a[x-1,y] = 0 then
                        dfs(dep+1,x-1,y,3)
                else
                        dfs(dep+1,x,y+1,4);
        end;
        if f = 4 then
        begin
                if y+1 <= n then
                if a[x,y+1] = 0 then
                        dfs(dep+1,x,y+1,4)
                else
                        dfs(dep+1,x+1,y,1);
        end;
end;
begin
        fillchar(a,sizeof(a),0);
        write('N=');
        readln(n);
        dfs(1,1,n,1);
end.