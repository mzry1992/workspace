var
        n,m,i,j,time:longint;
        mp:array[1..7,1..7] of char;
        vis:array[1..7,1..7] of boolean;
        yes:boolean;

procedure bfs;
var
        d:array[1..2000,1..3] of byte;
        vi:array[1..7,1..7,0..50] of boolean;
        head,tail,now,nx,ny,nd:byte;
begin
        fillchar(vi,sizeof(vi),false);
        head := 1;
        tail := 1;
        d[head,1] := 1;
        d[head,2] := 1;
        d[head,3] := 0;
        while ( head <= tail ) and (d[head,3] <= time) and (not yes) do
        begin
                now := head;
                nx := d[head,1];
                ny := d[head,2];
                nd := d[head,3];
                if (nx+1 >=1) and (nx+1 <= n) then
                if mp[nx+1,ny] <> 'H' then
                if not vi[nx+1,ny,nd+1] then
                begin
                        inc(tail);
                        d[tail,1] := nx+1;
                        d[tail,2] := ny;
                        d[tail,3] := nd+1;
                        vi[nx+1,ny,nd+1] := true;
                        if (nd+1 = time) and (mp[nx+1,ny] = 'D') then
                                yes := true;
                end;
                if (nx-1 >=1) and (nx-1 <= n) then
                if mp[nx-1,ny] <> 'H' then
                if not vi[nx-1,ny,nd+1] then
                begin
                        inc(tail);
                        d[tail,1] := nx-1;
                        d[tail,2] := ny;
                        d[tail,3] := nd+1;
                        vi[nx-1,ny,nd+1] := true;
                        if (nd+1 = time) and (mp[nx-1,ny] = 'D') then
                                yes := true;
                end;
                if (ny+1 >=1) and (ny+1 <= m) then
                if mp[nx,ny+1] <> 'H' then
                if not vi[nx,ny+1,nd+1] then
                begin
                        inc(tail);
                        d[tail,1] := nx;
                        d[tail,2] := ny+1;
                        d[tail,3] := nd+1;
                        vi[nx,ny+1,nd+1] := true;
                        if (nd+1 = time) and (mp[nx,ny+1] = 'D') then
                                yes := true;
                end;
                if (ny-1 >=1) and (ny-1 <= m) then
                if mp[nx,ny-1] <> 'H' then
                if not vi[nx,ny-1,nd+1] then
                begin
                        inc(tail);
                        d[tail,1] := nx;
                        d[tail,2] := ny-1;
                        d[tail,3] := nd+1;
                        vi[nx,ny-1,nd+1] := true;
                        if (nd+1 = time) and (mp[nx,ny-1] = 'D') then
                                yes := true;
                end;
                inc(head);
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
                yes := false;
                bfs;
                if not yes then writeln('No')
                else
                        writeln('Yes');
                readln(n,m,time);
        end;
end.
