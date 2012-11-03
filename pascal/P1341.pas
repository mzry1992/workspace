var
        i,j,tn,tm,mv,ans,temp:longint;
        inf:array[1..18,1..3] of longint;
        us:array[1..10] of longint;
procedure dfs(now,sum:longint);
var
        i,j:longint;
        flg:boolean;
begin
        if now > tm then
        begin
                if sum > ans then       ans := sum;
                exit;
        end;
        flg := true;
        for j := inf[now,1]+1 to inf[now,2] do
        if inf[now,3] > us[j] then
        begin
                flg := false;
                break;
        end;
        if flg then
        begin
                for i := inf[now,1]+1 to inf[now,2] do
                        us[i] := us[i]-inf[now,3];
                dfs(now+1,sum+(inf[now,2]-inf[now,1])*inf[now,3]);
                for i := inf[now,1]+1 to inf[now,2] do
                        us[i] := us[i]+inf[now,3];
        end;
        dfs(now+1,sum);
end;
begin
        readln(tn,tm,mv);
        for i := 1 to tm do
                readln(inf[i,1],inf[i,2],inf[i,3]);
        for i := 1 to tn do     us[i] := mv;
        for i := 1 to tm-1 do
        for j := i+1 to tm do
        if inf[i,1] > inf[j,1] then
                begin
                        temp := inf[i,1];       inf[i,1] := inf[j,1];   inf[j,1] := temp;
                        temp := inf[i,2];       inf[i,2] := inf[j,2];   inf[j,2] := temp;
                        temp := inf[i,3];       inf[i,3] := inf[j,3];   inf[j,3] := temp;
                end;
        ans := 0;
        dfs(1,0);
        writeln(ans);
end.