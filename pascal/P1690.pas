var
        m,n,i,j,k,t,v:longint;
        p,l,x:array[1..100] of longint;
        dis:array[1..100,1..100] of longint;
        can:array[1..100,1..100] of boolean;
begin
        assign(input,'data.in');
        reset(input);
        assign(output,'data.out');
        rewrite(output);
        readln(m,n);
        fillchar(can,sizeof(can),false);
        for i := 1 to n do
        for j := 1 to n do
                dis[i,j] := 19930713;
        for i := 1 to n do
        begin
                readln(p[i],l[i],x[i]);
                dis[i,i] := 0;
                can[i,i] := true;
                for j := 1 to x[i] do
                begin
                        readln(t,v);
                        dis[i,t] := v;
                        can[i,t] := true;
                end;
        end;
        for k := 1 to n do
        for i := 1 to n do
        for j := 1 to n do
        if can[i,k] and can[k,j] then
        if abs(l[i]-l[j]) <= m then
        if abs(l[i]-l[k]) <= m then
        if abs(l[j]-l[k]) <= m then
                can[i,j] := true
        else
                can[i,j] := false;
        for k := 1 to n do
        for i := 1 to n do
        for j := 1 to n do
        if can[i,k] and can[k,j] and can[i,j] then
        if dis[i,j] > dis[i,k]+dis[k,j] then
                dis[i,j] := dis[i,k]+dis[k,j];
        k := maxlongint;
        for i := 1 to n do
        if can[1,i] then
        if dis[1,i] + p[i] < k then
                k := dis[1,i]+p[i];
        writeln(k);
        close(input);
        close(output);
end.
