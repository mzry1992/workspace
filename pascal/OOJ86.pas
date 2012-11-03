const
        fin = 'City.Inp';
        fou = 'City.Out';
        maxn = 50;
        maxm = 10;
        maxnum = 1e100;
        bit:array[0..10] of longint = (1,2,4,8,16,32,64,128,256,512,1024);
var
        dis,mp:array[1..maxn,1..maxn] of double;
        n,m,i,j,k:longint;
        mindist:double;
        ax,ay,tx,ty:array[1..maxm] of 1..maxn;
        use:array[1..maxn] of boolean;
procedure       init;
begin
        assign(input,fin);
        assign(output,fou);
        reset(input);
        rewrite(output);
end;
procedure       endd;
begin
        close(input);
        close(output);
        halt;
end;
procedure       dfs(now,lem:longint;dis:double);
var
        i,j,k:longint;
begin
        if lem > m then exit;
        if dis > mindist then exit;
        if now = n then
        begin
                if lem < m then exit;
                if dis > mindist then exit;
                mindist := dis;
                ax := tx;
                ay := ty;
                exit;
        end;
        for i := 2 to n do
        if not use[i] then
        if mp[now,i] <> maxnum then
        begin
                for j := lem to m do
                begin
                        for k := lem+1 to j do
                        begin
                                tx[k] := now;
                                ty[k] := i;
                        end;
                        dfs(i,j,dis+mp[now,i]/bit[j-lem]);
                end;
        end;
end;
begin
        init;
        readln(n,m);
        for i := 1 to n do
        begin
                for j := 1 to n do
                begin
                        read(mp[i,j]);
                        if mp[i,j] = 0 then mp[i,j] := maxnum;
                end;
                readln;
        end;
        dis := mp;
        for k := 1 to n do
        for i := 1 to n do
        for j := 1 to n do
        if dis[i,k] + dis[k,j] < dis[i,j] then dis[i,j] := dis[i,k]+dis[k,j];
        mindist := dis[1,n];
        fillchar(use,sizeof(use),false);
        use[1] := true;
        dfs(1,0,0);
        writeln(mindist:0:2);
        for i := 1 to m do      writeln(ax[i],' ',ay[i]);
        endd;
end.
