var
        mp:array[1..100,0..100] of longint;
        rmp:array[1..100,0..100] of longint;
        path:array[1..100,1..2] of longint;
        f,c:array[1..100,1..100] of longint;
        q:array[1..1000] of longint;
        head,tail,now:longint;
        n,i,j,x,y:longint;
function min(a,b:longint):longint;
begin
        if a < b then exit(a);
        exit(b);
end;
begin
        readln(n);
        fillchar(mp,sizeof(mp),0);
        fillchar(rmp,sizeof(rmp),0);
        for i := 1 to n do
        begin
                for j := 1 to n do
                begin
                        read(c[i,j]);
                        inc(mp[i,0]);
                        mp[i,mp[i,0]] := j;
                        inc(rmp[j,0]);
                        rmp[j,rmp[j,0]] := i;
                end;
                readln;
        end;
        fillchar(f,sizeof(f),0);
        repeat
                fillchar(path,sizeof(path),0);
                path[1,1] := 0;
                path[1,2] := maxlongint;
                head := 1;
                tail := 1;
                q[head] := 1;
                while (( head <= tail ) and (path[n,1] = 0)) do
                begin
                        now := head;
                        inc(head);
                        for i := 1 to mp[now,0] do
                        begin
                                if path[mp[now,i],1] = 0 then
                                if f[now,mp[now,i]] < c[now,mp[now,i]] then
                                begin
                                        inc(tail);
                                        q[tail] := mp[now,i];
                                        path[mp[now,i],1] := now;
                                        path[mp[now,i],2] := min(path[now,2],c[now,mp[now,i]]-f[now,mp[now,i]]);
                                end;
                        end;
                        for i := 1 to rmp[now,0] do
                        begin
                                if path[rmp[now,i],1] = 0 then
                                if f[now,rmp[now,i]] > 0 then
                                begin
                                        inc(tail);
                                        q[tail] := rmp[now,i];
                                        path[rmp[now,i],1] := -now;
                                        path[rmp[now,i],2] := min(path[now,2],f[now,rmp[now,i]]);
                                end;
                        end;
                end;
                        if path[n,1] <> 0 then
                        begin
                                now := n;
                                while now <> 0 do
                                begin
                                        if now > 0 then
                                        begin
                                                f[path[now,1],now] := f[path[now,1],now]+path[n,2];
                                                now := path[now,1];
                                        end
                                        else
                                        if now < 0 then
                                        begin
                                                f[path[-now,1],now] := f[path[-now,1],now]-path[n,2];
                                                now := path[-now,1];
                                        end;
                                end;
                        end;
        until path[n,1] = 0;
        for i := 1 to n do
        begin
                for j := 1 to n do
                        write(f[i,j],' ');
                writeln;
        end;
end.