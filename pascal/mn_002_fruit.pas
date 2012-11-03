uses    sysutils;
var
        flog:text;
        time1,time2:double;
        n,i,t,tot,ans:longint;
        a:array[1..20002] of longint;
procedure       setinput;
begin
        assign(input,'fruit.in');
        assign(output,'fruit.out');
        assign(flog,'fruit.log');
        append(flog);
        reset(input);
        rewrite(output);
        time1 := now;
end;
procedure       setoutput;
begin
        time2 := now;
        writeln(flog,(time2-time1)*24*3600:0:10);
        close(flog);
        close(input);
        close(output);
end;
procedure       swap(var a,b:longint);
var
        t:longint;
begin
        t := a;
        a := b;
        b := t;
end;
procedure       sift_up(root:longint);
var
        done:boolean;
begin
        done := false;
        if root <> 1 then
        while ( not done ) and ( root <> 1) do
        begin
                if a[root] < a[root div 2] then swap(a[root],a[root div 2])
                else    done := true;
                root := root div 2;
        end;
end;
procedure       sift_down(root:longint);
var
        done:boolean;
begin
        done := false;
        if root*2 <= tot then
        while (not done) and (root*2 <= tot) do
        begin
                root := root*2;
                if (root+1 <= tot) and (a[root+1] < a[root]) then inc(root);
                if a[root div 2] > a[root] then swap(a[root],a[root div 2])
                else    done := true;
        end;
end;
procedure       insert(value:longint);
begin
        inc(tot);
        a[tot] := value;
        sift_up(tot);
end;
procedure       delete(root:longint);
var
        x,y:longint;
begin
        x := a[root];
        y := a[tot];
        dec(tot);
        if (root <= tot) then     a[root] := y;
        if (y >= x) then        sift_down(root)
        else                    sift_up(root);
end;
function        get_min:longint;
var
        temp:longint;
begin
        temp := a[1];
        delete(1);
        exit(temp);
end;
begin
        setinput;
        fillchar(a,sizeof(a),0);
        readln(n);
        tot := 0;
        for i := 1 to n do
        begin
                read(t);
                insert(t);
        end;
        ans := 0;
        for i := 1 to n-1 do
        begin
                t := get_min;
                t := t+get_min;
                ans := ans+t;
                insert(t);
        end;
        writeln(ans);
        setoutput;
end.