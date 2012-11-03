var
        n,m,i,j,time:longint;
        mp:array[1..7,1..7] of char;
        vis:array[1..7,1..7] of boolean;
        vi:array[1..7,1..7,0..50] of boolean;
        yes:boolean;

procedure dfs(x,y,dep:byte);
begin
        if vi[x,y,dep] then exit
        else
                vi[x,y,dep] := true;
        if yes then exit;
        if mp[x,y] = 'H' then exit;
        if mp[x,y] = 'D' then
                if dep = time then
                begin
                        yes := true;
                        exit;
                end;
        if dep >= time then exit;
        if (x+1 >=1) and (x+1 <= n) then
        if not vis[x+1,y] then
        begin
                vis[x+1,y] := true;
                dfs(x+1,y,dep+1);
                vis[x+1,y] := false;
        end;
        if (x-1 >=1) and (x-1 <= n) then
        if not vis[x-1,y] then
        begin
                vis[x-1,y] := true;
                dfs(x-1,y,dep+1);
                vis[x-1,y] := false;
        end;
        if (y+1 >=1) and (y+1 <= m) then
        if not vis[x,y+1] then
        begin
                vis[x,y+1] := true;
                dfs(x,y+1,dep+1);
                vis[x,y+1] := false;
        end;
        if (y-1 >=1) and (y-1 <= m) then
        if not vis[x,y-1] then
        begin
                vis[x,y-1] := true;
                dfs(x,y-1,dep+1);
                vis[x,y-1] := false;
        end;
end;

begin
        readln(n,m,time);
        while not ((n=0) and (m=0) and (time=0)) do
        begin
                for i := 1 to n do
                begin
                        for j := 1 to m do      read(mp[i,j]);
                        readln;
                end;
                fillchar(vis,sizeof(vis),false);
                fillchar(vi,sizeof(vi),false);
                yes := false;
                dfs(1,1,0);
                if not yes then writeln('No')
                else
                        writeln('Yes');
                readln(n,m,time);
        end;
end.
