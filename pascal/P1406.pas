const
        step:array[1..4,1..2] of longint = ((1,0),(-1,0),(0,1),(0,-1));
var
        m,n,x,y,top,s,t,k:longint;
        a:array[0..500,1..500] of char;
        g:array[1..500,1..500] of longint;
        f:array[0..500,1..500] of longint;
        visit:array[0..500,1..500] of boolean;

procedure fill(x,y,top:longint);
var
        i,xx,yy:longint;
begin
        f[x,y] := top;
        for i := 1 to 4 do
        begin
                xx := x+step[i,1];
                yy := y+step[i,2];
                if (( xx >= 0 ) and ( xx <= m+1 )) then
                if (( yy > 0 ) and ( yy <= n )) then
                if a[xx,yy] = a[x,y] then
                if f[xx,yy] = 0 then
                        fill(xx,yy,top);
        end;
end;

procedure makeg(x,y:longint);
var
        i,xx,yy:longint;
begin
        visit[x,y] := true;
        for i := 1 to 4 do
        begin
                xx := x+step[i,1];
                yy := y+step[i,2];
                if (( xx >= 0 ) and ( XX <= m+1 )) then
                if (( yy > 0 ) and ( yy <= n )) then
                if f[xx,yy] = f[x,y] then
                begin
                if not visit[xx,yy] then
                        makeg(xx,yy);
                end
                else
                begin
                        g[f[x,y],f[xx,yy]] := 1;
                        g[f[xx,yy],f[x,y]] := 1;
                end;
        end;
end;

begin
        readln(m,n);
        for x := 1 to n do begin a[0,x] := '@'; a[m+1,x] := '%'; end;
        for x := 1 to m do
        begin
                for y := 1 to n do read(a[x,y]);
                readln;
        end;
        top:=0;
        fillchar(f,sizeof(f),0);
        for x := 0 to m+1 do
        for y := 1 to n do
        if f[x,y] = 0 then
        begin
                inc(top);
                fill(x,y,top);
        end;
        fillchar(g,sizeof(g),0);
        fillchar(visit,sizeof(visit),false);
        for x := 0 to m+1 do
        for y := 1 to n do
        if not visit[x,y] then
                makeg(x,y);
        s:=1;   t:=top;
        for k := s to t do
        for x := s to t do
        for y := s to t do
        if g[x,k] <> 0 then
        if g[k,y] <> 0 then
        if ( g[x,y] > g[x,k] + g[y,k] ) or ( g[x,y] = 0 ) then
                g[x,y] := g[x,k] + g[y,k];
        writeln(g[s,t]-1);
end.