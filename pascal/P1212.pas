var
        map:array[1..1000,1..1000] of boolean;
        cover:array[1..1000] of boolean;
        link:array[1..1000] of integer;
        n,total:integer;

function find(i:integer):boolean;
var
        k,q:integer;
begin
        for k := 1 to n do
        if map[i,k] and not cover[k] then
        begin
                q := link[k];
                link[k] := i;
                cover[k] := true;
                if ( q = 0 ) or find(q) then exit(true);
                link[k] := q;
        end;
        exit(false);
end;

procedure main;
var
        i:integer;
begin
        total := 0;
        for i := 1 to n do
        begin
                fillchar(cover,sizeof(cover),false);
                if find(i) then inc(total);
        end;
end;

function timeallows(x1,y1,x2,y2,v:double;time:integer):boolean;
var
        dis:double;
begin
        dis := sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if dis <= time * v then exit(true);
        exit(false);
end;

procedure Myinit;
var
        i,j,a,r,t:integer;
        x,y:array[1..1000] of double;
        sx,sy,sv:array[1..1000] of double;
begin
        readln(r,a,t);
        n := r;
        for i := 1 to a do      read(x[i],y[i]);
        readln;
        for i := 1 to r do      readln(sx[i],sy[i],sv[i]);
        fillchar(link,sizeof(link),0);
        fillchar(map,sizeof(map),false);
        for i := 1 to r do
        for j := 1 to a do
        if timeallows(sx[i],sy[i],x[j],y[j],sv[j],t) then
                map[i,j] := true;
end;

procedure Myprint;
begin
        writeln(total);
end;

begin
        Myinit;
        main;
        Myprint;
end.

